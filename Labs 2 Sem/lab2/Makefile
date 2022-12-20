CXX = g++

LL = LinkedList/LinkedList.cpp
LLS = Sequence/LinkedListSequence/LinkedListSequence.cpp
DA = DynamicArray/DynamicArray.cpp
DAS = Sequence/ArraySequence/ArraySequence.cpp
S = Sequence/Sequence.cpp
MTRX = Matrix/matrix.cpp
T = tests/test.cpp
FLGS = -std=c++11 -g

all: lab2

list.o: $(LL)
	$(CXX) -c $(LL) $(FLGS) -o list.o

DynamicArray.o: $(DA)
	$(CXX) -c $(DA) $(FLGS) -o DynamicArray.o

ArraySequence.o: $(DAS)
	$(CXX) -c $(DAS) $(FLGS) -o ArraySequence.o

LinkedListSequence.o: $(LLS)
	$(CXX) -c $(LLS) $(FLGS) -o LinkedListSequence.o

Sequence.o: $(S)
	$(CXX) -c $(S) $(FLGS) -o Sequence.o

matrix.o: $(MTRX)
	$(CXX) -c $(MTRX) $(FLGS) -o matrix.o

test.o: $(T)
	$(CXX) -c $(T) $(FLGS) -o test.o

main.o: main.cpp
	$(CXX) -c main.cpp $(FLGS) -o main.o
	 
lab2: list.o DynamicArray.o ArraySequence.o LinkedListSequence.o Sequence.o matrix.o test.o main.o
	$(CXX) list.o DynamicArray.o ArraySequence.o LinkedListSequence.o Sequence.o matrix.o test.o main.o $(FLGS) -o lab2

clean:
	    rm -f *.o lab2