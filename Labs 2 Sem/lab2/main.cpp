#include <cstring>
#include <iostream>
#include "Matrix/matrix.h"
#include "Sequence/ArraySequence/ArraySequence.h"
#include "Sequence/LinkedListSequence/LinkedListSequence.h"
#include "ISorter/ISorter.h"
#include "Menu/Menu.h"

using namespace std;
//
// Created by Fedor Bulygin on 04.10.2022.
//
bool IntAscCmp(int v1, int v2){
    return v1 > v2;
}
bool IntDscCmp(int v1, int v2){
    return v1 < v2;
}

int main(int argc, char* argv[]){
    int setArr[10] = {4,9,7,6,2,3,8,3,5,7};

    int firstIndex = 0, lastIndex = 0 , res = 0, index = 0, num = 0 , i = 0, j = 0;
    char input[7] , arr[20];

    memset(input, '\0', 7 * sizeof(char));

    ArraySequence<int> ArrSeq(setArr, 10);
    ArraySequence<int> ArrSeq2(setArr, 5);

    LinkedListSequence<int> LlSeq(setArr, 10);
    LinkedListSequence<int> LlSeq2(setArr, 5);

    Matrix< LinkedListSequence<int> ,int> matrix1(4, 4);
    Matrix< LinkedListSequence<int> ,int> matrix2(4, 4);

    //
    ArraySequence<int> ArrSeq11(setArr, 10);
    ArraySequence<int> ArrSeq12(setArr, 10);
    ArraySequence<int> ArrSeq13(setArr, 10);

    LinkedListSequence<int> LlSeq11(setArr, 10);
    LinkedListSequence<int> LlSeq12(setArr, 10);
    LinkedListSequence<int> LlSeq13(setArr, 10);

    ISorter<int, ArraySequence<int> > var1(ArrSeq11);
    ISorter<int, ArraySequence<int> > var2(ArrSeq12);
    ISorter<int, ArraySequence<int> > var3(ArrSeq13);

    cout<<"Qsort"<<endl;
    var1.a.Print();
    var1.Qsort(IntAscCmp );
    var1.a.Print();
    cout<<endl;

    cout<<"ShellSort"<<endl;
    var2.a.Print();
    var2.ShellSort(IntAscCmp);
    var2.a.Print();
    cout<<endl;

    cout<<"BatcherSort"<<endl;
    var3.a.Print();
    //var2.(IntAscCmp);
    var3.a.Print();
    cout<<endl;
    //

    srand(time(nullptr));

    return 0;
}
