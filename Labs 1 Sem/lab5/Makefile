all: lab5
main.o: lab5.c
	gcc -c -std=c99 lab5.c -o ofiles/main.o

menu.o: Functions/menu.c
	gcc -c -std=c99 Functions/menu.c -o ofiles/menu.o

delete.o: Functions/delete.c
	gcc -c -std=c99 Functions/delete.c -o ofiles/delete.o

change.o: Functions/change.c
	gcc -c -std=c99 Functions/change.c -o ofiles/change.o

randv.o: Functions/randv.c
	gcc -c -std=c99 Functions/randv.c -o ofiles/randv.o

other_functions.o: Functions/other_functions.c
	gcc -c -std=c99 Functions/other_functions.c -o ofiles/other_functions.o

lab5: main.o menu.o delete.o change.o randv.o other_functions.o
	gcc ofiles/main.o ofiles/menu.o ofiles/delete.o ofiles/change.o ofiles/randv.o ofiles/other_functions.o -o lab5
clean:
	rm -f lab5 ofiles/*.o
