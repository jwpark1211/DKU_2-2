CC=gcc -g
LIBS= -L C:/sd/MinGW/lib/gcc-lib/mingw32/3.2.3/ -lstdc++

all: PM

PM: pmatching.o st_common.o
	$(CC) -o PM pmatching.o st_common.o

st_common.o: st_common.c st_common.h
	$(CC) -c st_common.c -o st_common.o  $(LIB)

pmatching.o: pmatching.c
	$(CC) -c pmatching.c -o pmatching.o $(LIB)

clean:
	del -f PM.exe
	del -f *.o

