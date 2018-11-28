INCLUDEPATHS=-I"../openssl-1.0.2d/include" -I"../boost_1_35_0"
LIBPATHS=-L"../openssl-1.0.2d"
LIBS= \
 -l crypto\
 -l kernel32 -l user32 -l gdi32 -l comdlg32 -l winspool -l winmm -l shell32 -l comctl32 -l ole32 -l oleaut32 -l uuid -l rpcrt4 -l advapi32 -l ws2_32
CFLAGS=-mthreads -O0 -w -Wno-invalid-offsetof -Wformat   $(INCLUDEPATHS) -static
HEADERS=headers.h util.h serialize.h uint256.h key.h bignum.h base58.h

all:test.exe

obj/util.o: util.cpp		    $(HEADERS)
	g++ -c $(CFLAGS) -o $@ $<
	
obj/test.o: test.cpp $(HEADERS)
	g++ -c $(CFLAGS) -o $@ $<

obj/sha.o: sha.cpp		    sha.h
	g++ -c $(CFLAGS) -O3 -o $@ $<
	
OBJS=obj/test.o

test.exe: $(OBJS)
	-kill /f test.exe
	g++ $(CFLAGS) -o $@ $(LIBPATHS) $(OBJS) $(LIBS)

clean:
	-del /Q obj\*
