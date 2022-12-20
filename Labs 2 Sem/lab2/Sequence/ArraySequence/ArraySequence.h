//
//  DynamicArraySequence.hpp
//  lab2
//
//  Created by Фёдор Булыгин on 12.04.2022.
//
#pragma once

#ifndef ArraySequence_hpp
#define ArraySequence_hpp

#include <cstdio>
#include "../Sequence.h"
#include "../../DynamicArray/DynamicArray.h"
#include "../../LinkedList/LinkedList.h"

using namespace std;

template <class T>
class ArraySequence: public Sequence<T>{
private:
    DynamicArray<T> *arrM = nullptr;
public:
    //Default ArraySequence constructor
    ArraySequence(){
        arrM = new DynamicArray<T>();
    }
    
    ArraySequence(int k){
        arrM = new DynamicArray<T>(k);
    }
    
    //K array elements DynamicArraySequence constructor
    ArraySequence(T* const arr, int k){
        arrM = new DynamicArray<T> (arr,k);
    }
    
    ArraySequence(T* const arr, int firstIndex, int lastIndex){
        arrM = new DynamicArray<T> (arr, firstIndex, lastIndex);
    }
    
    ArraySequence(ArraySequence<T> const &arrIn){
        arrM = arrIn.arrM;
    }
    
    //Copy constructor
    ArraySequence(DynamicArray<T> const &arr, int k){
        arrM = new DynamicArray<T> (arr);
    }
    
    ArraySequence( DynamicArray<T> const &arrIn, int firstElement, int lastElement){
        arrM = new DynamicArray<T>(arrIn, firstElement, lastElement);
    }

    ArraySequence( ArraySequence<T> const &arrIn, int firstElement, int lastElement){
        arrM = new DynamicArray<T>(*arrIn.arrM, firstElement, lastElement);
    }
    
    ArraySequence( LinkedList<T> const &list ){
        arrM = new DynamicArray<T>(list.GetLength());
        for (int i = 0; i < arrM->GetSize(); i++){
            arrM->Set(list.Get(i), i);
        }
    }

    T GetFirst() override{
        if(arrM->GetSize() == 0){
            throw "Index out of range";
        }
        return arrM->Get(0);
    }

    T GetLast() override{
        if(arrM->GetSize() == 0){
            throw "Index out of range";
        }
        return arrM->Get(arrM->GetSize() - 1);
    }
    
    int GetLength() override{
        return arrM->GetSize();
    }
    
    void Append(T value) override{
        arrM->ReSize( arrM->GetSize() + 1);
        arrM->Set(value, arrM->GetSize() - 1);
    }
    
    void Prepend(T value) override{
        int newSize = arrM->GetSize() + 1;
        arrM->ReSize(newSize);
        for (int i = newSize - 1; i > 0; i--){
            arrM->Set(arrM->Get(i - 1), i);
        }
        arrM->Set(value, 0);
    }

    T Get(int index) const override{
        if(index + 1 > arrM->GetSize() || index < 0){
            throw "Index out of range";
        }
        return arrM->Get(index);
    }
    
    void Set(T value, int index) override{
        arrM->Set(value, index);
    }
    
    void InsertAt(T value, int index) override{
        if ( index + 1 > arrM->GetSize() || index < 0){
            throw "Index out of range";
        }
        arrM->ReSize(arrM->GetSize() + 1);
        T *tmp = new T[ (arrM->GetSize() - 1) - index];
        int j = 0;
        for (int i = index; i < arrM->GetSize() - 1; i++){
            tmp[j++] = arrM->Get(i);
        }
        arrM->Set(value, index);
        j = 0;
        for (int i = index + 1; i < arrM->GetSize(); i++){
            arrM->Set(tmp[j++], i);
        }
        delete [] tmp;
    }

    void Swap(int index1, int index2){
        T tmp = arrM->Get(index2);
        arrM->Set(arrM->Get(index1),index2);
        arrM->Set(tmp,index1);
    }

    void Delete(int firstIndex, int lastIndex){
        if (firstIndex > lastIndex){
            T tmp = firstIndex;
            firstIndex = lastIndex;
            lastIndex = tmp;
        }
        arrM->Delete(firstIndex, lastIndex);
    }

    void Concatenate(ArraySequence<T> const &a){
        arrM->Concatenate(a.arrM);
    }

    void Print() override{
        arrM->Print();
    }
    
    void operator+ (ArraySequence<T>const  &arrIn);
    
    void operator- (ArraySequence<T> const &arrIn);
    
    void operator* (ArraySequence<T> const &arrIn);

    void operator/ (ArraySequence<T> const *arrIn);

    T& operator[](int index) override;

    T operator[](int index) const ;

    ~ArraySequence(){
        delete arrM;
    }
};

template<class T>
void ArraySequence<T>::operator+(const ArraySequence<T> &arrIn) {
    arrM->operator+( arrIn->arrM );
}

template<class T>
void ArraySequence<T>::operator-(const ArraySequence<T> &arrIn) {
    arrM->operator-(arrIn->arrM);
}

template<class T>
void ArraySequence<T>::operator*(const ArraySequence<T> &arrIn) {
    arrM->operator*(arrIn->arrM);
}

template<class T>
void ArraySequence<T>::operator/(const ArraySequence<T> *arrIn) {
    ArraySequence tmp(arrM->operator/(arrIn->arrM), max(arrM->GetSize(), arrIn->arrM->GetSize()) );
}

template<class T>
T& ArraySequence<T>::operator[](const int index) {
    return arrM->Get(index);
}

template<class T>
T ArraySequence<T>::operator[](const int index) const {
    if (index > arrM->GetSize()) {
        return;
    }
    return arrM->Get(index);
}

#endif /* ArraySequence_hpp */
