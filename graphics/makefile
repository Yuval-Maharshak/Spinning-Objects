CC = g++
CFLAGS = -Wall

unit: unit.o terminal.o
	$(CC) $(CFLAGS) -o unit unit.o terminal.o -lncurses

unit.o: unit.cpp terminal.h head.h
	$(CC) $(CFLAGS) -c unit.cpp

terminal.o: terminal.cpp terminal.h head.h
	$(CC) $(CFLAGS) -c terminal.cpp

clean:
	rm *.o