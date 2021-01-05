INCLUDE_PATH =  -I"$(ISE_LIBRARY)/library/encoding/implementation/include" -I"$(ISE_LIBRARY)/library/time/spec/include" -I"$(ISE_LIBRARY)/library/vision2/spec/include" -I"$(ISE_LIBRARY)/library/vision2/implementation/gtk/Clib"  -pthread -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/gio-unix-2.0/ -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libpng16 -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
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
SYSTEM_IN_DYNAMIC_LIB = space_defender_2.so 

.SUFFIXES:.cpp .o

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

OBJECTS = big_file_C2_c.o 

OLDOBJECTS =  et1001.o et1001d.o sp1000.o sp1000d.o sp998.o sp998d.o sp999.o \
	sp999d.o et997.o et997d.o se995.o se995d.o se996.o se996d.o se994.o \
	se994d.o wa993.o wa993d.o st992.o st992d.o ev1018.o ev1018d.o \
	ev1024.o ev1024d.o ev1023.o ev1023d.o ev1022.o ev1022d.o ev1021.o \
	ev1021d.o ev1020.o ev1020d.o ev1019.o ev1019d.o ev1017.o ev1017d.o \
	uc1016.o uc1016d.o kl1015.o kl1015d.o ev1014.o ev1014d.o ev1013.o \
	ev1013d.o kl1012.o kl1012d.o uc1011.o uc1011d.o ev1010.o ev1010d.o \
	ev1009.o ev1009d.o ev1008.o ev1008d.o ev1007.o ev1007d.o ev1006.o \
	ev1006d.o ev1005.o ev1005d.o ev1004.o ev1004d.o ev1003.o ev1003d.o \
	ev1002.o ev1002d.o 

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

