
# object files
OBJ := main.c
OBJ += ./cpu/cpu_capability.c
OBJ += ./thread/thread_pool.c


# include files
INCLUDE := -I./ 
INCLUDE += -I./cpu
INCLUDE += -I./thread


# libary files
LIB += -lpthead
#LIB += -L PATH


all: bin

.PHONT:bin
bin:
	gcc $(OBJ) $(LIB) $(INCLUDE) -o wcs_demo -Wall
	
.PHONY:clean
clean:
	rm wcs_demo *.o














