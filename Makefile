CC = gcc
AR = ar
FLAGS = -Wall -g

make all: connections

connections: my_mat.o
	$(CC) $(FLAGS) -o connections main.c my_mat.o

my_mat.o: my_mat.h my_mat.c
	$(CC) $(FLAGS) -c my_mat.c

clean:
	rm -f *.o *.a *.so co connections
