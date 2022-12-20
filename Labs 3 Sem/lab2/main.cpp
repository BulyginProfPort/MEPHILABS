#include <iostream>
#include "HashTable/HashTable.h"
#include "Tasks/SubSequence/CountSubSequence.h"
#include "Tasks/Packing/BagPacking.h"


int main() {

    //ЗАДАЧА №1 (НАИБОЛЬШАЯ ПОДПОСЛЕДОВАТЕЛЬНОСТЬ)
    HashTable<std::string, vector<int> > dict(15);

    //std::string sqnce = "abaababaabaab$";
    std::string sqnce = "abbaabba";
    vector<std::string> indexes;

    Crochemore(dict, sqnce, indexes);
    std::cout << dict << endl;

    Sequence<std::string> arr[indexes.size()];

    for (int i  = 0 ; i <  indexes.size(); i++) {
        try {
            arr[i].name = dict.Get(indexes[i]).key;
            arr[i].count = dict.Get(indexes[i]).data;
        }
        catch (const std::out_of_range &oor) {
            std::cout<<oor.what()<<endl;
        }
    }

    std::sort(arr, arr + indexes.size(), cmp<std::string>);

    std::cout << "Результат" << endl;
    for (int i = 0; i < indexes.size(); i++)
    {
        std::cout << "cтрока: <" << arr[i].name << "> число вхождений: [" << arr[i].count << "]" << endl;
    }
    std::cout<<endl;

    //ЗАДАЧА №2 РЮКЗАК (ВАРИАНТ А)
    list<Item> items = { { 2, 100, 2*100, 40 }, { 2, 157, 2*157, 50 }, { 2, 99, 2 * 99, 100 }, { 2, 250, 2 * 250, 60 }, { 2, 150, 2 * 150, 30 }, { 2, 200, 2 * 200, 45 }, { 2, 100, 2 * 100, 40 } };

    int maxSize = 1300;
    Pack backpack( maxSize );
    Item BEST = backpack.find_best(items);
    std::cout << std::endl << "Best: " << backpack << std::endl;
}