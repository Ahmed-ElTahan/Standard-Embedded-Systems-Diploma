gcc -c main.c -o main.o
gcc -c add.c -o add.o
gcc main.o add.o -o calculator.exe
