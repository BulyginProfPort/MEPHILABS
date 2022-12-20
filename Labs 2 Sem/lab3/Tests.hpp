//
//  Tests.hpp
//  lab3
//
//  Created by Фёдор Булыгин on 20.05.2022.
//

#ifndef Tests_hpp
#define Tests_hpp

#include <stdio.h>
#include "ComplexNumbers.hpp"
#include "Person.hpp"
bool onlyNegativeIntNum(int a);
bool CmplxNum(class Complex a);
bool PersonNum(class Person a);
int quadInt(int a);
Complex quadCmplx(Complex a);
Person quadPerson(Person a);
Complex quadCmplx(Complex a);
Person quadPerson(Person a);
bool testMapInt();
bool testWhereInt();
bool testMergeInt();
bool testExtractionInt();
bool testMapCmplx();
bool testWhereCmplx();
bool testMergeCmplx();
bool testExtractionCmplx();
bool testMapPerson();
bool testWherePerson();
bool testMergePerson();
void AllTests();
#endif /* Tests_hpp */
