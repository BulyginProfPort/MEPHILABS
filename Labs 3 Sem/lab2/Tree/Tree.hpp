#pragma once
#ifndef Tree_hpp
#define Tree_hpp
#include <iostream>
using namespace std;

template <class T>
struct TreeNode{
    T data;
    TreeNode* left;
    TreeNode* right;
};

template <class T>
class Tree{
private:
    TreeNode<T>* root;
    int size;
    
public:
    //CONSTRUCTORS
    Tree(){
        root = nullptr;
        size = 0;
    }
    //GET
    int getSize(){
        return size;
    }
    //SET
    void setRoot(T data){
        root->setValue(data);
    }
    void setSize(int newSize){
        size = newSize;
    }

    //ADD ELEMENT IN TREE
    void add(T value_){
        if (root){
            if (value_ > root->value){
                if ( root->right){
                    add(value_, root->right);
                }
                else{
                    root->right = new struct TreeNode<T>;
                    root->right->value = value_;
                    root->right->left = root->right->right = nullptr;
                }
            }
            else if (value_ < root->value){
                if ( root->left){
                    add(value_,root->left);
                }
                else{
                    root->left = new struct TreeNode<T>;
                    root->left->value = value_;
                    root->left->left = root->left->right = nullptr;
                }
            }
            else if (value_ == root->value){
                return;
            }
        }
        else{
            root = new TreeNode<T>;
            root->value = value_;
            root->left = root->right = nullptr;
        }
        size++;
    }

    //MAP
    void map(function<T(T)> f, Tree &nB){
        if (root){
                nB->add(f(root->value), nB.root);
                map(f, root->right, nB.roo);
                map(f,root->left,nB.root);
            }
    }
    // WHERE
    void where(function<bool(T)> f, Tree &nB){
        if(root){
            if ( f(root->value) ){
                nB->add(root->value,nB);
            }
            where(f,root->left, nB);
            where(f, root->right, nB);
        }
    }
    // MERGE
    void merge(Tree &b){
        if  (root){
            b->add( root->getValue(), b );
            merge( root->left, b);
            merge( root->right,b);
        }
    }

    //SEARCHER
    bool searchElement(T data){
        if (root){
            if (data > root->value){
                return searchElement(data, root->right);
            }
            else if (data < root->value){
                return searchElement(data, root->left);
            }
            else if (data == root->value){
                cout<<"True"<<endl;
                return true;
            }
        }
        cout<<"False"<<endl;
        return false;
    }

    void print(std::string &byPass)const {

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
    //Free Tree
    void freeTree(TreeNode<T>* &list){
        if (list){
            freeTree( list->right);
            freeTree( list->left);
            delete list;
            list = nullptr;
        }
    }
    ~Tree(){
        freeTree(root);
    }
};


#endif /* Tree_hpp */
