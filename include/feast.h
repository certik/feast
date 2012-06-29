/*
!=========================================================================================
!Copyright (c) 2009-2011, The Regents of the University of Massachusetts, Amherst.
!Developed by E. Polizzi
!All rights reserved.
!
!Redistribution and use in source and binary forms, with or without modification, 
!are permitted provided that the following conditions are met:
!
!1. Redistributions of source code must retain the above copyright notice, this list of conditions 
!   and the following disclaimer.
!2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions 
!   and the following disclaimer in the documentation and/or other materials provided with the distribution.
!3. Neither the name of the University nor the names of its contributors may be used to endorse or promote
!    products derived from this software without specific prior written permission.
!
!THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
!BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
!ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
!EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
!SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
!LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
!IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
!==========================================================================================
*/




extern void feastinit_(int *feastparam);
extern void dfeast_srci_(char *ijob,int *N,double *Ze,double *work,double   *workc,double   *Aq,double   *Sq,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info);
extern void zfeast_hrci_(char *ijob,int *N,double   *Ze,double   *work,double   *workc,double   *zAq,double   *zSq,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double   *q,int *mode,double *res,int *info);
extern void sfeast_srci_(char *ijob,int *N,float *Ze,float *work,float   *workc,float   *Aq,float   *Sq,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info);
extern void cfeast_hrci_(char *ijob,int *N,float   *Ze,float   *work,float   *workc,float   *zAq,float   *zSq,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float   *q,int *mode,float *res,int *info);
extern void dset_point_gauss_legendre_(int *nbe,int *e,double *xe,double *we);
extern void sset_point_gauss_legendre_(int *nbe,int *e,float *xe,float *we);


void feastinit(int *feastparam) {
     feastinit_(feastparam);
}
void FEASTINIT(int *feastparam) {
     feastinit_(feastparam);
}
void dfeast_srci(char *ijob,int *N,double   *Ze,double *work,double   *workc,double   *Aq,double   *Sq,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
     dfeast_srci_(ijob,N,Ze,work,workc,Aq,Sq,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void zfeast_hrci(char *ijob,int *N,double   *Ze,double   *work,double   *workc,double   *zAq,double   *zSq,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double   *q,int *mode,double *res,int *info){
    zfeast_hrci_(ijob,N,Ze,work,workc,zAq,zSq,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void sfeast_srci(char *ijob,int *N,float   *Ze,float *work,float   *workc,float   *Aq,float   *Sq,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
     sfeast_srci_(ijob,N,Ze,work,workc,Aq,Sq,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void cfeast_hrci(char *ijob,int *N,float   *Ze,float   *work,float   *workc,float   *zAq,float   *zSq,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float   *q,int *mode,float *res,int *info){
    cfeast_hrci_(ijob,N,Ze,work,workc,zAq,zSq,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void DFEAST_SRCI(char *ijob,int *N,double   *Ze,double *work,double   *workc,double   *Aq,double   *Sq,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
     dfeast_srci_(ijob,N,Ze,work,workc,Aq,Sq,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void ZFEAST_HRCI(char *ijob,int *N,double   *Ze,double   *work,double   *workc,double   *zAq,double   *zSq,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double   *q,int *mode,double *res,int *info){
    zfeast_hrci_(ijob,N,Ze,work,workc,zAq,zSq,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void SFEAST_SRCI(char *ijob,int *N,float   *Ze,float *work,float   *workc,float   *Aq,float   *Sq,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
     sfeast_srci_(ijob,N,Ze,work,workc,Aq,Sq,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void CFEAST_HRCI(char *ijob,int *N,float   *Ze,float   *work,float   *workc,float   *zAq,float   *zSq,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float   *q,int *mode,float *res,int *info){
    cfeast_hrci_(ijob,N,Ze,work,workc,zAq,zSq,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}


//////////// others
void dset_point_gauss_legendre(int *nbe,int *e,double *xe,double *we){
 dset_point_gauss_legendre_(nbe,e,xe,we)
  ;}
void sset_point_gauss_legendre(int *nbe,int *e,float *xe,float *we){
 sset_point_gauss_legendre_(nbe,e,xe,we)
  ;}
void DSET_POINT_GAUSS_LEGENDRE(int *nbe,int *e,double *xe,double *we){
 dset_point_gauss_legendre_(nbe,e,xe,we)
  ;}
void SSET_POINT_GAUSS_LEGENDRE(int *nbe,int *e,float *xe,float *we){
 sset_point_gauss_legendre_(nbe,e,xe,we)
  ;}
