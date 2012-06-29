help:
	@echo "Usage: make {all clean} "
	@echo "!!!!Please correct accordingly compiler and libraries paths, change compiler options,etc.  " 
	@echo " in the "User Specifications region" in file Makefile !!!!"
	@echo

###########################################
# USER SPECIFICATIONS #####################
###########################################

#==============================================
# Specify Compiler
#==============================================
FC = ifort # -lgfortran
#FC=gfortan # -lifcoremt

PFC = mpiifort -f90=$(FC)
## other possibilities (examples)
#PFC  =  mpif90.mpich2 -f90=$(FC)
#PFC  =  mpif90.openmpi # with shell variable "OMPI_FC=$(FC)" 

#==============================================
# Specify OPTIMIZATION flags
#==============================================
FLAGS =-O3  

#==============================================
# Specify PATH to FEAST (main directory)- can be defined as shell variable
#==============================================
#FEASTROOT=/home/polizzi/FEAST/2.0

#==============================================
# Specify libraries path (FEAST+PARDISO+LAPACK+BLAS) 
#==============================================
LOCLIBS = -L/$(FEASTROOT)/lib/x64   

#==============================================================
# Specify all the libraries (feast - pardiso- lapack- blas) mkl==pardiso - lapack -blas  
#==============================================================
LIB=$(LOCLIBS) -lpfeast_sparse -lpfeast -lmkl_intel_lp64  -Wl,--start-group -lmkl_intel_thread -lmkl_core  -Wl,--end-group -liomp5 -lpthread 

###########################################
# END USER SPECIFICATIONS #################
###########################################



#============================================================
# COMPILE and LINK
#============================================================
EXAMPLES = pdriver_feast_sparse 


all: examples 


examples: 
	@for file in $(EXAMPLES); \
	do \
		echo $(PFC)  $(FLAGS) $(INCL) -c $$file.f90 ;\
		$(PFC)  $(FLAGS) $(INCL) -c $$file.f90 ;\
		echo $(PFC)   -o $$file $$file.o $(LIB) ;\
		$(PFC)   -o $$file $$file.o $(LIB) ;\
	done


#==========================================================
# Clean up directory: delete object files and modules
#==========================================================
clean: 
	-@rm  $(EXAMPLES) *.o
