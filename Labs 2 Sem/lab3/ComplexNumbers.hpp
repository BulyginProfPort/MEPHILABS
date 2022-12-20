//
//  Complex Numbers.hpp
//  lab3
//
//  Created by Фёдор Булыгин on 19.05.2022.
//

#ifndef ComplexNumbers_hpp
#define ComplexNumbers_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
class Complex {
private:
    int real;
    int imaginary;
public:
    //CONSTRUCTORS
    Complex(){
        real = 0;
        imaginary = 0;
    }
    
    Complex (int newReal, int Im){
        real = newReal;
        imaginary = Im;
    }
    
    Complex (const Complex &a){
        real = a.real;
        imaginary = a.imaginary;
    }
    
    //GETS
    int GetReal(){
        return real;
    }
    int GetIm(){
        return imaginary;
    }
    //SETS
    void setReal(int newReal){
        real = newReal;
    }
    void setIm(int newIm){
        imaginary = newIm;
    }
    
    //OPERATORS OVERLOADING
    friend std::ostream& operator << (std::ostream &os,  Complex num){
        return os << num.real << "+(" << num.imaginary << ")i" << std::endl;
    }
    friend std::istream& operator >> (std::istream &in,  Complex &b){
        return in >> b.real >> b.imaginary;
    }
    
    Complex operator * (const class Complex b){
        return Complex(real * b.real - imaginary * b.imaginary, real * b.imaginary + imaginary * b.real);
    }
    void operator = (const class Complex b){
        real = b.real;
        imaginary = b.imaginary;
    }
    bool operator == (const class Complex b){
        if ( (real == b.real) && (imaginary == b.imaginary) ){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator > (const class Complex b){
        if (sqrt(pow(real,2)+pow(imaginary,2)) > sqrt(pow(b.real,2)+pow(b.imaginary,2))){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator < (const class Complex b){
        if (sqrt(pow(real,2)+pow(imaginary,2)) < sqrt(pow(b.real,2)+pow(b.imaginary,2))){
            return true;
        }
        else{
            return false;
        }
    }
    
    ~Complex(){}
    
};


#endif /* ComplexNumbers_hpp */
