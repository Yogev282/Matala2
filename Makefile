CC = gcc
FLAGS = -Wall -g

make all: connections

connections: lib_my_mat.so
	$(CC) $(FLAGS) -o connections main.o my_mat.o 

lib_my_mat.so: my_mat.o main.o	
	$(CC) -shared -o lib_my_mat.so my_mat.o

my_mat.o: my_mat.h my_mat.c
	$(CC) $(FLAGS) -c my_mat.c

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

clean:
	rm -f *.o *.a *.so co connections

leakTest: clean connections
	valgrind --leak-check=full  --track-origins=yes --show-leak-kinds=all --error-exitcode=1 ./connections