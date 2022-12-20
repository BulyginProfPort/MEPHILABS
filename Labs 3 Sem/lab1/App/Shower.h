#pragma once
#include "vector"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "../ISorter/ISorter.h"
#define Type ArraySequence<int>

bool IntAscCmp(int v1, int v2);
bool DspAscCmp(int v1, int v2);
class Shower {
private:
    Type* arr;
    int size;
public:
    void createArr(int size);
    string sortArr(string s); // возвращает время выполнения
    string getArr();
    vector<double> getPointForGraph(string s);
};