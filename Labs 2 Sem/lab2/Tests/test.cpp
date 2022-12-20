//
//  test.cpp
//  lab2
//
//  Created by Фёдор Булыгин on 12.04.2022.
//

#include "test.h"
#include "../Sequence/ArraySequence/ArraySequence.h"
#include "../Sequence/LinkedListSequence/LinkedListSequence.h"
#include "../Matrix/matrix.h"
using namespace std;
//                               LinkedList tests
struct Node {
    int value;
    struct Node *next = nullptr;
    struct Node *prev = nullptr;
};
struct List{
    struct Node *head = nullptr;
    struct Node *tail = nullptr;
};

void LinkedListTestCheckSize(){
    int size = 1;
    LinkedList<int> listT;
    try{
        if(size != listT.GetLength()){
            throw  "ERROR: LinkedList check size";
        }
        cout<<"Test: 'LinkedListTestCheckSize' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testLlCnstrByArray(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    LinkedList<int> listT(a,20);
    try{
        for (int i  = 0; i < 20; i++){
            if (a[i] != listT.Get(i) ){
                throw "ERROR: LinkedList constructor by array";
            }
        }
        cout<<"Test: 'testCnstrByArr' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testLlCnstrByLinkedList(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    LinkedList<int> listM(a,20);
    LinkedList<int> listT(listM);
    try{
        for (int i = 0; i < listM.GetLength(); i++){
            if (listT.Get(i) != listM.Get(i) ){
                throw "ERROR: LinkedList constructructor by the same class LinkedList";
            }
        }
        cout<<"Test: 'testCnstrByLinkedList' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
void testLlGetFirstValue(){
    try{
        int a[20] = {10,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
        LinkedList<int> listT(a,20);
        int n = 10;
        if(n != listT.GetFirstValue() ){
            throw "ERROR: LinkedList Get first value";
        }
        cout<<"Test: 'testGetFirstValue' complete"<<'\n'<<endl;;
    }
    catch(const char *exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testLlGetLastValue(){
    try{
        int a[20] = {10,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,99};
        LinkedList<int> listT(a,20);
        int n = 99;
        if(n != listT.GetLastValue() ){
            throw "ERROR: LinkedList Get last value";
        }
        cout<<"Test: 'testGetLastValue' complete"<<'\n'<<endl;
    }
    catch(const char *exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testLlGetValueByIndex(){
    try{
        int a[20] = {0,1,0,2,0,3,0,4,0,99,0,6,0,7,0,8,0,9,0,10};
        LinkedList<int> listT(a,20);
        int n = 99;
        if(n != listT.Get(9) ){
            throw "ERROR: LinkedList Get value by index";
        }
        cout<<"Test: 'testGetValueByIndex' complete"<<'\n'<<endl;
    }
    catch(const char *exception){
        cout<<exception<<'\n'<<endl;
    }
}
void testLlAppend(){
    try{
        int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
        LinkedList<int> listT(a,20);
        int n = 99;
        listT.Append(n);
        if (n != listT.GetLastValue() ){
            throw "ERROR: LinkedList Append";
        }
        cout<<"Test: 'testAppend' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
void testLlPrepend(){
    try{
        int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
        LinkedList<int> listT(a,20);
        int n = 99;
        listT.Prepend(n);
        if (n != listT.GetFirstValue() ){
            throw "ERROR: LinkedList Prepend";
        }
        cout<<"Test: 'testPrepend' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testLlInsertAt(){
    try{
        int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
        LinkedList<int> listT(a,20);
        listT.InsertAt(99, 10);
        if (listT.Get(10) != 99){
            throw "ERROR: LinkedList InsertAt";
        }
        cout<<"Test: 'testInsertAt' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testLlSubList(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    LinkedList<int> listM(a,20);
    LinkedList<int> listT;
    listT = listM.GetSubList(0, 10);
    try{
        for (int i = 0; i < 11; i++){
            if (a[i] != listT.Get(i)){
                throw "ERROR: LinkedList GetSubList";
            }
        }
        cout<<"Test: 'testSubList' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

///
///
void testLlAllCnstr(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    LinkedList<int> listT(a,20);
    
    LinkedList<int> listM(listT);
    
    try{
        for (int i  = 0; i < 20; i++){
            if (a[i] != listT.Get(i) ){
                throw "ERROR: LinkedList constructor by array";
            }
            if (listM.Get(i) != listT.Get(i) ){
                throw "ERROR: LinkedList constructructor by the same class LinkedList";
            }
        }
        cout<<"Test: 'testCnstrByArr' complete"<<'\n'<<endl;
        cout<<"Test: 'testCnstrByLinkedList' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
///
///
void testLlAllGet(){
    try{
        int a[20] = {99,1,0,2,0,3,0,4,0,99,0,6,0,7,0,8,0,9,0,99};
        LinkedList<int> listT(a,20);
        int n = 99;
        if(n != listT.GetFirstValue() ){
            throw "ERROR: LinkedList Get first value";
        }
        cout<<"Test: 'testGetFirstValue' complete"<<'\n'<<endl;
        if(n != listT.GetLastValue() ){
            throw "ERROR: LinkedList Get last value";
        }
        cout<<"Test: 'testGetLastValue' complete"<<'\n'<<endl;
        if(n != listT.Get(9) ){
            throw "ERROR: LinkedList Get value by index";
        }
        cout<<"Test: 'testGetValueByIndex' complete"<<'\n'<<endl;
    }
    catch(const char *exception){
        cout<<exception<<'\n'<<endl;
    }
}
///
///
void testLlAllApPrIn(){
    try{
        int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
        LinkedList<int> listT(a,20);
        int n = 99;
        listT.Append(n);
        listT.Prepend(n);
        listT.InsertAt(n, 10);
        if (n != listT.GetFirstValue() ){
            throw "ERROR: LinkedList Prepend";
        }
        cout<<"Test: 'testPrepend' complete"<<'\n'<<endl;
        if (n != listT.GetFirstValue() ){
            throw "ERROR: LinkedList Prepend";
        }
        cout<<"Test: 'testPrepend' complete"<<'\n'<<endl;
        if (listT.Get(10) != 99){
            throw "ERROR: LinkedList InsertAt";
        }
        cout<<"Test: 'testInsertAt' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
///
///

void AllLinkedListTests(){
//    testLlCnstrByArray();
//    testLlCnstrByLinkedList();
//    testLlGetFirstValue();
//    testLlGetLastValue();
//    testLlGetValueByIndex();
//    testLlAppend();
//    testLlPrepend();
//    testLlInsertAt();
    testLlAllCnstr();
    testLlAllGet();
    testLlAllApPrIn();
    testLlSubList();
}
//
//                                DynamicArray tests
void testDaCheckSize(){
    int size = 2;
    DynamicArray<int> arrT(size);
    try{
        if (size != arrT.GetSize()){
            throw "ERROR: check size";
        }
        cout<<"Test: 'DynamicArrayTestCheckSize' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
void testDaCnstrByArray(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    DynamicArray<int> arrT(a,20);
    try{
        for (int i = 0; i < 20; i++){
            if ( a[i] != arrT.Get(i) ){
                throw "ERROR: DynamicArray constructor by array";
            }
        }
        cout<<"Test: 'testDaCnstrByArray' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
void testDaCnstrByDynamicArray(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    DynamicArray<int> arrM(a,20);
    DynamicArray<int> arrT(arrM);
    try{
        for (int i = 0; i < arrM.GetSize(); i++){
            if (arrM.Get(i) !=  arrT.Get(i) ){
                throw "ERROR: DynamicArray constructor by copy the same class";
            }
        }
        cout<<"Test: 'testDaCnstrByDynamicArray' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testDaCnstrByArrayInterval(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    DynamicArray<int> arrT(a,1, 10);
    try{
        for (int i = 0; i < 10; i++){
            if (a[i] != arrT.Get(i) ){
                throw "ERROR: DynamicArray constructor by copy array interval";
            }
        }
        cout<<"Test: 'testDaCnstrByArrayInterval' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
void testDaCnstrByDynamicArrayInterval(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    DynamicArray<int> arrM(a,20);
    
    DynamicArray<int> arrT(arrM,1,10);
    try{
        for (int i = 0; i < 10; i++){
            if ( a[i] != arrT.Get(i) ){
                throw "ERROR: DynamicArray constructor by copy the smae class by interval";
            }
        }
        cout<<"Test: 'testDaCnstrByDynamicArrayInterval' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testDaGetValueByIndex(){
    int a[20] = {0,1,0,2,0,3,0,4,0,99,0,6,0,7,0,8,0,9,0,10};
    DynamicArray<int> arrM(a,20);
    int n = 99;
    try{
        if ( n != arrM.Get(9) ){
            throw "ERROR: DynamicArray get value by index";
        }
        cout<<"Test: 'testDaGetValueByIndex' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }

}
///
///
void testDaAllCnstr(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    DynamicArray<int> arrT(a,20);
    
    DynamicArray<int> arrT2(arrT);
    
    DynamicArray<int> arrT3(a,1, 10);
    
    DynamicArray<int> arrT4(arrT,1,10);
    try{
        for (int i = 0; i < 20; i++){
            if ( a[i] != arrT.Get(i) ){
                throw "ERROR: DynamicArray constructor by array";
            }
            if (arrT.Get(i) !=  arrT2.Get(i) ){
                throw "ERROR: DynamicArray constructor by copy the same class";
            }
            if (i < 10 && a[i] != arrT3.Get(i) ){
                throw "ERROR: DynamicArray constructor by copy array interval";
            }
            if ( i < 10 && a[i] != arrT4.Get(i) ){
                throw "ERROR: DynamicArray constructor by copy the same class by interval";
            }
        }
        cout<<"Test: 'testDaCnstrByArray' complete"<<'\n'<<endl;
        cout<<"Test: 'testDaCnstrByDynamicArray' complete"<<'\n'<<endl;
        cout<<"Test: 'testDaCnstrByArrayInterval' complete"<<'\n'<<endl;
        cout<<"Test: 'testDaCnstrByDynamicArrayInterval' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
///
///
///
///

///
///


void AllDynamicArrayTests(){
    testDaCheckSize();
    //testDaCnstrByArray();
    //testDaCnstrByDynamicArray();
    //testDaCnstrByArrayInterval();
    //testDaCnstrByDynamicArrayInterval();
    testDaAllCnstr();
    testDaGetValueByIndex();
}

//
//      ArraySequence
//

void testAsCheckSize(){
    int size = 5;
    ArraySequence<int> arrT(size);
    try{
        if (size != arrT.GetLength() ){
            throw "ERROR: check size";
        }
        cout<<"Test: 'testAsCheckSize' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
    
}

void testAsCnstrByArray(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    ArraySequence<int> arrT(a,20);
    try{
        for (int i = 0; i < 20; i++){
            if ( a[i] != arrT.Get(i) ){
                throw "ERROR: ArraySequence constructor by array";
            }
        }
        cout<<"Test: 'testAsCnstrByArray' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testAsCnstrByDynamicArray(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    DynamicArray<int> arrT(a, 20);
    ArraySequence<int> arrM(arrT, arrT.GetSize());
    try{
        for (int i = 0; i < 20; i++){
            if ( arrT.Get(i) != arrM.Get(i) ){
                throw "ERROR: ArraySequence constructor by DynamicArray";
            }
        }
        cout<<"Test: 'testAsCnstrByDynamicArray' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testAsCnstrByArrayInterval(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    ArraySequence<int> arrM(a,10,20);
    int j = 0;
    try{
        for (int i = 9; i < 20; i++){
            if ( a[i] != arrM.Get(j++) ){
                throw "ERROR: ArraySequence constructor by array interval";
            }
        }
        cout<<"Test: 'testAsCnstrByArrayInterval' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testAsCnstrByDynamicArrayInterval(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    DynamicArray<int> arrT(a, 20);
    ArraySequence<int> arrM(arrT, 10,20);
    int j = 0;
    try{
        for (int i = 9; i < 20; i++){
            if ( arrT.Get(i) != arrM.Get(j++) ){
                throw "ERROR: ArraySequence constructor by DynamicArray interval";
            }
        }
        cout<<"Test: 'testAsCnstrByDynamicArrayInterval' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
void testAsGetFirstValue(){
    int a[20] = {99,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    ArraySequence<int> arrM(a,20);
    int n = 99;
    try{
        if ( n != arrM.GetFirst() ){
            throw "ERROR: ArraySequence get first value";
        }
        cout<<"Test: 'testAsGetFirstValue' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
void testAsGetLastValue(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,99};
    ArraySequence<int> arrM(a,20);
    int n = 99;
    try{
        if ( n != arrM.GetLast() ){
                throw "ERROR: ArraySequence get last value";
        }
        cout<<"Test: 'testAsGetLastValue' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testGetValueByIndex(){
    int a[20] = {0,1,0,2,0,3,0,4,0,99,0,6,0,7,0,8,0,9,0,10};
    ArraySequence<int> arrM(a,20);
    int n = 99;
    try{
        if ( n != arrM.Get(9)){
            throw "ERROR: ArraySequence get value by index";
        }
        cout<<"Test: 'testAsGetValueByIndex' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
void testAsAppend(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    ArraySequence<int> arrM(a,20);
    arrM.Append(99);
    int n = 99;
    try{
        if ( n != arrM.GetLast()){
            throw "ERROR: ArraySequence apppend";
        }
        cout<<"Test: 'testAsAppend' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
    
void testAsPrepend(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    ArraySequence<int> arrM(a,20);
    arrM.Prepend(99);
    int n = 99;
    try{
        if ( n != arrM.GetFirst()){
            throw "ERROR: ArraySequence prepend";
        }
        cout<<"Test: 'testAsprepend' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
///
///
void testAsAllCnstr(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10}, j1 = 0, j2 = 0;
    ArraySequence<int> arrT(a,20);

    DynamicArray<int> arrTD(a, 20);
    ArraySequence<int> arrM(arrTD, arrTD.GetSize());
    
    ArraySequence<int> arrM2(a,10,20);
    
    ArraySequence<int> arrM3(arrTD, 10,20);
    
    try{
        for (int i = 0; i < 20; i++){
            if ( a[i] != arrT.Get(i) ){
                throw "ERROR: ArraySequence constructor by array";
            }
            if ( arrM.Get(i) != arrTD.Get(i) ){
                throw "ERROR: ArraySequence constructor by DynamicArray";
            }
            if ( i > 8 && a[i] != arrM2.Get(j1++) ){
                throw "ERROR: ArraySequence constructor by array interval";
            }
            if ( i > 8 && arrTD.Get(i) != arrM3.Get(j2++) ){
                throw "ERROR: ArraySequence constructor by DynamicArray interval";
            }
        }
        cout<<"Test: 'testAsCnstrByArray' complete"<<'\n'<<endl;
        
        cout<<"Test: 'testAsCnstrByDynamicArray' complete"<<'\n'<<endl;
    
        cout<<"Test: 'testAsCnstrByArrayInterval' complete"<<'\n'<<endl;
        
        cout<<"Test: 'testAsCnstrByDynamicArrayInterval' complete"<<'\n'<<endl;
        
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
///
///
void testAsAllGet(){
    int a[20] = {99,1,0,2,0,3,0,4,0,99,0,6,0,7,0,8,0,9,0,99};
    ArraySequence<int> arrM(a,20);
    int n = 99;
    try{
        if ( n != arrM.GetFirst() ){
            throw "ERROR: ArraySequence get first value";
        }
        cout<<"Test: 'testAsGetFirstValue' complete"<<'\n'<<endl;
        if ( n != arrM.GetLast() ){
            throw "ERROR: ArraySequence get last value";
        }
        cout<<"Test: 'testAsGetLastValue' complete"<<'\n'<<endl;
        if ( n != arrM.Get(9)){
            throw "ERROR: ArraySequence get value by index";
        }
        cout<<"Test: 'testAsGetValueByIndex' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
///
///
void testAsAllApPr(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    ArraySequence<int> arrM(a,20);
    arrM.Prepend(99);
    arrM.Append(99);
    int n = 99;
    try{
        if ( n != arrM.GetFirst()){
            throw "ERROR: ArraySequence prepend";
        }
        cout<<"Test: 'testAsprepend' complete"<<'\n'<<endl;
        if ( n != arrM.GetLast()){
            throw "ERROR: ArraySequence apppend";
        }
        cout<<"Test: 'testAsAppend' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
///
///



void AllArraySequenceTests(){
    testAsCheckSize();
    //testAsCnstrByArray();
    //testAsCnstrByDynamicArray();
    //testAsCnstrByArrayInterval();
    //testAsCnstrByDynamicArrayInterval();
    //testAsGetFirstValue();
    //testAsGetLastValue();
    //testAsAppend();
    //testAsPrepend();
    //testGetValueByIndex();
    testAsAllCnstr();
    testAsAllGet();
    testAsAllApPr();
}

//
//      LinkedListSequence
//
void testLlsCheckSize(){
    int size = 10;
    LinkedListSequence<int> listT(size);
    try{
        if (size != listT.GetLength() ){
            throw "ERROR: LinkedListSequence get length";
        }
        cout<<"Test: 'testLlsCheckSize' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testLlsCnstrByArray(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    LinkedListSequence<int> listT(a, 20);
    try{
        for (int i  = 0; i < 20; i++){
            if (a[i] != listT.Get(i) ){
                throw "ERROR: LinkedListSequence constructor by array";
            }
        }
        cout<<"Test: 'testLlsCnstrByArray' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
void testLlsCnstrByLL(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    LinkedList<int> listT(a,20);
    LinkedListSequence<int> listM(listT);
    try{
        for (int i  = 0; i < 20; i++){
            if (listT.Get(i)!= listM.Get(i) ){
                throw "ERROR: LinkedListSequence constructor by LinkedList";
            }
        }
        cout<<"Test: 'testLlsCnstrByLL' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
void testLlsCnstrByDymaicArray(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    DynamicArray<int> arrT(a,20);
    LinkedListSequence<int> listT(arrT);
    try{
        for (int i  = 0; i < 20; i++){
            if (arrT.Get(i) != listT.Get(i) ){
                throw "ERROR: LinkedListSequence constructor by DynamicArray";
            }
        }
        cout<<"Test: 'testLlsCnstrByDynamicArray' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testLlsGetFirstValue(){
    int a[20] = {99,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    LinkedListSequence<int> listT(a,20);
    int n = 99;
    try{
        if ( n != listT.GetFirst() ){
            throw "ERROR: LinkedListSequence get first value";
        }
        cout<<"Test: 'testLlsGetFirstValue' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
void testLlsGetLastValue(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,99};
    LinkedListSequence<int> listT(a,20);
    int n = 99;
    try{
        if (n != listT.GetLast() ){
            throw "ERROR: LinkedListSequence get last value";
        }
        cout<<"Test: 'testLlsgetLastValue' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }

}
void testLlsGetValueByIndex(){
    int a[20] = {0,1,0,2,0,3,0,4,0,99,0,6,0,7,0,8,0,9,0,10};
    LinkedListSequence<int> listT(a,20);
    int n = 99;
    try{
        if (n != listT.Get(9) ){
            throw "ERROR: LinkedListSequence get value by index";
        }
        cout<<"Test: 'testLlGetValueByIndex' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testLlsAppend(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    LinkedListSequence<int> listT(a,20);
    int n = 99;
    listT.Append(n);
    try{
        if (n != listT.GetLast() ){
            throw "ERROR: LinkedListSequence append";
        }
        cout<<"Test: 'testLlsAppend' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testLlsPrepend(){
    int a[20] = {99,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    LinkedListSequence<int> listT(a,20);
    int n = 99;
    listT.Prepend(n);
    try{
        if (n != listT.GetFirst() ){
            throw "ERROR: LinkedListSequence prepend";
        }
        cout<<"Test: 'testLlsPrepend' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}

void testLlsInsertAt(){
    int a[20] = {99,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    LinkedListSequence<int> listT(a,20);
    int n = 99;
    listT.InsertAt(n, 9);
    try{
        if (n != listT.Get(9)){
            throw "ERROR: LinkedListSequence insert value by index";
        }
        cout<<"Test: 'testLlsInsertAt' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
///
///
void testLlsAllCnstr(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};

    LinkedListSequence<int> listT(a, 20);
    
    LinkedListSequence<int> listM(listT);
    
    DynamicArray<int> arrT(a,20);
    LinkedListSequence<int> listT2(arrT);
    
    try{
        for (int i  = 0; i < 20; i++){
            if (arrT.Get(i) != listT.Get(i) ){
                throw "ERROR: LinkedListSequence constructor by DynamicArray";
            }
            if (a[i] != listT2.Get(i) ){
                throw "ERROR: LinkedListSequence constructor by array";
            }
            if (listT.Get(i)!= listM.Get(i) ){
                throw "ERROR: LinkedListSequence constructor by LinkedList";
            }
        }
        cout<<"Test: 'testLlsCnstrByArray' complete"<<'\n'<<endl;
        cout<<"Test: 'testLlsCnstrByLL' complete"<<'\n'<<endl;
        cout<<"Test: 'testLlsCnstrByDynamic Array' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
///
///
void testLlsAllGet(){
    int a[20] = {99,1,0,2,0,3,0,4,0,99,0,6,0,7,0,8,0,9,0,99};
    LinkedListSequence<int> listT(a,20);
    
    int n = 99;
    try{
        if ( n != listT.GetFirst() ){
            throw "ERROR: LinkedListSequence get first value";
        }
        cout<<"Test: 'testLlsGetFirstValue' complete"<<'\n'<<endl;
        if (n != listT.GetLast() ){
            throw "ERROR: LinkedListSequence get last value";
        }
        cout<<"Test: 'testLlsgetLastValue' complete"<<'\n'<<endl;
        
        if (n != listT.Get(9) ){
            throw "ERROR: LinkedListSequence get value by index";
        }
        cout<<"Test: 'testLlGetValueByIndex' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
///
///
void testLlsAllApPrIn(){
    int a[20] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10};
    LinkedListSequence<int> listT(a,20);
    int n = 99;
    listT.Append(n);
    listT.Prepend(n);
    listT.InsertAt(n, 9);
    try{
        if (n != listT.GetLast() ){
            throw "ERROR: LinkedListSequence append";
        }
        cout<<"Test: 'testLlsAppend' complete"<<'\n'<<endl;
        if (n != listT.GetFirst() ){
            throw "ERROR: LinkedListSequence prepend";
        }
        cout<<"Test: 'testLlsPrepend' complete"<<'\n'<<endl;
        if (n != listT.Get(9)){
            throw "ERROR: LinkedListSequence insert value by index";
        }
        cout<<"Test: 'testLlsInsertAt' complete"<<'\n'<<endl;
    }
    catch(const char* exception){
        cout<<exception<<'\n'<<endl;
    }
}
///
///

///
///
void AllLinkedListSequenceTests(){
    testLlsCheckSize();
    //testLlsCnstrByArray();
    //testLlsCnstrByLL();
    //testLlsCnstrByDa();
    //testLlsGetFirstValue();
    //testLlsGetLastValue();
    //testLlsGetValueByIndex();
    //testLlsAppend();
    //testLlsPrepend();
    //testLlsInsertAt();
    testLlsAllCnstr();
    testLlsAllGet();
    testLlsAllApPrIn();
}

//
//      Matrix Tests
//

void testMatrixGet(){
    int x = 3, y = 3;
    Matrix<ArraySequence<int>,int> matrix(x,y);
    try{
        
    }
    catch(const char *exception){}
}
void testMatrixGetR(){
    int x = 3, y = 3;
    Matrix<ArraySequence<int>,int> matrix(x,y);
    try{
        
    }
    catch(const char *exception){}
}
void testMatrixGetC(){
    int x = 3, y = 3;
    Matrix<ArraySequence<int>,int> matrix(x,y);
    try{}
    catch(const char *exception){}
    
}

void testMatrixSet(){
    int x = 3, y = 3;
    Matrix<ArraySequence<int>,int> matrix(x,y);
    try{}
    catch(const char *exception){}
}
void testMatrixSetR(){
    int x = 3, y = 3;
    Matrix<ArraySequence<int>,int> matrix(x,y);
    try{}
    catch(const char *exception){}
}
void testMatrixSetC(){
    int x = 3, y = 3;
    Matrix<ArraySequence<int>,int> matrix(x,y);
    try{}
    catch(const char *exception){}
}

void AllMatrixTests(){
    testMatrixGet();
    testMatrixGetR();
    testMatrixGetC();
    testMatrixSet();
    testMatrixSetR();
    testMatrixSetR();
    testMatrixSetC();
}
//
//      All Tests
//

void AllTests(){
    cout<<"DynamicArray tests"<<'\n'<<endl;
    AllDynamicArrayTests();
    cout<<endl;
    
    cout<<"LinkedList tests"<<'\n'<<endl;
    AllLinkedListTests();
    cout<<endl;
    
    cout<<"ArraySequence tests"<<'\n'<<endl;
    AllArraySequenceTests();
    cout<<endl;
    
    cout<<"LinkedListSequence tests"<<'\n'<<endl;
    AllLinkedListSequenceTests();
    cout<<endl;
    
    cout<<"Matrix tests"<<'\n'<<endl;
    AllMatrixTests();
    cout<<endl;
}
