//
// Created by Fedor Bulygin on 14.10.2022.
//
#pragma once

#ifndef LAB1_ISORTER_H
#define LAB1_ISORTER_H

#include "Sequence.h"
#include "LinkedListSequence.h"
#include "ArraySequence.h"
template <class D, class T>
class ISorter{
private:
    static void qsort(D& a,bool (*cmp)(T, T), int left, int right ) {
        int i = left;
        int j = right;
        T pivot = a[(i + j) / 2 ];
        while (i <= j){
            while ( i < (a.GetLength() - 1) && (cmp(pivot, a[i]) == true) )
                i++;
            while ( j > left && cmp(a[j], pivot) == true)
                j--;
            if (i <= j){
                a.Swap(i,j);
                i++;
                j--;
            }
        }
        if (j > left)
            qsort(a, cmp, left, j );
        if (i < right)
            qsort(a, cmp, i, right );
    }
    static void heapify(D& a, int i, int size){
        int big = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < size && a[l] > a[big] )
            big = l;
        if (r < size && a[r] > a[big] )
            big = r;
        if (big != i) {
            a.Swap(i, big);
            heapify(a, big, size);
        }
    }
    static void heapSort(D& a, bool (*cmp)(T, T)){
        int size = a.GetLength();
        for (int i = size/2 - 1 ; i >= 0; i--)
            heapify(a, i, size );
        for (int i = size - 1; i >= 0; i--){
            a.Swap(0, i);
            heapify(a, 0, i);
        }
    }
public:
    static void Qsort(D& a,bool (*cmp)(T, T)){
        qsort(a,cmp,0,a.GetLength() - 1);
    }

    static void ShellSort(D& a, bool (*cmp)(T,T) ){
        for (int s = a.GetLength() / 2; s > 0; s /= 2) {
            for (int i = s; i < a.GetLength(); ++i) {
                for (int j = i - s; j >= 0 && cmp(a[j],a[j+s]) == true; j -= s) {
                    a.Swap(j,j+s);
               }
            }
        }
    }

    static void HeapSort(D& a, bool (*cmp)(T, T)){
        heapSort(a, cmp);
    }

};
#endif //LAB1_ISORTER_H
