case $CONFIG in
'')
	if test ! -f ../config.sh; then
		(echo "Can't find ../config.sh."; exit 1)
	fi 2>/dev/null
	. ../config.sh
	;;
esac
case "$O" in
*/*) cd `expr X$0 : 'X\(.*\)/'` ;;
esac
echo "Compiling C code in C21"
$spitshell >Makefile <<!GROK!THIS!
INCLUDE_PATH =  -I"\$(ISE_LIBRARY)/library/encoding/implementation/include" -I"\$(ISE_LIBRARY)/library/time/spec/include" -I"\$(ISE_LIBRARY)/library/vision2/spec/include" -I"\$(ISE_LIBRARY)/library/vision2/implementation/gtk/Clib" `$ISE_LIBRARY/library/encoding/implementation/unix/Clib/iconv-config --include_path` `$ISE_LIBRARY/library/vision2/implementation/gtk/Clib/vision2-gtk-config --include_path`
SHELL = /bin/sh
CC = $cc
CPP = $cpp
CFLAGS = $wkoptimize $mtccflags $large -DWORKBENCH -I"$rt_include" -I. \$(INCLUDE_PATH)
CPPFLAGS = $wkoptimize $mtcppflags $large -DWORKBENCH -I"$rt_include" -I. \$(INCLUDE_PATH)
LDFLAGS = $ldflags
CCLDFLAGS = $ccldflags  $windows_flags
LDSHAREDFLAGS =  $mtldsharedflags
EIFLIB = "$rt_lib/$prefix$mt_prefix$wkeiflib$suffix"
EIFTEMPLATES = $rt_templates
LIBS = $mtlibs
MAKE = $make
AR = $ar
LD = $ld
MKDEP = $mkdep \$(DPFLAGS) --
MV = $mv
CP = $cp
RANLIB = $ranlib
RM = $rm -f
FILE_EXIST = $file_exist
RMDIR = $rmdir
X2C = "$x2c"
SHAREDLINK = $sharedlink
SHAREDLIBS = $sharedlibs
SHARED_SUFFIX = $shared_suffix
COMMAND_MAKEFILE = 
START_TEST = $start_test 
END_TEST = $end_test 
CREATE_TEST = $create_test 
SYSTEM_IN_DYNAMIC_LIB = space_defender_2$shared_suffix 
!GROK!THIS!
$spitshell >>Makefile <<'!NO!SUBS!'

.SUFFIXES:.cpp .o

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

OBJECTS = big_file_C21_c.o 

OLDOBJECTS =  ty1622.o ty1622d.o ty1623.o ty1623d.o ty1624.o ty1624d.o ty1626.o \
	ty1626d.o ar1625.o ar1625d.o he1635.o he1635d.o he1633.o he1633d.o \
	tr1630.o tr1630d.o bi1629.o bi1629d.o bi1628.o bi1628d.o pr1634.o \
	pr1634d.o tr1631.o tr1631d.o li1632.o li1632d.o kl1636.o kl1636d.o \
	kl1640.o kl1640d.o kl1647.o kl1647d.o kl1648.o kl1648d.o kl1619.o \
	kl1619d.o kl1637.o kl1637d.o kl1641.o kl1641d.o kl1646.o kl1646d.o \
	kl1649.o kl1649d.o kl1620.o kl1620d.o kl1638.o kl1638d.o kl1642.o \
	kl1642d.o kl1644.o kl1644d.o kl1650.o kl1650d.o kl1621.o kl1621d.o \
	kl1639.o kl1639d.o kl1643.o kl1643d.o kl1645.o kl1645d.o kl1651.o \
	kl1651d.o kl1627.o kl1627d.o 

all: Cobj21.o

Cobj21.o: $(OBJECTS) Makefile
	$(LD) $(LDFLAGS) -r -o Cobj21.o $(OBJECTS)
	$(RM) $(OBJECTS)
	$(CREATE_TEST)

clean: local_clean
clobber: local_clobber

local_clean::
	$(RM) core finished *.o

local_clobber:: local_clean
	$(RM) Makefile

!NO!SUBS!
chmod 644 Makefile
$eunicefix Makefile

