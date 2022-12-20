#pragma once

#ifndef matrix_hpp
#define matrix_hpp


#include <iostream>
#include <ctime>
#include "../Sequence/Sequence.h"
#include "../Sequence/LinkedListSequence/LinkedListSequence.h"
#include "../Sequence/ArraySequence/ArraySequence.h"

using namespace std;

// шаблонный класс Матрица
template <class D,class T>
class Matrix{
private:
    D **AM = nullptr;
    int rows = 0; // количество строк
    int columns = 0; // количество столбцов
public:
    //КОНСТРУКТОР
    Matrix() {
        columns = rows = 0;
        AM = nullptr; // необязательно
    }

    Matrix(int x, int y) {

        rows = x;
        columns = y;
        AM = new D *[rows]; // количество строк, количество указателей на строки в матрице
        for (int i = 0; i < rows; i++) {
            AM[i] = new D(columns);
            for (int j = 0; j < columns; j++) {
                AM[i]->Set(rand() % 10, j);
            }
        }
    }

    Matrix(const Matrix<D,T> &NM) {
        // Создается новый объект для которого выделяется память
        // Копирование данных *this <= NM
        rows = NM.rows;
        columns = NM.columns;
        AM = NM.AM;
    }

    // методы доступа
    T const GetMij(int i, int j) {
        if (i < 0 || j < 0 || i >= rows || j >= columns) {
            throw "IndexOutOfRange";
        }
        if ((rows > 0) && (columns > 0)) {
            return AM[i]->Get(j);
        } else {
            return 0;
        }
    }

    int GetRows() {
        return rows;
    }

    int GetColumns() {
        return columns;
    }

    void SetRows(int n) {
        rows = n;
    }

    void SetColumns(int n) {
        columns = n;
    }

    void SetMij(int i, int j, T value) {
        if ((i < 0) || (i >= rows)) {
            throw "IndexOutOfRange";
        }
        if ((j < 0) || (j >= columns)) {
            throw "IndexOutOfRange";
        }
        AM[i]->Set(value, j);
    }

    // метод, выводящий матрицу
    void const Print() {
        for (int i = 0; i < rows; i++) {
            AM[i]->Print();
            cout << endl;
        }
    }

    void operator+(Matrix<D,T> const &matrix2) {
        for (int i = 0; i < rows; i++) {
            AM[i]->operator+(matrix2.AM[i]);
        }
    }

    void operator-(Matrix<D,T> const &matrix2){
        for (int i = 0; i < rows; i++){
            AM[i]->operator-(matrix2.AM[i]);
        }
    }
    void operator*(Matrix<D,T> const &matrix2){
        if (rows == matrix2.columns){
            Matrix<D,T> res(rows,columns);
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < columns; j++){
                    for (int k = 0; k < columns ; k++){
                        res.AM[i]->Set( res.GetMij(i, j) + ( AM[i]->Get(k) * matrix2.AM[k]->Get(j) ), j);
                    }
                }
            }
            cout << "Result matrix" << endl;
            res.Print();
            cout<< "finish"<<endl;
        }
        else{
            printf("Cant multiply matrix");
            return;
        }
    }

    // Деструктор - освобождает память, выделенную для матрицы
    ~Matrix(){
        for (int i = 0; i < rows; i++){
            delete AM[i];
        }
        delete [] AM;
    }
};
#endif /* matrix_hpp */
