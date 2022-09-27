CC=gcc -g
LIBS= -L C:/sd/MinGW/lib/gcc-lib/mingw32/3.2.3/ -lstdc++

all: IP

IP: InfixToPostfix.o st_common.o
	$(CC) -o IP InfixToPostfix.o st_common.o

st_common.o: st_common.c st_common.h
	$(CC) -c st_common.c -o st_common.o  $(LIB)

InfixToPostfix.o: InfixToPostfix.c
	$(CC) -c InfixToPostfix.c -o InfixToPostfix.o $(LIB)

clean:
	del -f IP.exe
	del -f *.o

