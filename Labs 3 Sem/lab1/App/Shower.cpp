#include <random>
#include <string>
#include <ctime>
#include "Shower.h"
bool IntAscCmp(int v1, int v2){
    return v1>v2;
}
bool DspAscCmp(int v1, int v2){
    return v1<v2;
}
void Shower::createArr(int size) {
    this->size = size;
    int* tmp_arr = new int[size];

    for (int i = 0; i < size; i++)
        tmp_arr[i] = rand() % 100 + 1;

    arr = new Type(tmp_arr, size);

    delete[] tmp_arr;
}

string Shower::sortArr(string s) {
    auto start = clock();
    if (s == "Shaker")
        ISorter<Type, int>::HeapSort(*arr, IntAscCmp);
    else if(s == "Quick")
        ISorter<Type,int>::Qsort(*arr, IntAscCmp);
    else if(s == "Shell")
        ISorter<Type,int>::ShellSort(*arr ,IntAscCmp);
    auto end = clock();

    return to_string((double)(end - start) / (CLOCKS_PER_SEC / 1000) );
}

string Shower::getArr() {
    string res = "";
    for (int i = 0; i < this->size; i++)
        res += to_string(arr->Get(i)) + " ";
    return res;
}

vector<double> Shower::getPointForGraph(string s) {
    vector<double> resVec;
    resVec.push_back(0);

    for (int i = 1; i <= 100000; i*=10) {
        int tmp_size = i;
        int* tmp_arr = new int[tmp_size];

        for (int j = 0; j < tmp_size; j++)
            tmp_arr[j] = rand() % 10 + 1;

        Type ArrSeq(tmp_arr, tmp_size);

        auto start = clock();

        if (s == "Shaker")
            ISorter<Type, int>::HeapSort(ArrSeq, IntAscCmp);
        else if (s == "Quick")
            ISorter<Type,int>::Qsort(ArrSeq, IntAscCmp);
        else if (s == "Shell")
            ISorter<Type,int>::ShellSort(ArrSeq, IntAscCmp);

        auto end = clock();

        resVec.push_back( (double)(end - start) / (CLOCKS_PER_SEC / 1000));
        delete[] tmp_arr;
    }

    return resVec;
}