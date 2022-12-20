#include "../ArraySequence/ArraySequence.h"
#include "../ISorter/ISorter.h"
#include "../App/Shower.h"
#include <vector>
#define Type ArraySequence<int>

void QuickSortTest(ArraySequence<int> &arr, vector<int> vec, string *x, bool (*cmp)(int,int)) {
    ISorter<Type,int>::ShellSort(arr, IntAscCmp);
    sort(vec.begin(), vec.end());
    bool m = 1;
    for(int i = 0; i < arr.GetLength(); i++) {
        if (arr[i] != vec[i])
            m = 0;
    }
    if (m)
        *x += "Quick - Test has been successful passed\n";
    else
        *x += "Quick - Test was failed\n";
}

void ShellSortTest(ArraySequence<int> &arr,  vector<int> vec, string *x, bool (*cmp)(int,int)){
    ISorter<Type,int>::Qsort(arr, IntAscCmp);
    sort(vec.begin(), vec.end());
    bool m = 1;
    for(int i = 0; i < arr.GetLength(); i++) {
        if (arr[i] != vec[i])
            m = 0;
    }
    if (m)
        *x += "Shell sort - Test has been successful passed\n";
    else
        *x += "Shell sort - Test was failed\n";
}

void HeapSortTest(ArraySequence<int> &arr, vector<int> vec, string *x, bool (*cmp)(int,int) ) {
    ISorter<Type,int>::HeapSort(arr,IntAscCmp );
    sort(vec.begin(), vec.end());
    bool m = 1;
    for(int i = 0; i < arr.GetLength(); i++) {
        if (arr[i] != vec[i])
            m = 0;
    }
    if (m)
        *x += "Heap sort - Test has been successful passed\n";
    else
        *x += "Heap sort - Test was failed\n";
}

string SortTests() {
    int Arr[5];

    for (int & i : Arr)
        i = 1 + rand() % 5;

    string x;
    ArraySequence<int> ArrSeq1(Arr, 5);
    ArraySequence<int> ArrSeq2(Arr, 5);
    ArraySequence<int> ArrSeq3(Arr, 5);

    vector<int> vec1(Arr, Arr + sizeof Arr / sizeof Arr[0]);
    vector<int> vec2(Arr, Arr + sizeof Arr / sizeof Arr[0]);
    vector<int> vec3(Arr, Arr + sizeof Arr / sizeof Arr[0]);

    x +="Usual Sort\n";
    QuickSortTest(ArrSeq1,vec1,&x,IntAscCmp);
    ShellSortTest(ArrSeq2,vec2,&x,IntAscCmp);
    HeapSortTest(ArrSeq3, vec3,&x,IntAscCmp);

    vec1.reserve(vec1.size());
    vec2.reserve(vec1.size());
    vec3.reserve(vec1.size());

    x +="Back Sort\n";
    QuickSortTest(ArrSeq1,vec1,&x,DspAscCmp);
    ShellSortTest(ArrSeq2,vec2,&x,DspAscCmp);
    HeapSortTest(ArrSeq3, vec3,&x,DspAscCmp);

    return x;
}