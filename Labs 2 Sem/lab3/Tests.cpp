//
//  Tests.cpp
//  lab3
//
//  Created by Фёдор Булыгин on 20.05.2022.
//

#include "Tests.hpp"
#include "Tree.hpp"
#include "Person.hpp"
#include "ComplexNumbers.hpp"
std::string byPass[6] = {"LeftRootRight",
                         "RightLeftRoot",
                         "RightRootLeft",
                         "LeftRightRoot",
                         "RootRightLeft",
                         "RootLeftRight"
                         };

///FUNCTIONS FOR <MAP> <WHERE>
bool onlyNegativeIntNum(int a){
    if (a < 0 ){
        return true;
    }
    else{
        return false;
    }

}
bool CmplxNum(class Complex a){
    class Complex b(3,1);
    if (a > b ){
        return true;
    }
    else{
        return false;
    }

}
bool PersonNum(class Person a){
    class Person b(a);
    b.setAge(35);
    if (a > b){
        return true;
    }
    else{
        return false;
    }
}
int quadInt(int a){
    return a*a;
}

Complex quadCmplx(Complex a){
    class Complex b = a*a;
    a = b;
    return a;
}
Person quadPerson(Person a){
    a.setAge(a.GetAge() * a.GetAge());
    return a;
}

///TESTS FOR INT

bool testMapInt(){
    Tree<int> tree1;
    tree1.add(0);
    tree1.add(15);
    tree1.add(-13);
    tree1.add(19);
    tree1.add(24);
    Tree<int> tree2;
    tree2.add(0);
    tree2.add(225);
    tree2.add(169);
    tree2.add(361);
    tree2.add(576);
    Tree<int> tree3;
    
    tree1.map(quadInt, tree3);
    if (tree3 == tree2){
        cout<<"Complete testMapInt"<<endl;
    }
    return (tree3 == tree2);
}


bool testWhereInt(){
    Tree<int> tree1;
    tree1.add(10);
    tree1.add(-10);
    tree1.add(0);
    tree1.add(-15);
    tree1.add(1000);
    
    Tree<int> tree2;
    tree2.add(-10);
    tree2.add(-15);
    
    Tree<int> tree3;
    tree1.where(onlyNegativeIntNum, tree3);
    if (tree3 == tree2){
        cout<<"Complete testWhereInt"<<endl;
    }
    return (tree3 == tree2);
}
///                TREE1
///                   0
///          -25      |       15
///           |       |   3    |    55

///                 TREE 2
///                  125
///          -169     |         2679
///   -576     |      |   361    |
///


///                         TREE 3
///                            0
///                 -25        |        15
///         -169      |        |   3    |     55
///   -576    |                |              |      125
///                                                  |      2679
///                                                    361     |

bool testMergeInt(){
    Tree<int> tree1;
    tree1.add(0);
    tree1.add(15);
    tree1.add(-25);
    tree1.add(3);
    tree1.add(55);
   
    Tree<int> tree2;
    tree2.add(125);
    tree2.add(2679);
    tree2.add(-169);
    tree2.add(361);
    tree2.add(-576);
    
    Tree<int> tree3;
    tree3.add(0);
    tree3.add(15);
    tree3.add(-25);
    tree3.add(3);
    tree3.add(55);
    tree3.add(125);
    tree3.add(2679);
    tree3.add(-169);
    tree3.add(361);
    tree3.add(-576);
    
    tree2.merge(tree1);
    if (tree3 == tree1){
        cout<<"Complete testMergeInt"<<endl;
    }
    return (tree3 == tree1);
}

bool testExtractionInt(){
    Tree<int> tree1;
    tree1.add(3);
    tree1.add(8);
    tree1.add(-3);
    tree1.add(-19);
    tree1.add(32);
    tree1.add(25);
    Tree<int> tree2;
    tree2.add(32);
    tree2.add(25);
    
    Tree<int> tree3;
    tree1.extraction(32, tree3);
    if (tree3 == tree2){
        cout<<"Complete testExtractionInt"<<endl;
    }
    return (tree3 == tree2);
}

//TESTS FOR CLASS COMPLEX
bool testMapCmplx(){
    class Complex n11(-1,-1),n21(0,2),
                  n12(2,-4), n22(-12,-16),
                  n13(-3,5), n23(-16,-30),
                  n14(3,1),  n24(8,6),
                  n15(3,8),  n25(-55,48);
    Tree<class Complex> tree1;
    tree1.add(n11);
    tree1.add(n12);
    tree1.add(n13);
    tree1.add(n14);
    tree1.add(n15);
    Tree<class Complex> tree2;
    tree2.add(n21);
    tree2.add(n22);
    tree2.add(n23);
    tree2.add(n24);
    tree2.add(n25);
    Tree<class Complex> tree3;
    tree1.map(quadCmplx, tree3);
    if (tree3 == tree2){
        cout<<"Complete testMapCmplx"<<endl;
    }
    return (tree3 == tree2);

}


bool testWhereCmplx(){
    class Complex n11(-1,-1),
                  n12(2,-4), n21(2,-4),
                  n13(-3,5), n22(-3,5),
                  n14(3,1),
                  n15(3,8),  n23(3,8);
    Tree<class Complex> tree1;
    tree1.add(n11);
    tree1.add(n12);
    tree1.add(n13);
    tree1.add(n14);
    tree1.add(n15);
    Tree<class Complex> tree2;
    tree2.add(n21);
    tree2.add(n22);
    tree2.add(n23);

    Tree<class Complex> tree3;
    
    tree1.where(CmplxNum, tree3);
    if (tree3 == tree2){
        cout<<"Complete testWhereCmplx"<<endl;
    }
    return (tree3 == tree2);
}
///                TREE1
///                 (-1,-1)
///          -25      |       15
///           |       |   3    |    55

///                 TREE 2
///                  125
///          -169     |         2679
///   -576     |      |   361    |
///


///                         TREE 3
///                            0
///                 -25        |        15
///         -169      |        |   3    |     55
///   -576    |                |              |      125
///                                                  |      2679
///                                                    361     |


bool testMergeCmplx(){
    class Complex n11(-1,-1),n21(0,2),
                  n12(2,-4), n22(-12,-16),
                  n13(-3,5), n23(-16,-30),
                  n14(3,1),  n24(8,6),
                  n15(3,8),  n25(-55,48);
    Tree<class Complex> tree1;
    tree1.add(n11);
    tree1.add(n12);
    tree1.add(n13);
    tree1.add(n14);
    tree1.add(n15);
    Tree<class Complex> tree2;
    tree2.add(n21);
    tree2.add(n22);
    tree2.add(n23);
    tree2.add(n24);
    tree2.add(n25);
    
    Tree<class Complex> tree3;
    tree3.add(n11);
    tree3.add(n12);
    tree3.add(n13);
    tree3.add(n14);
    tree3.add(n15);
    tree3.add(n21);
    tree3.add(n22);
    tree3.add(n23);
    tree3.add(n24);
    tree3.add(n25);
    
    tree2.merge(tree1);
    if (tree3 == tree1){
        cout<<"Complete testMergeCmplx"<<endl;
    }
    return (tree3 == tree1);
}

bool testExtractionCmplx(){
    class Complex n11(-1,-1),
                  n12(2,-4),
                  n13(-3,5),
                  n14(3,1),
                  n15(3,8);
    Tree<class Complex> tree1;
    tree1.add(n11);
    tree1.add(n12);
    tree1.add(n13);
    tree1.add(n14);
    tree1.add(n15);
    Tree<class Complex> tree2;
    tree2.add(n12);
    tree2.add(n13);
    tree2.add(n14);
    tree2.add(n15);
    
    Tree<class Complex> tree3;
    tree1.extraction(n12, tree3);
    if (tree3 == tree2){
        cout<<"Complete testExtractionCmplx"<<endl;
    }
    return (tree3 == tree2);
}
//TESTS FOR CLASS PERSON
bool testMapPerson(){
    class Person n11(13),n21(169),
                  n12(14), n22(196),
                  n13(5), n23(25),
                  n14(3),  n24(9),
                  n15(21),  n25(441);
    Tree<class Person> tree1;
    tree1.add(n11);
    tree1.add(n12);
    tree1.add(n13);
    tree1.add(n14);
    tree1.add(n15);
    Tree<class Person> tree2;
    tree2.add(n21);
    tree2.add(n22);
    tree2.add(n23);
    tree2.add(n24);
    tree2.add(n25);
    Tree<class Person> tree3;
    tree1.map(quadPerson, tree3);
    if (tree3 == tree2){
        cout<<"Complete testMapPerson"<<endl;
    }
    return (tree3 == tree2);

}


bool testWherePerson(){
    class Person n11(56),n21(56),
                  n12(14),
                  n13(25),
                  n14(81),  n23(81),
                  n15(92),  n24(92);
    Tree<class Person> tree1;
    tree1.add(n11);
    tree1.add(n12);
    tree1.add(n13);
    tree1.add(n14);
    tree1.add(n15);
    Tree<class Person> tree2;
    tree2.add(n21);

    tree2.add(n23);
    tree2.add(n24);
    
    Tree<class Person> tree3;
    
    tree1.where(PersonNum, tree3);
    if (tree3 == tree2){
        cout<<"Complete testWherePerson"<<endl;
    }
    return (tree3 == tree2);
}

bool testMergePerson(){
    class Person n11(13),n21(169),
                  n12(14), n22(196),
                  n13(5), n23(25),
                  n14(3),  n24(9),
                  n15(21),  n25(441);
    Tree<class Person> tree1;
    tree1.add(n11);
    tree1.add(n12);
    tree1.add(n13);
    tree1.add(n14);
    tree1.add(n15);
    Tree<class Person> tree2;
    tree2.add(n21);
    tree2.add(n22);
    tree2.add(n23);
    tree2.add(n24);
    tree2.add(n25);
    
    Tree<class Person> tree3;
    tree3.add(n11);
    tree3.add(n12);
    tree3.add(n13);
    tree3.add(n14);
    tree3.add(n15);
    tree3.add(n21);
    tree3.add(n22);
    tree3.add(n23);
    tree3.add(n24);
    tree3.add(n25);
    
    tree2.merge(tree1);
    if (tree3 == tree1){
        cout<<"Complete testMergePerson"<<endl;
    }
    return (tree3 == tree1);
}

//AllTests
void AllTests(){
    if (testMapInt() && testWhereInt() && testMergeInt() && testExtractionInt() && testMapCmplx() && testWhereCmplx() && testMergeCmplx() && testExtractionCmplx() && testMapPerson() && testWherePerson() && testMergePerson() ){
        cout << "Tests is completed successfully" << endl;
    }
    else{
        cout << "Fail" << endl;
    }
}
