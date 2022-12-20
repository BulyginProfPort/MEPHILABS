//
//  Sequence.hpp
//  lab2
//
//  Created by Фёдор Булыгин on 03.04.2022.
//
#ifndef Sequence_hpp
#define Sequence_hpp

#include <iostream>
using namespace std;
template <class T>
class Sequence{
public:
    virtual T GetLast() = 0;
    virtual T GetFirst() = 0;
    virtual T Get(int index) const = 0;
    virtual void Set(T value,int index) = 0;
    virtual int GetLength() = 0;
    virtual void Append(T value) = 0;
    virtual void Prepend(T value) = 0;
    virtual void InsertAt(T value, int index) = 0;
    virtual void Print() = 0;
    virtual T& operator[](int index) = 0;
};
#endif /* Sequence_hpp */
