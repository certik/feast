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


extern void dfeast_sbgv_(char *UPLO,int *N,int *kla,double *A,int *LDA,int *klb,double *B,int *LDB,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info);
extern void dfeast_sbev_(char *UPLO,int *N,int *kla,double *A,int *LDA,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info);
extern void zfeast_hbgv_(char *UPLO,int *N,int *kla,double *A,int *LDA,int *klb,double *B,int *LDB,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info);
extern void zfeast_hbev_(char *UPLO,int *N,int *kla,double *A,int *LDA,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info);
extern void sfeast_sbgv_(char *UPLO,int *N,int *kla,float *A,int *LDA,int *klb,float *B,int *LDB,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info);
extern void sfeast_sbev_(char *UPLO,int *N,int *kla,float *A,int *LDA,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info);
extern void cfeast_hbgv_(char *UPLO,int *N,int *kla,float *A,int *LDA,int *klb,float *B,int *LDB,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info);
extern void cfeast_hbev_(char *UPLO,int *N,int *kla,float *A,int *LDA,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info);



void dfeast_sbgv(char *UPLO,int *N,int *kla,double *A,int *LDA,int *klb,double *B,int *LDB,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  dfeast_sbgv_(UPLO,N,kla,A,LDA,klb,B,LDB,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void dfeast_sbev(char *UPLO,int *N,int *kla,double *A,int *LDA,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  dfeast_sbev_(UPLO,N,kla,A,LDA,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}

void zfeast_hbgv(char *UPLO,int *N,int *kla,double *A,int *LDA,int *klb,double *B,int *LDB,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  zfeast_hbgv_(UPLO,N,kla,A,LDA,klb,B,LDB,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}

void zfeast_hbev(char *UPLO,int *N,int *kla,double *A,int *LDA,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  zfeast_hbev_(UPLO,N,kla,A,LDA,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void sfeast_sbgv(char *UPLO,int *N,int *kla,float *A,int *LDA,int *klb,float *B,int *LDB,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  sfeast_sbgv_(UPLO,N,kla,A,LDA,klb,B,LDB,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void sfeast_sbev(char *UPLO,int *N,int *kla,float *A,int *LDA,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  sfeast_sbev_(UPLO,N,kla,A,LDA,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void cfeast_hbgv(char *UPLO,int *N,int *kla,float *A,int *LDA,int *klb,float *B,int *LDB,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  cfeast_hbgv_(UPLO,N,kla,A,LDA,klb,B,LDB,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void cfeast_hbev(char *UPLO,int *N,int *kla,float *A,int *LDA,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  cfeast_hbev_(UPLO,N,kla,A,LDA,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void DFEAST_SBGV(char *UPLO,int *N,int *kla,double *A,int *LDA,int *klb,double *B,int *LDB,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  dfeast_sbgv_(UPLO,N,kla,A,LDA,klb,B,LDB,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void DFEAST_SBEV(char *UPLO,int *N,int *kla,double *A,int *LDA,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  dfeast_sbev_(UPLO,N,kla,A,LDA,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void ZFEAST_HBGV(char *UPLO,int *N,int *kla,double *A,int *LDA,int *klb,double *B,int *LDB,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  zfeast_hbgv_(UPLO,N,kla,A,LDA,klb,B,LDB,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void ZFEAST_HBEV(char *UPLO,int *N,int *kla,double *A,int *LDA,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  zfeast_hbev_(UPLO,N,kla,A,LDA,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void SFEAST_SBGV(char *UPLO,int *N,int *kla,float *A,int *LDA,int *klb,float *B,int *LDB,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  sfeast_sbgv_(UPLO,N,kla,A,LDA,klb,B,LDB,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void SFEAST_SBEV(char *UPLO,int *N,int *kla,float *A,int *LDA,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  sfeast_sbev_(UPLO,N,kla,A,LDA,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void CFEAST_HBGV(char *UPLO,int *N,int *kla,float *A,int *LDA,int *klb,float *B,int *LDB,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  cfeast_hbgv_(UPLO,N,kla,A,LDA,klb,B,LDB,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void CFEAST_HBEV(char *UPLO,int *N,int *kla,float *A,int *LDA,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  cfeast_hbev_(UPLO,N,kla,A,LDA,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
