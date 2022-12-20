//
//  LinkedListSequence.hpp
//  lab2
//
//  Created by Фёдор Булыгин on 12.04.2022.
//
#pragma once

#ifndef ListSequence_hpp
#define ListSequence_hpp

#include <cstdio>

#include "../Sequence.h"
#include "../../LinkedList/LinkedList.h"
#include "../../DynamicArray/DynamicArray.h"

using namespace std;

template<class T>
class LinkedListSequence: public Sequence<T>{
private:
    LinkedList<T> *listM = nullptr;
public:
    LinkedListSequence(){
        listM = new LinkedList<T>();
    }
    
    LinkedListSequence(int k){
        listM = new LinkedList<T>(k);
    }
    
    LinkedListSequence(T* arr, int k){
        listM = new LinkedList<T>(arr,k);
    }
    
    LinkedListSequence(const LinkedList<T> &list){
        listM = new LinkedList<T> (list);
    }
    
    LinkedListSequence(const DynamicArray<T> &arr){
        listM = new LinkedList<T>();
        for (int i = 0; i < arr.GetSize(); i++){
            listM->InsertAt(arr.Get(i), i);
        }
    }

    LinkedListSequence(const LinkedListSequence<T> &listIn, int firstIndex, int lastIndex){
        listM = new LinkedList<T> ();
        *listM = listIn.listM->GetSubList(firstIndex, lastIndex);
    }

    T GetFirst() override{
        if ( listM->GetLength() == 0){
            throw "Index out of range";
        }
        return listM->GetFirstValue();
    }

    T GetLast() override{
        if ( listM->GetLength() == 0){
            throw "Index out of range";
        }
        return listM->GetLastValue();
    }

    T Get(int index) const override{
        if ( index < 0 || index + 1 > listM->GetLength() ){
            throw "Index out of range";
        }
        return listM->Get(index);
    }

    void Set(T value, int index) override{
        listM->Set(value,index);
    }

    int GetLength() override{
        return listM->GetLength();
    }
    
    void Append(T value) override{
        listM->Append(value);
    }
    
    void Prepend(T value) override{
        listM->Prepend(value);
    }
    
    void InsertAt(T value, int index) override{
        if (index < 0 || index + 1 > listM->GetLength() ){
            throw "Index out of range";
        }
        listM->InsertAt(value, index);
    }

    void Delete(int firstIndex, int lastIndex) {
        listM->PopRange(firstIndex,lastIndex);
    }

    void Concatenate(LinkedListSequence<T> const &a){
        listM->Concatenate(a.listM);
    }

    void Print() override{
        listM->Print();
    }

    void operator+(LinkedListSequence<T> const *list2);

    void operator-(LinkedListSequence<T> const *list2);

    void operator*(LinkedListSequence<T> const *list2);

    void operator/(LinkedListSequence<T> const *list2);

    T& operator[](int index) override;

    ~LinkedListSequence(){
        delete listM;
    }
};

template<class T>
void LinkedListSequence<T>::operator+(const LinkedListSequence<T> *list2) {
    listM->operator+(list2->listM);
}

template<class T>
void LinkedListSequence<T>::operator-(const LinkedListSequence<T> *list2) {
    listM->operator-(list2->listM);
}

template<class T>
void LinkedListSequence<T>::operator*(const LinkedListSequence<T> *list2) {
    listM->operator*(list2->listM);
}

template<class T>
void LinkedListSequence<T>::operator/(const LinkedListSequence<T> *list2) {
    listM->operator/(list2->listM);
}

template<class T>
T& LinkedListSequence<T>::operator[](const int index) {
    return listM->Get(index);
}


#endif /* ListSequence_hpp */
