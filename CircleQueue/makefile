CC=gcc -g
LIBS= -L C:/sd/MinGW/lib/gcc-lib/mingw32/3.2.3/ -lstdc++

all: Cq

Cq: Cqmain.o Cqueue.o
	$(CC) -o Cq Cqmain.o Cqueue.o

Cqueue.o: Cqueue.c Cqueue.h
	$(CC) -c cqueue.c -o Cqueue.o  $(LIB)

Cqmain.o: Cqmain.c
	$(CC) -c Cqmain.c -o Cqmain.o $(LIB)

clean:
	del -f Cq.exe
	del -f *.o

