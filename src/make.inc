############################################################################
#  Compilers 
############################################################################ 

#####################################################################
########### Two possible options (choose one)
########### Option 1- (any) Fortran Compiler is used alone
########### Option 2- Intel Fortran + (any) C Compiler to remove the Fortran runtime library dependencies 
#######################################################################

#OPTION = 1
OPTION = 2

##########################################################
########## Select C compiler and flags (mandatory for option #2)
##########################################################
CC     = gcc
CFLAGS = -O3 -fopenmp


##########################################################
########## Select F90 compiler and flags  (Mandatory) 
##########################################################

####### two examples (choose one or create your own)

############ Intel Fortran Compiler (Mandatory for Option # 2 above)
F90 = ifort 
F90FLAGS = -O3 -openmp -fpp   

############ Gnu Fortran Compiler
#F90 = gfortran 
#F90FLAGS = -O3 -m64 -openmp -ffree-line-length-none -ffixed-line-length-none -cpp 


##########################################################
########### For FEAST-MPI (if you wish to compile it) 
########### Select your MPI implementation 
##########################################################

###### (for example: mpiifort, mpif90.mpich2, mpif90.openmpi, etc.)
# Intel MPI
MPI	= mpiifort -f90=$(F90) 
# mpich2
#MPI    = mpif90.mpich2 -f90=$(F90)
# openmpi ...requires shell environment variable "OMPI_FC=$(F90)"
#export OMPI_FC=$(F90) # for BASH shell
#MPI	= mpif90.openmpi 

######### MPI is here associated with the F90 compiler above and compiler directives are activated
######### Do not change the following
PF90 = $(MPI) 
PF90FLAGS = $(F90FLAGS) -DMPI   

