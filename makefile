all: main.o
	gcc -o work15 main.o

main.o: main.c
	gcc -c main.c

run: 
	./work15

clean: 
	rm *.o
