main: main.o pessoas.o disciplinas.o
	gcc main.o pessoas.o disciplinas.o -o main

# Como gerar pessoas.o a partir de pessoas.c
pessoas.o: pessoas.c
	gcc -c pessoas.c

disciplinas.o: disciplinas.c
	gcc -c disciplinas.c

# Como gerar main.o a partir de main.c
main.o: main.c
	gcc -c main.c