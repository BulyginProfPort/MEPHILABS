//
// Created by Fedor Bulygin on 27.10.2022.
//
#include "ISorter/ISorter.h"
#include "Sequence/ArraySequence/ArraySequence.h"
bool IntAscCmp(int v1, int v2){
    return v1>v2;
}
int main(){
    int a[10] = {0,1,45,67,4,3,7,9,4,1};
    ArraySequence<int> Arr1(a,10);
    ArraySequence<int> Arr2(a,10);

    ISorter<ArraySequence<int>,int> var;

    Arr1.Print();
    var.Qsort(Arr1,IntAscCmp);
    Arr1.Print();

    printf("\n");

    Arr2.Print();
    var.HeapSort(Arr2,IntAscCmp);
    Arr2.Print();

    return 0;
}