//
//  test.hpp
//  lab2
//
//  Created by Фёдор Булыгин on 12.04.2022.
//
#pragma once
#ifndef test_hpp
#define test_hpp

#include <iostream>
#include "../LinkedList/LinkedList.h"
#include "../DynamicArray/DynamicArray.h"

// LinkedList
void LinkedListTestCheckSize();
void testLlCnstrByArr();
void testLlCnstrByLinkedList();
void testLlGetFirstValue();
void testLlGetLastValue();
void testLlGetValueByIndex();
void testLlAppend();
void testLlPrepend();
void testLlInsertAt();
void testLlSubList();

void AllLinkedListTests();

// DynamicArray
void testDaCheckSize();
void testDaCnstrByArray();
void testDaCnstrByDynamicArray();
void testDaCnstrByArrayInterval();
void testDaCnstrByDynamicArrayInterval();

void AllDynamicArrayTests();

//Array Sequence
void testAsCheckSize();
void testAsCnstrByArray();
void testAsCnstrByDynamicArray();
void testAsCnstrByArrayInterval();
void testAsCnstrByDynamicArrayInterval();
void testAsGetFirstValue();
void testAsGetLastValue();
void testAsAppend();
void testAsPrepend();
void testGetValueByIndex();

void AllArraySequenceTests();

//LinkedList Sequence
void testLlsCheckSize();
void testLlsCnstrByArray();
void testLlsCnstrByLL();
void testLlsCnstrByDa();
void testLlsGetFirstValue();
void testLlsGetLastValue();
void testLlsGetValueByIndex();
void testLlsAppend();
void testLlsPrepend();
void testLlsInsertAt();

void AllLinkedListSequenceTests();

//ISotrer tests
void testQsort(){}
void testShellSort(){}
void testBsort(){}

// All Tests
void AllTests();
#endif /* test_hpp */
