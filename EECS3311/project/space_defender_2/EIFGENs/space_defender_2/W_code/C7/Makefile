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

OBJECTS = big_file_C7_c.o 

OLDOBJECTS =  ro1164.o ro1164d.o et1163.o et1163d.o et1162.o et1162d.o da1166.o \
	da1166d.o ev1158.o ev1158d.o kl1159.o kl1159d.o ev1167.o ev1167d.o \
	ev1185.o ev1185d.o ev1184.o ev1184d.o ev1168.o ev1168d.o ev1183.o \
	ev1183d.o kl1188.o kl1188d.o kl1186.o kl1186d.o ev1182.o ev1182d.o \
	ev1181.o ev1181d.o ev1180.o ev1180d.o ev1179.o ev1179d.o ev1178.o \
	ev1178d.o ev1177.o ev1177d.o ev1176.o ev1176d.o ev1157.o ev1157d.o \
	kl1161.o kl1161d.o ev1165.o ev1165d.o ev1187.o ev1187d.o ev1175.o \
	ev1175d.o ev1174.o ev1174d.o ev1173.o ev1173d.o ev1172.o ev1172d.o \
	ki1160.o ki1160d.o uc1189.o uc1189d.o ev1171.o ev1171d.o ev1170.o \
	ev1170d.o ev1169.o ev1169d.o 

all: Cobj7.o

Cobj7.o: $(OBJECTS) Makefile
	$(LD) $(LDFLAGS) -r -o Cobj7.o $(OBJECTS)
	$(RM) $(OBJECTS)
	$(CREATE_TEST)

clean: local_clean
clobber: local_clobber

local_clean::
	$(RM) core finished *.o

local_clobber:: local_clean
	$(RM) Makefile

