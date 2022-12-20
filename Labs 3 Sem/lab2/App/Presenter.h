//
// Created by Fedor Bulygin on 05.12.2022.
//

#ifndef LAB2_3_PRESENTER_H
#define LAB2_3_PRESENTER_H

#include <iostream>
#include "vector"
#include "../HashTable/HashTable.h"
#include "../Tasks/SubSequence/CountSubSequence.h"
#include "../Tasks/Packing/BagPacking.h"

class Presenter {
private:
    string s;
public:
    string findMostPopularSubSequence(string s);
    string BackPack(int k, int size);
};

#endif //LAB2_3_PRESENTER_H
