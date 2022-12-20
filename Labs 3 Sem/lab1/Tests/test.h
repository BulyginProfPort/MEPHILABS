#include "../ArraySequence/ArraySequence.h"
#include "../ISorter/ISorter.h"
#include <vector>
#include <string>
bool QuickSortTest(ArraySequence<int> &arr, vector<int> vec,string* x,bool (*cmp)(int,int));
bool ShellSortTest(ArraySequence<int> &arr, vector<int> vec,string* x,bool (*cmp)(int,int));
bool HeapSortTest(ArraySequence<int> &arr, vector<int> vec,string* x,bool (*cmp)(int,int));
string SortTests();