FLGS = -std=c++11 -g

all:lab4

cmplx.o: ComplexNumbers.cpp
	g++ -c ComplexNumbers.cpp $(FLGS) -o cmplx.o
person.o: Person.cpp
	g++ -c Person.cpp $(FLGS) -o person.o
test.o: Tests.cpp
	g++ -c Tests.cpp $(FLGS) -o test.o
list.o: List.cpp
	g++ -c List.cpp $(FLGS) -o list.o 
tree.o: Tree.cpp
	g++ -c Tree.cpp $(FLGS) -o tree.o
main.o: main.cpp
	g++ -c main.cpp $(FLGS) -o main.o
lab4: cmplx.o person.o list.o tree.o test.o main.o
	g++ cmplx.o person.o list.o tree.o test.o main.o -o lab4
clean:
	rm -f *.o
