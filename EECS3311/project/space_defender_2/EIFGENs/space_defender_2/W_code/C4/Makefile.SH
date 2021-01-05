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
echo "Compiling C code in C4"
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

OBJECTS = big_file_C4_c.o 

OLDOBJECTS =  es1064.o es1064d.o es1060.o es1060d.o es1063.o es1063d.o es1062.o \
	es1062d.o et1058.o et1058d.o et1061.o et1061d.o es1059.o es1059d.o \
	ti1086.o ti1086d.o da1087.o da1087d.o ti1085.o ti1085d.o ti1084.o \
	ti1084d.o da1090.o da1090d.o da1089.o da1089d.o fo1081.o fo1081d.o \
	ev1077.o ev1077d.o ti1083.o ti1083d.o co1082.o co1082d.o da1088.o \
	da1088d.o sc1079.o sc1079d.o or1080.o or1080d.o ev1078.o ev1078d.o \
	ev1076.o ev1076d.o ev1075.o ev1075d.o ev1074.o ev1074d.o ki1069.o \
	ki1069d.o ev1073.o ev1073d.o ev1071.o ev1071d.o ev1070.o ev1070d.o \
	ki1068.o ki1068d.o uc1067.o uc1067d.o uc1066.o uc1066d.o rt1072.o \
	rt1072d.o uc1065.o uc1065d.o 

all: Cobj4.o

Cobj4.o: $(OBJECTS) Makefile
	$(LD) $(LDFLAGS) -r -o Cobj4.o $(OBJECTS)
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

