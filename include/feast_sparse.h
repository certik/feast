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


extern void dfeast_scsrgv_(char *UPLO,int *N,double *sa,int *isa,int *jsa,double *sb,int *isb,int *jsb,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info);
extern void dfeast_scsrev_(char *UPLO,int *N,double *sa,int *isa,int *jsa,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info);
extern void zfeast_hcsrgv_(char *UPLO,int *N,double *sa,int *isa,int *jsa,double *sb,int *isb,int *jsb,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info);
extern void zfeast_hcsrev_(char *UPLO,int *N,double *sa,int *isa,int *jsa,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info);
extern void sfeast_scsrgv_(char *UPLO,int *N,float *sa,int *isa,int *jsa,float *sb,int *isb,int *jsb,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info);
extern void sfeast_scsrev_(char *UPLO,int *N,float *sa,int *isa,int *jsa,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info);
extern void cfeast_hcsrgv_(char *UPLO,int *N,float *sa,int *isa,int *jsa,float *sb,int *isb,int *jsb,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info);
extern void cfeast_hcsrev_(char *UPLO,int *N,float *sa,int *isa,int *jsa,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info);



void dfeast_scsrgv(char *UPLO,int *N,double *sa,int *isa,int *jsa,double *sb,int *isb,int *jsb,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  dfeast_scsrgv_(UPLO,N,sa,isa,jsa,sb,isb,jsb,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void dfeast_scsrev(char *UPLO,int *N,double *sa,int *isa,int *jsa,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  dfeast_scsrev_(UPLO,N,sa,isa,jsa,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void zfeast_hcsrgv(char *UPLO,int *N,double *sa,int *isa,int *jsa,double *sb,int *isb,int *jsb,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  zfeast_hcsrgv_(UPLO,N,sa,isa,jsa,sb,isb,jsb,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void zfeast_hcsrev(char *UPLO,int *N,double *sa,int *isa,int *jsa,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  zfeast_hcsrev_(UPLO,N,sa,isa,jsa,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void sfeast_scsrgv(char *UPLO,int *N,float *sa,int *isa,int *jsa,float *sb,int *isb,int *jsb,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  sfeast_scsrgv_(UPLO,N,sa,isa,jsa,sb,isb,jsb,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void sfeast_scsrev(char *UPLO,int *N,float *sa,int *isa,int *jsa,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  sfeast_scsrev_(UPLO,N,sa,isa,jsa,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void cfeast_hcsrgv(char *UPLO,int *N,float *sa,int *isa,int *jsa,float *sb,int *isb,int *jsb,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  cfeast_hcsrgv_(UPLO,N,sa,isa,jsa,sb,isb,jsb,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void cfeast_hcsrev(char *UPLO,int *N,float *sa,int *isa,int *jsa,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  cfeast_hcsrev_(UPLO,N,sa,isa,jsa,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void DFEAST_SCSRGV(char *UPLO,int *N,double *sa,int *isa,int *jsa,double *sb,int *isb,int *jsb,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  dfeast_scsrgv_(UPLO,N,sa,isa,jsa,sb,isb,jsb,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void DFEAST_SCSREV(char *UPLO,int *N,double *sa,int *isa,int *jsa,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  dfeast_scsrev_(UPLO,N,sa,isa,jsa,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void ZFEAST_HCSRGV(char *UPLO,int *N,double *sa,int *isa,int *jsa,double *sb,int *isb,int *jsb,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  zfeast_hcsrgv_(UPLO,N,sa,isa,jsa,sb,isb,jsb,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void ZFEAST_HCSREV(char *UPLO,int *N,double *sa,int *isa,int *jsa,int *feastparam,double *epsout,int *loop,double *Emin,double *Emax,int *M0,double *lambda,double *q,int *mode,double *res,int *info){
  zfeast_hcsrev_(UPLO,N,sa,isa,jsa,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void SFEAST_SCSRGV(char *UPLO,int *N,float *sa,int *isa,int *jsa,float *sb,int *isb,int *jsb,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  sfeast_scsrgv_(UPLO,N,sa,isa,jsa,sb,isb,jsb,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void SFEAST_SCSREV(char *UPLO,int *N,float *sa,int *isa,int *jsa,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  sfeast_scsrev_(UPLO,N,sa,isa,jsa,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void CFEAST_HCSRGV(char *UPLO,int *N,float *sa,int *isa,int *jsa,float *sb,int *isb,int *jsb,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  cfeast_hcsrgv_(UPLO,N,sa,isa,jsa,sb,isb,jsb,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}
void CFEAST_HCSREV(char *UPLO,int *N,float *sa,int *isa,int *jsa,int *feastparam,float *epsout,int *loop,float *Emin,float *Emax,int *M0,float *lambda,float *q,int *mode,float *res,int *info){
  cfeast_hcsrev_(UPLO,N,sa,isa,jsa,feastparam,epsout,loop,Emin,Emax,M0,lambda,q,mode,res,info);
}


