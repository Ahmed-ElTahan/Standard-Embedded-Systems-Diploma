calculator: main.o add.o
	gcc main.o add.o -o calculator.exe

main.o: main.c
	gcc -c main.c -o main.o

add.o: add.c
	gcc -c add.c -o add.o

clean:
	rm main.o add.o calculator.exe