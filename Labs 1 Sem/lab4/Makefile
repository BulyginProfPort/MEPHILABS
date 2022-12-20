all: lab4

compare_swap.o: sorts/sort_fx/compare_swap.c
	gcc -c -std=c99 sorts/sort_fx/compare_swap.c -o ofiles/compare_swap.o

input.o: input.c
	gcc -c -std=c99 input.c -o ofiles/input.o

menu.o: menu.c
	gcc -c -std=c99 menu.c -o ofiles/menu.o

sort1.o: sorts/insertion_sort.c
	gcc -c -std=c99 sorts/insertion_sort.c -o ofiles/sort1.o

sort2.o: sorts/shaker_sort.c
	gcc -c -std=c99 sorts/shaker_sort.c -o ofiles/sort2.o

sort3.o: sorts/double_selection_sort.c
	gcc -c -std=c99 sorts/double_selection_sort.c -o ofiles/sort3.o

main.o: lab4.c
	gcc -c -std=c99 lab4.c -o ofiles/main.o

lab4: main.o input.o menu.o compare_swap.o sort1.o sort2.o sort3.o
	gcc -g -std=c99 ofiles/main.o ofiles/input.o ofiles/menu.o ofiles/compare_swap.o ofiles/sort1.o ofiles/sort2.o ofiles/sort3.o -o lab4

clean:
	rm -f lab4 *.o
