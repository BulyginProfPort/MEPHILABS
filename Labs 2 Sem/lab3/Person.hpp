//
//  Person.hpp
//  lab3
//
//  Created by Фёдор Булыгин on 19.05.2022.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>
class Person{
private:
    int age = 0;
    std::string FirstName;
    std::string MiddleName;
    std::string LastName;
public:
    //CONSTRUCTORS
    Person(){
        age = 1;
        FirstName = "Ivanov";
        MiddleName = "Ivan";
        LastName = "Ivanovich";

    }
    Person(int newAge){
        age = newAge;
        FirstName = "Ivanov";
        MiddleName = "Ivan";
        LastName = "Ivanovich";

    }
    Person(const Person &person){
        age = person.age;
        FirstName = person.FirstName;
        MiddleName = person.MiddleName;
        LastName = person.LastName;
        
    }
    //GET
    std::string getFirstName(){
        return FirstName;
    }
    std::string getMiddleName(){
        return MiddleName;
    }
    std::string getLastName(){
        return LastName;
    }
    int GetAge(){
        return age;
    }
    
    //SETS
    void setAge(int newAge){
        age = newAge;
    }
    void setFirstName(std::string &newFirstName){
        FirstName = newFirstName;
    }
    void setMiddleName(std::string &newMiddleName){
        MiddleName = newMiddleName;
    }
    void setLastName(std::string &newLastName){
        LastName = newLastName;
    }
    
    
    //OPERATORS OVERLOADING
    friend std::ostream& operator << (std::ostream &os,const Person &a){
        return os << a.LastName << " " << a.FirstName << " " << a.MiddleName << '\n' << "Age = "<< a.age <<std::endl;
    }
    friend std::istream& operator >>(std::istream &in,Person &a){
        return in >> a.age >> a.FirstName >> a.MiddleName >> a.LastName;
    }
    void operator = (const class Person b){
        age = b.age;
        FirstName = b.FirstName;
        MiddleName = b.MiddleName;
        LastName = b.LastName;

    }
    bool operator > (const class Person b){
        if (age > b.age){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator < (const class Person b){
        if (age < b.age){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator == (const class Person b){
        if  (  ( age == b.age ) && (FirstName == b.FirstName) && (MiddleName == b.MiddleName) && (LastName == b.LastName) ){
            return true;
        }
        else{
            return false;
        }
    }
};

#endif /* Person_hpp */
