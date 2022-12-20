#include <iostream>
#include <ctime>
#include "ComplexNumbers.hpp"
#include "Person.hpp"
#include "Tree.hpp"
#include "Tests.hpp"

int main() {
    time(NULL);
    std::string byPass[6] = {
                             "LeftRootRight",
                             "RightLeftRoot",
                             "RightRootLeft",
                             "LeftRightRoot",
                             "RootRightLeft",
                             "RootLeftRight"
                            };
    while (1){
        char c[5] = {'\0','\0','\0','\0','\0'};
    Back1:
        //----------------------------back1
        printf("\n            Welcome!\n"
               "1 - Int\n"
               "2 - class Complex\n"
               "3 - class Person\n"
               "4 - Test menu\n"
               "5 - About the program\n"
               "6 - Exit\n");
        cin >> c[0];
        getchar();
        
        switch (c[0]) {
            case '1':
            {
                Tree<int> A;
                printf("\n\nYou should create a tree\n"
                "Add N element (N - Number of elements)\n");
                int N;
                cin >> N;
                getchar();
                time_t startTime = clock();
                for (int i = 0; i < N; ++i){
                    int x = rand()%(N+1);
                    A.add(x);
                }
                time_t endTime = clock();
                cout << endl;
                time_t resTime = endTime - startTime;
                //A.print(byPass[5]);
                cout << endl;
                cout <<"Time: "<< resTime/1000.0<<endl;
            Repeat1:
                printf("1 - map (quad)\n"
                       "2 - where (All elements < 0)\n"
                       "3 - merger\n"
                       "4 - search element of tree\n"
                       "5 - Show a tree\n"
                       "6 - Filing\n"
                       "7 - Back\n"
                       "0 - Exit\n");
                cin >> c[1];
                getchar();
                switch (c[1]) {
                    case '1':
                    {
                        Tree<int> B;
                        int startTime = clock();
                        A.map(quadInt, B);
                        int endTime = clock();
                        int resTime = endTime - startTime;
                        B.print(byPass[5]);
                        cout<<endl;
                        cout <<"Time: "<< resTime/1000.0<<endl;
                        
                        goto Repeat1;
                    }
                        break;
                    case '2':
                    {
                        Tree<int> B;
                        int startTime = clock();
                        A.where(onlyNegativeIntNum, B);
                        int endTime = clock();
                        int resTime = endTime - startTime;
                        B.print(byPass[5]);
                        cout <<"Time: "<< resTime/1000.0<<endl;
                        cout<<endl;
                        goto Repeat1;
                    }
                        break;
                    case '3':
                    {
                        Tree<int> B;
                        int N;
                        printf("You should create a second tree\n"
                               "Add N elements. Enter N: ");
                        cin >> N;
                        getchar();
                        for (int i = 0; i < N; ++i){
                            int x = rand()%10+1;
                            B.add(x);
                        }
                        int startTime = clock();
                        B.merge(A);
                        int endTime = clock();
                        int resTime = endTime - startTime;
                        A.print(byPass[5]);
                        cout << endl;
                        cout <<"Time: "<< resTime/1000.0<<endl;
                        goto Repeat1;
                    }
                        break;
                    case '4':
                    {
                        int elem;
                        printf("Eneter element which you want to find\n"
                                "elem: ");
                        cin>>elem;
                        getchar();
                        int startTime = clock();
                        if (A.searchElement(elem) == true){
                            cout << "YES!" << endl;
                        }
                        else{
                            cout << "NO!" << endl;
                            goto Repeat1;
                        }
                        int endTime = clock();
                        int resTime = endTime - startTime;
                        cout <<"Time: "<< resTime/1000.0<<endl;
                    }
                        break;
                    case '5':
                    {
                        printf("Choose the by pass option which which you want:\n"
                               "\t1. LeftRootRight\n"
                               "\t2. RightLeftRoot\n"
                               "\t3. RightRootLeft\n"
                               "\t4. LeftRightRoot\n"
                               "\t5. RootRightLeft\n"
                               "\t6. RootLeftRight\n");
                        int k;
                        cin >> k;
                        printf("        Tree\n");
                        if(k == 1){
                            A.print(byPass[0]);
                        }
                        if(k == 2){
                            A.print(byPass[1]);
                        }
                        if(k == 3){
                            A.print(byPass[2]);
                        }
                        if(k == 4){
                            A.print(byPass[3]);
                        }
                        if(k == 5){
                            A.print(byPass[4]);
                        }
                        if(k == 6){
                            A.print(byPass[5]);
                        }
                        cout << endl << endl;
                        goto Repeat1;
                    }
                        break;
                    case '6':
                    {
                        int elem;
                        printf("Eneter element which you want to find\n"
                               "elem: ");
                        cin>>elem;
                        getchar();
                        int startTime = clock();
                        A.add(elem);
                        int endTime = clock();
                        int resTime = endTime - startTime;
                        cout <<"Time: "<< resTime/1000.0<<endl;
                        goto Repeat1;
                    }
                        break;
                    case '7':
                    {
                        //A.freetree_el();
                        cout << endl;
                        goto Back1;
                    }
                        break;
                    case '0':
                    {
                        return 0;
                    }
                        break;
                        
                    default:
                    {
                        cout << "Try again" << endl;
                        goto Repeat1;
                    }
                        break;
                }
            }
                break;
            case '2':
            {
                Tree <Complex> A;
                printf("\n\nYou should create a tree"
                "Add N elements.\nEnter N: ");
                int N;
                cin >> N;
                getchar();
                for (int i = 0; i < N; ++i){
                    Complex elem;
                    cin >> elem;
                    A.add(elem);
                }
                cout << endl;
                A.print(byPass[5]);
                cout << endl;
            Repeat2:
                printf("1 - map (quad)\n"
                       "2 - where\n"
                       "3 - merger\n"
                       "4 - search element\n"
                       "5 - Show a tree\n"
                       "6 - Filing\n"
                       "7 - Back\n"
                        "0 - Exit\n");
                cin >> c[2];
                getchar();
                switch (c[2]) {
                    case '1':
                    {
                        Tree <Complex> B;
                        A.map(quadCmplx,B);
                        B.print(byPass[5]);
                        goto Repeat2;
                    }
                        break;
                    case '2':
                    {
                        Tree <Complex> B1;
                        A.where(CmplxNum, B1);
                        B1.print(byPass[5]);
                        goto Repeat2;
                    }
                        break;
                    case '3':
                    {
                        printf("You should create a second tree\n"
                               "Add N elements. Enter N: ");
                        Tree <Complex> B;
                        int N;
                        cin >> N;
                        getchar();
                        for (int i = 0; i < N; ++i){
                            Complex elem;
                            cin >> elem;
                            B.add(elem);
                        }
                        B.merge(A);
                        cout << endl;
                        A.print(byPass[5]);
                        goto Repeat2;
                    }
                        break;
                    case '4':
                    {
                        printf("Enter the element\n");
                        Complex elem;
                        cin >> elem;
                        if (A.searchElement(elem) == true){
                            cout << "YES!" << endl;
                        }
                        else{
                            cout << "NO!" << endl;
                        }
                        goto Repeat2;
                    }
                        break;
                    case '5':
                    {
                        printf("Choose the by pass option which which you want:\n"
                               "\t1. LeftRootRight\n"
                               "\t2. RightLeftRoot\n"
                               "\t3. RightRootLeft\n"
                               "\t4. LeftRightRoot\n"
                               "\t5. RootRightLeft\n"
                               "\t6. RootLeftRight\n");
                        int k;
                        cin >> k;
                        printf("        Tree\n\n       ");
                        if(k == 1){
                            A.print(byPass[0]);
                        }
                        if(k == 2){
                            A.print(byPass[1]);
                        }
                        if(k == 3){
                            A.print(byPass[2]);
                        }
                        if(k == 4){
                            A.print(byPass[3]);
                        }
                        if(k == 5){
                            A.print(byPass[4]);
                        }
                        if(k == 6){
                            A.print(byPass[5]);
                        }
                        cout << endl << endl;
                        goto Repeat2;
                    }
                        break;
                    case '6':
                    {
                        printf("Enter the element\n");
                        Complex elem;
                        cin >> elem;
                        getchar();
                        A.add(elem);
                        goto Repeat2;
                    }
                        break;
                    case '7':
                    {
                        A.~Tree();
                        cout << endl;
                        goto Back1;
                    }
                        break;
                    case '0':
                    {
                        return 0;
                    }
                        break;
                    
                    default:
                    {
                        cout << "Try again" << endl;
                        goto Repeat2;
                    }
                        break;
                }
            }
                break;
            case '3':
            {
                Tree <Person> A;
                printf("\n\nYou should create a tree\n"
                       "Add N elements.\nEnter N: ");
                int N;
                cin >> N;
                getchar();
                for (int i = 0; i < N; ++i){
                    Person elem;
                    cin >> elem;
                    getchar();
                    A.add(elem);
                }
                cout << endl;
                A.print(byPass[5]);
                cout << endl;
                Repeat3:
                printf("\n1 - map (F(str) = str.substr(1, 3))\n"
                       "2 - merger\n"
                       "3 - where (All elemets)"
                       "4 - search element\n"
                       "5 - Show a tree\n"
                       "6 - Filing\n"
                       "7 - Back\n"
                       "0 - Exit\n");
                cin >> c[3];
                getchar();
                switch (c[3]) {
                    case '1':
                    {
                        Tree<Person> B;
                        A.map(quadPerson,B);
                        B.print(byPass[5]);
                        goto Repeat3;
                    }
                        break;
                    case '2':
                    {
                        cout << endl << "You should create a second tree" << endl;
                        cout << "Add N elements.\nEnter N: ";
                        Tree<Person> B;
                        int N;
                        cin >> N;
                        getchar();
                        for (int i = 0; i < N; ++i){
                            Person elem;
                            cin >> elem;
                            B.add(elem);
                        }
                        B.merge(A);
                        cout << endl;
                        A.print(byPass[5]);
                        goto Repeat3;
                    }
                        break;
                    case '3':
                        break;
                    case '4':
                    {
                        Tree<Person> B;
                        cout << "Enter the element: " << endl;
                        Person elem;
                        cin >> elem;
                        getchar();
                        if (A.searchElement(elem) == true){
                            cout << "YES!" << endl;
                        }
                        else{
                            cout << "NO!" << endl;
                        }
                        goto Repeat3;
                    }
                        break;
                    case '5':
                    {
                        printf("Choose the by pass option which which you want:\n"
                               "\t1. LeftRootRight\n"
                               "\t2. RightLeftRoot\n"
                               "\t3. RightRootLeft\n"
                               "\t4. LeftRightRoot\n"
                               "\t5. RootRightLeft\n"
                               "\t6. RootLeftRight\n");
                        int k;
                        cin >> k;
                        printf("        Tree\n\n       ");
                        if(k == 1){
                            A.print(byPass[0]);
                        }
                        if(k == 2){
                            A.print(byPass[1]);
                        }
                        if(k == 3){
                            A.print(byPass[2]);
                        }
                        if(k == 4){
                            A.print(byPass[3]);
                        }
                        if(k == 5){
                            A.print(byPass[4]);
                        }
                        if(k == 6){
                            A.print(byPass[5]);
                        }
                        cout << endl << endl;
                        goto Repeat3;
                    }
                        break;
                    case '6':
                    {
                        Person elem;
                        cin >> elem;
                        A.add(elem);
                        getchar();
                        goto Repeat3;
                    }
                        break;
                    case '7':
                    {
                        A.~Tree();
                        cout << endl;
                        goto Back1;
                    }
                        break;
                    case '0':
                    {
                        return 0;
                    }
                        break;
                    
                    default:
                    {
                        cout << "Try again" << endl;
                        goto Repeat3;
                    }
                        break;
                }
            }
                break;
            case '4':
            {
                AllTests();
                getchar();
                cout << endl;
            }
                break;
            case '5':
            {
                printf("\nThe program is a demonstration of a binary tree\n"
                       "About a ternary tree.\n"
                       "In computer science, a ternary tree is a tree data structure in which each node has at most three child nodes, usually distinguished as left and right. "
                       "Nodes with children are parent nodes, and child nodes may contain references to their parents. "
                       "Outside the tree, there is often a reference to the root node (the ancestor of all nodes), if it exists. "
                       "Any node in the data structure can be reached by starting at root node and repeatedly following references to either the left or right child.\n"
                       "\n                                22.05.2022\n"
                       "                                            Bulygin Fedor\n");
            }
                break;
            case '6':
            {
                return 0;
            }
                break;
            default:
            {
                cout << "Try again" << endl;
                goto Back1;
            }
                break;
        }

    }
    return 0;
}
