!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!! FEAST general Driver sparse !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!! solving Ax=eBx or Ax=eX with A real or complex and B spd !!!!!!!!!
!!!!!!!                         single or double precision !!!!!!!!!!!!!!!
!!!!!!! where A and B if any, are provided by user in coordinate format !!                         
!!!!!!! by Eric Polizzi- 2009-2011  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
program driver_feast_sparse

  implicit none

!!!!!!!!!!!!!!!!! Feast declaration variable
  integer,dimension(64) :: feastparam 
  double precision :: depsout
  real :: sepsout
  integer :: loop

!!!!!!!!!!!!!!!!! Matrix declaration variable
  character(len=100) :: name
  character(len=1) :: UPLO,TYPE,PRE 
  integer :: n,nnza,nnzb
  real,dimension(:),allocatable :: ssa,ssb
  double precision,dimension(:),allocatable :: dsa,dsb
  complex,dimension(:),allocatable :: csa,csb
  complex(kind=kind(1.0d0)),dimension(:),allocatable :: zsa,zsb
  integer,dimension(:),allocatable :: isa,jsa,isb,jsb

!!!!!!!!!!!!!!!!! Others
  integer :: t1,t2,tim
  integer :: i,j
  integer :: M0,M,info
  double precision :: dEmin,dEmax
  real :: sEmin,sEmax
  ! eigenvectors
  real,dimension(:,:),allocatable :: sX
  complex,dimension(:,:),allocatable :: cX
  double precision,dimension(:,:),allocatable :: dX
  complex(kind=kind(1.0d0)),dimension(:,:),allocatable :: zX
  double precision:: drea,dimg
  real :: rea,img
  ! eigenvalue + residual
  double precision,dimension(:),allocatable :: dE,dres
  real,dimension(:),allocatable :: sE,sres 


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!! read main input file !!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  call getarg(1,name)

  call feastinit(feastparam)


!!!!!!!!!!!! DRIVER_FEAST_SPARSE input file  
  open(10,file=trim(name)//'.in',status='old')
  read(10,*) TYPE ! type of eigenvalue problem
  ! g== sparse generalized, s== sparse standard
  read(10,*) PRE  ! "PRE"==(s,d,c,z) resp. (single real,double real,complex,double complex) 
  read(10,*) UPLO ! UPLO==(F,L,U) reps. (Full csr, Lower csr, Upper csr) 
  if ((PRE=='d').or.(PRE=='z')) then
     read(10,*) dEmin
     read(10,*) dEmax
  else
     read(10,*) sEmin
     read(10,*) sEmax
  end if
  read(10,*) M0   ! size subspace
  read(10,*) ! Some changes from default for feastparam
  read(10,*) feastparam(1)  !com
  read(10,*) feastparam(2)  !nbe
  !tol single or double
  if ((PRE=='s').or.(PRE=='c')) then
     read(10,*) feastparam(7)
  else
     read(10,*) feastparam(3)
  end if
  read(10,*) feastparam(4)  !maxloop
  read(10,*) feastparam(6)  !residi
  close(10)



!!!!!!!!!!!read matrix A

  open(10,file=trim(name)//'.A',status='old')
  read(10,*) n,n,nnza

  allocate(isa(1:n+1))
  isa=0
  isa(1)=1
  allocate(jsa(1:nnza))

  if (PRE=='s') then
     allocate(ssa(1:nnza))
     do i=1,nnza
        read(10,*) j,jsa(i),ssa(i)
        isa(j+1)=isa(j+1)+1
     end do
  elseif (PRE=='d') then
     allocate(dsa(1:nnza))
     do i=1,nnza
        read(10,*) j,jsa(i),dsa(i)
        isa(j+1)=isa(j+1)+1
     end do
  elseif(PRE=='c') then
     allocate(csa(1:nnza))
     do i=1,nnza
        read(10,*) j,jsa(i),rea,img
        csa(i)=rea*(1.0d0,0.0d0)+img*(0.0d0,1.0d0)
        isa(j+1)=isa(j+1)+1
     end do
  elseif (PRE=='z') then
     allocate(zsa(1:nnza))
     do i=1,nnza
        read(10,*) j,jsa(i),drea,dimg
        zsa(i)=drea*(1.0d0,0.0d0)+dimg*(0.0d0,1.0d0)
        isa(j+1)=isa(j+1)+1
     end do
  end if
  close(10)

  do i=2,n+1
     isa(i)=isa(i)+isa(i-1)
  enddo

!!!!!!!!!!!read matrix B if any
  if (TYPE=='g') then


     open(10,file=trim(name)//'.B',status='old')
     read(10,*) n,n,nnzb
     allocate(isb(1:n+1))
     isb=0
     isb(1)=1
     allocate(jsb(1:nnzb))

     if (PRE=='s') then
        allocate(ssb(1:nnzb))
        do i=1,nnzb
           read(10,*) j,jsb(i),ssb(i)
           isb(j+1)=isb(j+1)+1
        end do
     elseif (PRE=='d') then
        allocate(dsb(1:nnzb))
        do i=1,nnzb
           read(10,*) j,jsb(i),dsb(i)
           isb(j+1)=isb(j+1)+1
        end do
     elseif (PRE=='c') then
        allocate(csb(1:nnza))
        do i=1,nnzb
           read(10,*) j,jsb(i),rea,img
           csb(i)=rea*(1.0d0,0.0d0)+img*(0.0d0,1.0d0)
           isb(j+1)=isb(j+1)+1
        end do
     elseif (PRE=='z') then
        allocate(zsb(1:nnza))
        do i=1,nnzb
           read(10,*) j,jsb(i),drea,dimg
           zsb(i)=drea*(1.0d0,0.0d0)+dimg*(0.0d0,1.0d0)
           isb(j+1)=isb(j+1)+1
        end do
     end if
     close(10)

     do i=2,n+1
        isb(i)=isb(i)+isb(i-1)
     enddo
  end if


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!! INFORMATION ABOUT MATRIX !!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  print *,'matrix -coordinate format- size',n
  print *,'sparse matrix A- nnz',nnza
  if (TYPE=='g') print *,'sparse matrix B- nnz',nnzb

  call system_clock(t1,tim)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!! FEAST  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


!!!!!!!!!!!!!  FEAST

  if ((PRE=='s').and.(TYPE=='g')) then ! case("ssge")
     allocate(sE(1:M0))     ! Eigenvalue
     allocate(sres(1:M0))   ! Residual 
     allocate(sX(1:n,1:M0))
     call sfeast_scsrgv(UPLO,N,ssa,isa,jsa,ssb,isb,jsb,feastparam,sepsout,loop,sEmin,sEmax,M0,sE,sX,M,sres,info)

  elseif ((PRE=='s').and.(TYPE=='s')) then  !case("ssst")
     allocate(sE(1:M0))     ! Eigenvalue
     allocate(sres(1:M0))   ! Residual 
     allocate(sX(1:n,1:M0))
     call sfeast_scsrev(UPLO,N,ssa,isa,jsa,feastparam,sepsout,loop,sEmin,sEmax,M0,sE,sX,M,sres,info)

  elseif ((PRE=='d').and.(TYPE=='g')) then ! case("dsge")
     allocate(dE(1:M0))     ! Eigenvalue
     allocate(dres(1:M0))   ! Residual  
     allocate(dX(1:n,1:M0))
     call dfeast_scsrgv(UPLO,N,dsa,isa,jsa,dsb,isa,jsa,feastparam,depsout,loop,dEmin,dEmax,M0,dE,dX,M,dres,info)

  elseif ((PRE=='d').and.(TYPE=='s')) then! case("dsst")
     allocate(dE(1:M0))     ! Eigenvalue
     allocate(dres(1:M0))   ! Residual 
     allocate(dX(1:n,1:M0))
     call dfeast_scsrev(UPLO,N,dsa,isa,jsa,feastparam,depsout,loop,dEmin,dEmax,M0,dE,dX,M,dres,info)


  elseif ((PRE=='c').and.(TYPE=='g')) then !case("csge")
     allocate(sE(1:M0))     ! Eigenvalue
     allocate(sres(1:M0))   ! Residual 
     allocate(cX(1:n,1:M0))
     call cfeast_hcsrgv(UPLO,N,csa,isa,jsa,csb,isb,jsb,feastparam,sepsout,loop,sEmin,sEmax,M0,sE,cX,M,sres,info)


  elseif ((PRE=='c').and.(TYPE=='s')) then ! case("csst")
     allocate(sE(1:M0))     ! Eigenvalue
     allocate(sres(1:M0))   ! Residual 
     allocate(cX(1:n,1:M0))
     call cfeast_hcsrev(UPLO,N,csa,isa,jsa,feastparam,sepsout,loop,sEmin,sEmax,M0,sE,cX,M,sres,info)


  elseif ((PRE=='z').and.(TYPE=='g')) then ! case("zsge")
     allocate(dE(1:M0))     ! Eigenvalue
     allocate(dres(1:M0))   ! Residual 
     allocate(zX(1:n,1:M0))
     feastparam(4)=1
     call zfeast_hcsrgv(UPLO,N,zsa,isa,jsa,zsb,isb,jsb,feastparam,depsout,loop,dEmin,dEmax,M0,dE,zX,M,dres,info)


  elseif ((PRE=='z').and.(TYPE=='s')) then ! case("zsst")
     allocate(dE(1:M0))     ! Eigenvalue
     allocate(dres(1:M0))   ! Residual 
     allocate(zX(1:n,1:M0))
     call zfeast_hcsrev(UPLO,N,zsa,isa,jsa,feastparam,depsout,loop,dEmin,dEmax,M0,dE,zX,M,dres,info)

  end if



!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!! POST-PROCESSING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  call system_clock(t2,tim)
  print *,'FEAST OUTPUT INFO',info
  if (info==0) then
     print *,'*************************************************'
     print *,'************** REPORT ***************************'
     print *,'*************************************************'
     print *,'SIMULATION TIME',(t2-t1)*1.0d0/tim
     if ((PRE=='s').or.(PRE=='c')) then
        print *,'# Search interval [Emin,Emax]',sEmin,sEmax
     else
        print *,'# Search interval [Emin,Emax]',dEmin,dEmax
     end if
     print *,'# mode found/subspace',M,M0
     print *,'# iterations',loop
     if ((PRE=='s').or.(PRE=='c')) then
        print *,'TRACE',sum(sE(1:M))
        print *,'Relative error on the Trace',sepsout
        if (feastparam(6)==1) then
           print *,'Eigenvalues/Residuals'
           do i=1,M
              print *,i,sE(i),sres(i)
           enddo
        endif
     else
        print *,'TRACE',sum(dE(1:M))
        print *,'Relative error on the Trace',depsout
        if (feastparam(6)==1) then
           print *,'Eigenvalues/Residuals'
           do i=1,M
              print *,i,dE(i),dres(i)
           enddo
        endif
     end if




  endif
end program driver_feast_sparse



