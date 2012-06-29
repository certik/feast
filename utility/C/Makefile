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
CC = gcc #-lifcoremt # -lgfortran

#==============================================
# Specify OPTIMIZATION flags
#==============================================
FLAGS =-O3 

#==============================================
# Specify PATH to FEAST (main directory)- can be defined as shell variable
#==============================================
#FEASTROOT=/home/polizzi/FEAST/2.0

#==============================================
# Specify INCLUDE PATH for C
#==============================================
INCL=-I/$(FEASTROOT)/include

#==============================================
# Specify libraries path (FEAST+PARDISO+LAPACK+BLAS) 
#==============================================
LOCLIBS = -L/$(FEASTROOT)/lib/x64   

#==============================================================
# Specify all the libraries (feast - mkl-pardiso- lapack- blas -lm) mkl==pardiso - lapack -blas  
#==============================================================

LIB=$(LOCLIBS) -lfeast_sparse -lfeast -Wl,--start-group -lmkl_intel_lp64 -lmkl_intel_thread -lmkl_core  -Wl,--end-group -limf -lsvml -lirc -liomp5 -lpthread -lm
###########################################
# END USER SPECIFICATIONS #################
###########################################


#============================================================
# COMPILE and LINK
#============================================================
EXAMPLES = driver_feast_sparse 


all: examples 


examples: 
	@for file in $(EXAMPLES); \
	do \
		echo $(CC)  $(FLAGS) $(INCL) -c $$file.c ;\
		$(CC)  $(FLAGS) $(INCL) -c $$file.c ;\
		echo $(CC)   -o $$file $$file.o $(LIB) ;\
		$(CC)   -o $$file $$file.o $(LIB) ;\
	done


#==========================================================
# Clean up directory: delete object files and modules
#==========================================================
clean: 
	-@rm  $(EXAMPLES) *.o
