INCLUDE_PATH =  -I"$(ISE_LIBRARY)/library/time/spec/include"
SHELL = /bin/sh
CC = gcc
CPP = g++
CFLAGS = -O0 -pipe -fPIC -D_GNU_SOURCE -m64 -DEIF_THREADS -DEIF_LINUXTHREADS  -DWORKBENCH -I"/usr/include/eiffelstudio-19.05" -I. $(INCLUDE_PATH)
CPPFLAGS = -O0 -pipe -fPIC -D_GNU_SOURCE -m64 -DEIF_THREADS -DEIF_LINUXTHREADS  -DWORKBENCH -I"/usr/include/eiffelstudio-19.05" -I. $(INCLUDE_PATH)
LDFLAGS = -m elf_x86_64
CCLDFLAGS = -m64  
LDSHAREDFLAGS =  -m elf_x86_64 -shared -o
EIFLIB = "/usr/lib/eiffelstudio-19.05/libmtwkbench.a"
EIFTEMPLATES = /usr/share/eiffelstudio-19.05/studio/config/unix/templates
LIBS = -lm -lpthread
MAKE = make
AR = ar
LD = ld
MKDEP = \$(EIFFEL_SRC)/C/mkdep $(DPFLAGS) --
MV = /bin/mv
CP = /bin/cp
RANLIB = :
RM = /bin/rm -f
FILE_EXIST = 
RMDIR = 
X2C = "/usr/lib/eiffelstudio-19.05/studio/x2c"
SHAREDLINK = ld
SHAREDLIBS = -lm
SHARED_SUFFIX = .so
COMMAND_MAKEFILE = 
START_TEST = if [ ! -f finished ] ; then 
END_TEST = ; fi 
CREATE_TEST = touch finished 
SYSTEM_IN_DYNAMIC_LIB = database.so 

.SUFFIXES:.cpp .o

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

OBJECTS = big_file_C2_c.o 

OLDOBJECTS =  tr1012.o tr1012d.o tr1017.o tr1017d.o pa1001.o pa1001d.o pa1006.o \
	pa1006d.o pa1008.o pa1008d.o pa1019.o pa1019d.o re1002.o re1002d.o \
	re1004.o re1004d.o re1018.o re1018d.o re1023.o re1023d.o se1003.o \
	se1003d.o se1005.o se1005d.o ba1011.o ba1011d.o ba1016.o ba1016d.o \
	tr1009.o tr1009d.o tr1014.o tr1014d.o tr1024.o tr1024d.o da1000.o \
	da1000d.o da1007.o da1007d.o da1022.o da1022d.o sp1010.o sp1010d.o \
	sp1015.o sp1015d.o tr1013.o tr1013d.o tr1020.o tr1020d.o da996.o \
	da996d.o ti994.o ti994d.o da992.o da992d.o da999.o da999d.o da995.o \
	da995d.o ti993.o ti993d.o da998.o da998d.o da997.o da997d.o in1021.o \
	in1021d.o 

all: Cobj2.o

Cobj2.o: $(OBJECTS) Makefile
	$(LD) $(LDFLAGS) -r -o Cobj2.o $(OBJECTS)
	$(RM) $(OBJECTS)
	$(CREATE_TEST)

clean: local_clean
clobber: local_clobber

local_clean::
	$(RM) core finished *.o

local_clobber:: local_clean
	$(RM) Makefile

