//
// Created by Fedor Bulygin on 04.12.2022.
//

#ifndef LAB2_3_COUNTSUBSEQUENCE_H
#define LAB2_3_COUNTSUBSEQUENCE_H

#include <vector>
#include "../../HashTable/HashTable.h"
#include <vector>

using namespace std;

template <typename T>
struct Sequence {
    T name; // Подстрока
    vector<int> count; // Кол-во ее вхождений
};
template <typename T>
bool cmp(Sequence<T> &v1, Sequence<T> &v2){
    return v1.count.size() > v2.count.size();
}
template <class KeyType, class DataType>
void Crochemore(HashTable<KeyType, DataType> &dict, string &sqnce, vector<string> &indexes){
    auto sqnce_min = 1;
    auto sqnce_max = sqnce.length() / 2;
    if (sqnce.length() < 5)
        sqnce_max = sqnce.length();
    // Используется алгоритм Крочемора, сложность O(n^2)
    for (int i = 0; i < sqnce.length(); i++) {
        for (auto j = sqnce_min; j < sqnce_max + 1; j++) {
            string ss = sqnce.substr(i, j);
            if (!dict.Search(ss)) {
                indexes.push_back(ss);
                vector<int> v1{i};
                dict.InsertItem(ss, v1);
            }
            else
            {
                vector<int> v2;
                for (auto it = dict[ss].begin(); it != dict[ss].end(); it++) {
                    if ( ( (*it).key == ss) && ( (*it).data[(*it).data.size() - 1] != i ) ) {
                        v2 = (*it).data;
                        v2.push_back(i);
                        (*it).data = v2;
                    }
                }
            }
        }
    }
}

#endif //LAB2_3_COUNTSUBSEQUENCE_H
