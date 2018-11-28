# Copyright (c) 2009 Satoshi Nakamoto
# Distributed under the MIT/X11 software license, see the accompanying
# file license.txt or http://www.opensource.org/licenses/mit-license.php.


ifneq "$(BUILD)" "debug"
ifneq "$(BUILD)" "release"
BUILD=debug
endif
endif
ifeq "$(BUILD)" "debug"
D=d
# note: gcc 3.x profile doesn't work
#DEBUGFLAGS=-O0 -g -pg -D__WXDEBUG__
DEBUGFLAGS=-g -D__WXDEBUG__
endif

INCLUDEPATHS=-I"../openssl-1.0.2d/include"
LIBPATHS=-L"../openssl-1.0.2d"
LIBS= \
 -l crypto \
 -l kernel32 -l user32 -l gdi32 -l comdlg32 -l winspool -l winmm -l shell32 -l comctl32 -l ole32 -l oleaut32 -l uuid -l rpcrt4 -l advapi32 -l ws2_32
WXDEFS=-DWIN32 -D__WXMSW__  -DNOPCH
CFLAGS=-mthreads -O0  -Wno-invalid-offsetof -Wformat $(DEBUGFLAGS) $(WXDEFS) $(INCLUDEPATHS) -static
HEADERS=bignum.h

all: main.exe

obj/main.o: main.cpp		    $(HEADERS)
	g++ -c $(CFLAGS) -o $@ $<


OBJS=obj/main.o

main.exe: $(OBJS)
	-kill /f main.exe
	g++ $(CFLAGS) -o $@ $(LIBPATHS) $(OBJS) $(LIBS)

clean:
	-del /Q obj\*
