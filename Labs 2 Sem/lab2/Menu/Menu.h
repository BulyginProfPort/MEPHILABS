//
// Created by Fedor Bulygin on 23.10.2022.
//
#ifndef LAB2_MENU_H
#define LAB2_MENU_H

#include <cstring>
#include <iostream>

void Menu();
void TestsMenu();
void LinkedListSequenceMenu();
void ArraySequenceMenu();
void MatrixMenu();
void SetMenu();
void GetMenu();
void CheckNumSize(const char *arr, int &s, int size);
int StrToInt(const char *s);
void InputNumCheckInt(char* arr, int size, int &num);
void InputIndex(int length, int &index);
void InputIndexes(int length, int &firstIndex,int &lastIndex);

#endif //LAB2_MENU_H
