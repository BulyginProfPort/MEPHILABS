#pragma once
#ifndef Tree_hpp
#define Tree_hpp
#include <iostream>
#include "List.hpp"
using namespace std;

template <class T>
class Tree{
private:
    List<T>* root = nullptr;
    int size;
    
public:
    //CONSTRUCTORS
    Tree(){
        root = nullptr;
        size = 0;
    }
    
    //GETS
    T getvalue(){
        return root->getValue();
    }
    int getSize(){
        return size;
    }
    void getString(std::string &byPass, T* &resultString){
        if (root){
            int i = 0;
            root->string(byPass, root, resultString, i);
        }
    }
    
    //SETS
    void setRoot(T data){
        root->setValue(data);
    }
    void setSize(int newSize){
        size = newSize;
    }
    void add(T value){
        root->add(value, root);
        size++;
    }
    
    //MAP WHERE MERGE
    void map(function<T(T)> f, Tree &nB){
        if (root){
            root->map(f, root, nB.root );
        }
    }
    void where(function<bool(T)> f, Tree &nB){
        if (root){
            root->where(f, root, nB.root );
        }
    }
    void merge(Tree &b){
        if (root){
            root->merge(root, b.root);
        }
    }
    void extraction(T value, Tree &a){
        if (root){
            root->extraction(root, a.root, value);
        }
    }
    
    //SEARCHERS
    bool searchElement(T data){
        if ( root->searchElement(data, root) ){
            cout<<"True"<<endl;
            return true;
        }
        else{
            cout<<"False"<<endl;
            return false;
        }
    }
    void print(std::string &byPass)const {
        if (root){
            root->print(byPass);
        }
    }
    
    //OPERATORS
    bool operator == ( class Tree<T> &b){
        if (root->equalityTree(root, b.root) ){
            return true;
        }
        else{
            return false;
        }
    }
    ~Tree(){
        if (root){
            root->freeTree(root);
        }
    }
};


#endif /* LinkedList_hpp */
