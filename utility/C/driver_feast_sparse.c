/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  !!!!!!! FEAST general Driver sparse !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  !!!!!!! solving Ax=eBx or Ax=eX with A real or complex and B spd !!!!!!!!!
  !!!!!!!                         single or double precision !!!!!!!!!!!!!!!
  !!!!!!! where A and B if any, are provided by user in coordinate format!!!!!!!!!                         
  !!!!!!! by Eric Polizzi- 2009-2011  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <sys/time.h>


#include "feast.h"
#include "feast_sparse.h"

int main(int argc,char *name[200]) {

  //!!!!!!!!!!!!!!!!! Feast declaration variable
  int feastparam[64];
  float sepsout; 
  double  depsout;
  int loop;

  //!!!!!!!!!!!!!!!!! Matrix declaration variable
  FILE *fp;
  char *buff, dum;
  size_t len = 0;
  char str[200],PRE,TYPE,UPLO;
  char str0[]=".in",strA[]=".A",strB[]=".B";
  int N,nnza,nnzb;
  float *ssa,*ssb;
  double *dsa,*dsb;
  float *csa,*csb;
  double *zsa,*zsb;
  int *isa,*jsa,*isb,*jsb;

  //!!!!!!!!!!!!!!!!! Others
  struct timeval t1, t2;
  int i,j,err;
  int M0,M,info;
  double dEmin,dEmax,dtrace;
  float sEmin,sEmax,strace;
  //! eigenvectors
  float *sX;
  double *dX;
  float *cX; 
  double *zX; 
  //! eigenvalue + residual
  float *sE,*sres;
  double *dE,*dres;



  /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!!!!!!!!!!!!!! read main input file !!!!!!!!!!!!!!!
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


  feastinit(feastparam);

  //!!!!!!!!!!!! DRIVER_FEAST_SPARSE input file  
  strcpy(str, name[1]);
  strcat(str, str0);

 
  fp = fopen (str, "r");

  buff = NULL;
  getline(&buff, &len, fp);
  TYPE = buff[0]; //! type of eigenvalue problem
                  // ! g== sparse generalized, s== sparse standard

  buff = NULL;
  getline(&buff, &len, fp);
  PRE = buff[0]; //! "PRE"==(s,d,c,z) resp. (single real,double real,complex,double complex)   

  buff = NULL;
  getline(&buff, &len, fp);
  UPLO = buff[0]; //! UPLO==(F,L,U) reps. (Full csr, Lower csr, Upper csr) 
 

  buff = NULL;
  getline(&buff, &len, fp);
  dEmin = atof(buff);

  buff = NULL;
  getline(&buff, &len, fp);
  dEmax = atof(buff);
  if ((PRE=='s')||(PRE=='c')){
    sEmin=(float) dEmin;
    sEmax=(float) dEmax;
  }

  buff = NULL;
  getline(&buff, &len, fp);
  M0 = atoi(buff); //! size subspace

  buff = NULL;
  getline(&buff, &len, fp);
  dum = buff[0]; //! Some changes from default for feastparam

  buff = NULL;
  getline(&buff, &len, fp);
  feastparam[0] = atoi(buff); //! com

  buff = NULL;
  getline(&buff, &len, fp);
  feastparam[1] = atoi(buff); //! nbe

  buff = NULL;
  getline(&buff, &len, fp); // tol. double or single
  if ((PRE=='s')||(PRE=='c')){
    feastparam[6] = atoi(buff); }
  else
    { feastparam[2] = atoi(buff);}

  buff = NULL;
  getline(&buff, &len, fp);
  feastparam[3] = atoi(buff); //! maxloop

  buff = NULL;
  getline(&buff, &len, fp);
  feastparam[5] = atoi(buff); //! residual


  fclose(fp);


  //!!!!!!!!!!!read matrix A

  strcpy(str, name[1]);
  strcat(str, strA);
  fp = fopen (str, "r");
  err=fscanf(fp,"%d%d%d\n",&N,&N,&nnza);
  isa=calloc(N+1,sizeof(int));
  for (i=0;i<=N;i++){*(isa+i)=0;}
  *(isa)=1;
  jsa=calloc(nnza,sizeof(int));
  if (PRE=='s'){
    ssa=calloc(nnza,sizeof(float));
    for (i=0;i<nnza;i++){
      err=fscanf(fp,"%d%d%f\n",&j,jsa+i,ssa+i);
      *(isa+j)=*(isa+j)+1;}
  }

  else if (PRE=='d'){
    dsa=calloc(nnza,sizeof(double));
    for (i=0;i<nnza;i++){
      err=fscanf(fp,"%d%d%lf\n",&j,jsa+i,dsa+i);
      *(isa+j)=*(isa+j)+1;}
  }
  else if (PRE=='c'){
    csa=calloc(2*nnza,sizeof(float));
    for (i=0;i<nnza;i++){
      err=fscanf(fp,"%d%d%f%f\n",&j,jsa+i,csa+2*i,csa+2*i+1);
      *(isa+j)=*(isa+j)+1;}
  }
  else if (PRE=='z'){
    zsa=calloc(2*nnza,sizeof(double));
    for (i=0;i<nnza;i++){
      err=fscanf(fp,"%d%d%lf%lf\n",&j,jsa+i,zsa+2*i,zsa+2*i+1);
      *(isa+j)=*(isa+j)+1;}
  }

  fclose(fp);

  for(i=1;i<=N;i++){*(isa+i)=*(isa+i)+*(isa+i-1);}
  



  //!!!!!!!!!!!read matrix B if any

  if (TYPE=='g'){
    strcpy(str, name[1]);
    strcat(str, strB);
    fp = fopen (str, "r");
    err=fscanf(fp,"%d%d%d\n",&N,&N,&nnzb);
    isb=calloc(N+1,sizeof(int));
    for (i=0;i<=N;i++){*(isb+i)=0;}
    *(isb)=1;
    jsb=calloc(nnzb,sizeof(int));

    if (PRE=='s'){
      ssb=calloc(nnzb,sizeof(float));
      for (i=0;i<nnzb;i++){
	err=fscanf(fp,"%d%d%f\n",&j,jsb+i,ssb+i);
	*(isb+j)=*(isb+j)+1;}
    }
    else if (PRE=='d'){
      dsb=calloc(nnzb,sizeof(double));
      for (i=0;i<nnzb;i++){
	err=fscanf(fp,"%d%d%lf\n",&j,jsb+i,dsb+i);
	*(isb+j)=*(isb+j)+1;}
    }
    else if (PRE=='c'){
      csb=calloc(2*nnzb,sizeof(float));
      for (i=0;i<nnzb;i++){
	err=fscanf(fp,"%d%d%f%f\n",&j,jsb+i,csb+2*i,csb+2*i+1);
	*(isb+j)=*(isb+j)+1;}
    }
    else if (PRE=='z'){
      zsb=calloc(2*nnzb,sizeof(double));
      for (i=0;i<nnzb;i++){
	err=fscanf(fp,"%d%d%lf%lf\n",&j,jsb+i,zsb+2*i,zsb+2*i+1);
	*(isb+j)=*(isb+j)+1;}
    }
    fclose(fp);
    for(i=1;i<=N;i++){*(isb+i)=*(isb+i)+*(isb+i-1);}
  }

  /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!!!!!!!!!!!!!!!!!!!!! INFORMATION ABOUT MATRIX !!!!!!!!!!!!!!!
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
  printf("sparse  -csrfile- size %.d\n",N);
  printf("sparse matrix A nnza %d \n",nnza);
  if (TYPE=='g') {printf("sparse matrix B nnzb %d \n",nnzb);}

  gettimeofday(&t1,NULL);

  /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!!!!!!!!!!!!!!!!!! FEAST  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

 
  if ((PRE=='s')&&(TYPE=='s')){// case("ssst")
    sE=calloc(M0,sizeof(float));  // eigenvalues
    sres=calloc(M0,sizeof(float));// residual 
    sX=calloc(N*M0,sizeof(float)); // eigenvectors
    sfeast_scsrev(&UPLO,&N,ssa,isa,jsa,feastparam,&sepsout,&loop,&sEmin,&sEmax,&M0,sE,sX,&M,sres,&info);
  }
  if ((PRE=='s')&&(TYPE=='g')){// case("ssge")
    sE=calloc(M0,sizeof(float));  // eigenvalues
    sres=calloc(M0,sizeof(float));// residual 
    sX=calloc(N*M0,sizeof(float)); // eigenvectors
    sfeast_scsrgv(&UPLO,&N,ssa,isa,jsa,ssb,isb,jsb,feastparam,&sepsout,&loop,&sEmin,&sEmax,&M0,sE,sX,&M,sres,&info);
  } 

  if ((PRE=='d')&&(TYPE=='s')){// case("dsst")
    dE=calloc(M0,sizeof(double));  // eigenvalues
    dres=calloc(M0,sizeof(double));// residual 
    dX=calloc(N*M0,sizeof(double)); // eigenvectors
    dfeast_scsrev(&UPLO,&N,dsa,isa,jsa,feastparam,&depsout,&loop,&dEmin,&dEmax,&M0,dE,dX,&M,dres,&info);
  }
  if ((PRE=='d')&&(TYPE=='g')){// case("dsge")
    dE=calloc(M0,sizeof(double));  // eigenvalues
    dres=calloc(M0,sizeof(double));// residual 
    dX=calloc(N*M0,sizeof(double)); // eigenvectors
    dfeast_scsrgv(&UPLO,&N,dsa,isa,jsa,dsb,isb,jsb,feastparam,&depsout,&loop,&dEmin,&dEmax,&M0,dE,dX,&M,dres,&info);
  }

  if ((PRE=='c')&&(TYPE=='s')){// case("csst")
    sE=calloc(M0,sizeof(float));  // eigenvalues
    sres=calloc(M0,sizeof(float));// residual 
    cX=calloc(2*N*M0,sizeof(float)); // eigenvectors
    cfeast_hcsrev(&UPLO,&N,csa,isa,jsa,feastparam,&sepsout,&loop,&sEmin,&sEmax,&M0,sE,cX,&M,sres,&info);
  }
  if ((PRE=='c')&&(TYPE=='g')){// case("csge")
    sE=calloc(M0,sizeof(float));  // eigenvalues
    sres=calloc(M0,sizeof(float));// residual 
    cX=calloc(N*M0,sizeof(float)); // eigenvectors
    cfeast_hcsrgv(&UPLO,&N,csa,isa,jsa,csb,isb,jsb,feastparam,&sepsout,&loop,&sEmin,&sEmax,&M0,sE,cX,&M,sres,&info);
  }

  if ((PRE=='z')&&(TYPE=='s')){// case("dsst")
    dE=calloc(M0,sizeof(double));  // eigenvalues
    dres=calloc(M0,sizeof(double));// residual 
    zX=calloc(2*N*M0,sizeof(double)); // eigenvectors
    zfeast_hcsrev(&UPLO,&N,zsa,isa,jsa,feastparam,&depsout,&loop,&dEmin,&dEmax,&M0,dE,zX,&M,dres,&info);
  }
  if ((PRE=='z')&&(TYPE=='g')){// case("dsge")
    dE=calloc(M0,sizeof(double));  // eigenvalues
    dres=calloc(M0,sizeof(double));// residual 
    zX=calloc(2*N*M0,sizeof(double)); // eigenvectors
    zfeast_hcsrgv(&UPLO,&N,zsa,isa,jsa,zsb,isb,jsb,feastparam,&depsout,&loop,&dEmin,&dEmax,&M0,dE,zX,&M,dres,&info);
  }


  gettimeofday(&t2,NULL);
  /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!!!!!!!! POST-PROCESSING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
  printf("FEAST OUTPUT INFO %d\n",info);
  if (info==0) {
    printf("*************************************************\n");
    printf("************** REPORT ***************************\n");
    printf("*************************************************\n");
    printf("SIMULATION TIME %f\n",(t2.tv_sec-t1.tv_sec)*1.0+(t2.tv_usec-t1.tv_usec)*0.000001);
    if ((PRE=='s')||(PRE=='c')){
      printf("# Search interval [Emin,Emax] %.15e %.15e\n",sEmin,sEmax);}
    else
      {
	printf("# Search interval [Emin,Emax] %.15e %.15e\n",dEmin,dEmax);}
    printf("# mode found/subspace %d %d \n",M,M0);
    printf("# iterations %d \n",loop);
    if ((PRE=='s')||(PRE=='c')){
      strace=(float) 0.0;
      for (i=0;i<=M-1;i=i+1){
	strace=strace+*(sE+i);
      }	  
      printf("TRACE %.6f\n", strace);
      printf("Relative error on the Trace %.6f\n",sepsout );
      printf("Eigenvalues/Residuals\n");
      for (i=0;i<=M-1;i=i+1){
	printf("   %d %.6f %.6f\n",i,*(sE+i),*(sres+i));
      }
    }
    else
      {dtrace=(double) 0.0;
	for (i=0;i<=M-1;i=i+1){
	  dtrace=dtrace+*(dE+i);
	}	  
	printf("TRACE %.15e\n", dtrace);
	printf("Relative error on the Trace %.15e\n",depsout );
	printf("Eigenvalues/Residuals\n");
	for (i=0;i<=M-1;i=i+1){
	  printf("   %d %.15e %.15e\n",i,*(dE+i),*(dres+i));
	}
      }
  }
  return 0;
}
