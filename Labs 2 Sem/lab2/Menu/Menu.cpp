//
// Created by Fedor Bulygin on 23.10.2022.
//
#include <iostream>

using namespace std;
void Menu(){
    printf(
            " ______________________________________________ \n"
            " ______________________________________________ \n"
            "||                  LAB 2                     ||\n"
            "||MENU:                                       ||\n"
            "||  General:                                  ||\n"
            "||    m = print menu                          ||\n"
            "||    q = stop this program                   ||\n"
            "\n"
            "||  ArraySequence:                            ||\n"
            "||    S = ArraySequence menu                  ||\n"
            "\n"
            "||  LinkedListSequence:                       ||\n"
            "||    L = LinkedLIstSequence menu             ||\n"
            "\n"
            "||  Matrix:                                   ||\n"
            "||    M = Matrix menu                         ||\n"
            "\n"
            "||  Tests:                                    ||\n"
            "||    T = Test menu                           ||\n"
            "||                                            ||\n"
            " ______________________________________________ \n"
            " ______________________________________________ \n"
    );

}
void TestsMenu(){
    printf(
            " ______________________________________________ \n"
            " ______________________________________________ \n"
            "||                  TEST'S MENU               ||\n"
            "||MENU:                                       ||\n"
            "||    General:                                ||\n"
            "||      m = print menu                        ||\n"
            "||      A = start all tests                   ||\n"
            "||      q = menu exit                         ||\n"
            "\n"
            "||    LinkedListSequence tests:               ||\n"
            "||      L = start all LinkedListSequence tests||\n"
            "\n"
            "||    ArraySequence tests:                    ||\n"
            "||      S = start all ArraySequence tests     ||\n"
            "\n"
            "||    DynamicArray tests:                     ||\n"
            "||      D = start all DynamicArray tests      ||\n"
            "\n"
            "||    LinkedList tests:                       ||\n"
            "||      l = start all LinkedList tests        ||\n"
            " ______________________________________________ \n"
            " ______________________________________________ \n"

    );
}
void LinkedListSequenceMenu(){
    printf(" ________________________________________________ \n"
           " ________________________________________________ \n"
           "||              LinkedListSequence              ||\n"
           "||MENU:                                         ||\n"
           "||    General:                                  ||\n"
           "\n"
           "||      I = insert new element                  ||\n"
           "||      D = Delete range of elements            ||\n"
           "||      S = Get slice of                        ||\n"
           "||      C = Concatenate                         ||\n"
           "\n"
           "||      p = print                               ||\n"
           "||      g = get element by index                ||\n"
           "||      q = menu exit                           ||\n"
           "\n"
           "||    LinkedListSequence tests:                 ||\n"
           "||      t = start all LinkedListSequence tests  ||\n"
           " ________________________________________________ \n"
           " ________________________________________________ \n"

    );
}
void ArraySequenceMenu(){
    printf(
            " ____________________________________________________ \n"
            " ____________________________________________________ \n"
            "||              ArraySequence                       ||\n"
            "||MENU:                                             ||\n"
            "||    General:                                      ||\n"
            "\n"
            "||      I = insert new element                      ||\n"
            "||      S = get slice                               ||\n"
            "||      C = concatenate                             ||\n"
            "||      D = delete range of ArraySequence elements  ||\n"
            "\n"
            "||      g = get element by index                    ||\n"
            "||      s = set element by index                    ||\n"
            "||      p = print                                   ||\n"
            "||      q = menu exit                               ||\n"
            "\n"
            "||    ArraySequence tests:                          ||\n"
            "||      t = start all ArraySequence tests           ||\n"
            " ____________________________________________________ \n"
            " ____________________________________________________ \n"
    );
}
void MatrixMenu(){
    printf(
            " ____________________________________________________ \n"
            " ____________________________________________________ \n"
            "||                     Matrix                       ||\n"
            "||MENU:                                             ||\n"
            "||    General:                                      ||\n"
            "\n"
            "||      s = Set Menu                                ||\n"
            "||      g = Get Menu                                ||\n"
            "\n"
            "||      S = Sum of 2 matrix                         ||\n"
            "||      M = Multi of 2 matrix                       ||\n"
            "||      p = print                                   ||\n"
            "||      q = menu exit                               ||\n"
            "\n"
            "||    Matrix tests:                                 ||\n"
            "||      t = start all Matrix tests                  ||\n"
            " ____________________________________________________ \n"
            " ____________________________________________________ \n"
    );
}
void SetMenu(){
    printf(
            " ____________________________________________________ \n"
            " ____________________________________________________ \n"
            "||                     Set Menu                     ||\n"
            "||MENU:                                             ||\n"
            "||    General:                                      ||\n"
            "\n"
            "||      1 = Set element by index                    ||\n"
            "||      2 = Set number of rows                      ||\n"
            "||      3 = Set number of columns                   ||\n"
            "||      4 = menu exit                               ||\n"
            " ____________________________________________________ \n"
            " ____________________________________________________ \n"
    );
}
void GetMenu(){
    printf(
            " ____________________________________________________ \n"
            " ____________________________________________________ \n"
            "||                    Get Menu                      ||\n"
            "||MENU:                                             ||\n"
            "||    General:                                      ||\n"
            "\n"
            "||      1 = Get element by index                    ||\n"
            "||      2 = Get row                                 ||\n"
            "||      3 = Get column                              ||\n"
            "||      4 = menu exit                               ||\n"
            " ____________________________________________________ \n"
            " ____________________________________________________ \n"
    );
}

void CheckNumSize(const char *arr, int &s, int size){
    s = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] != '\0'){
            s++;
        }
    }
}
int StrToInt(const char *s){
    int temp = 0; // число
    int i = 0;
    int sign = 0; // знак числа 0 - положительное, 1 — отрицательное
    if (s[i] == '-'){
        sign = 1;
        i++;
    }
    while (s[i] >= 0x30 && s[i] <= 0x39){
        temp = temp + (s[i] & 0x0F);
        temp = temp * 10;
        i++;
    }
    temp = temp / 10;
    if (sign == 1){
        temp = -temp;
    }
    return(temp);
}
void InputNumCheckInt(char* arr, int size, int &num){
    bool m = false;
    int s = 0;
    char a[11] = {"2147483647"};
    printf("Enter the number: ");
    getchar();
    cin.getline(arr, size);
    CheckNumSize(arr, s, size);
    while (s > 10){
        printf("\nERROR: Number is too big number for data type.\n"
               "Try enter the number again: ");
        memset(arr,'\0',20);
        cin.getline(arr, size);
        CheckNumSize(arr,s,size);
    }
    if (s < 10){
        m = true;
    }
    else if (s == 10){
        int i = 0;
        if (arr[i] > 2){
            throw "ERROR: Number is too big number for data type int";
        }
        else if (arr[i] < 2){
            m = true;
        }
        else if (arr[i] == 2){
            for (i = 0; i < 11; i++){
                if ( arr[i] <= int(a[i]) ){
                    m = true;
                }
                else{
                    throw "ERROR: Number is too big number for data type int";
                }
            }
        }
    }
    if (m){
        num = StrToInt(arr);
    }
}
void InputIndex(int length, int &index){
    cout<<"Write number of first index: ";
    cin>>index;
    while (index > length || index < 0){
        cout<<"Write number of first index: ";
        cin>>index;
    }
}
void InputIndexes(int length, int &firstIndex,int &lastIndex){
    cout<<"Write number of first index: ";
    cin>>firstIndex;
    cout<<"Write number of last index: ";
    cin>>lastIndex;
    while ( (firstIndex > length || firstIndex < 0) || (lastIndex > length || lastIndex < 0) ){
        printf("Oops, Index out of range! Write index where you want to insert number: ");
        cout<<"Write number of first index: ";
        cin>>firstIndex;
        cout<<"Write number of last index: ";
        cin>>lastIndex;
    }
}
