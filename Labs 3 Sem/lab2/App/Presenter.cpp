//
// Created by Fedor Bulygin on 05.12.2022.
//

#include "Presenter.h"
#include <random>

string Presenter::findMostPopularSubSequence(string sqnce) {
    std::string out;
    //ЗАДАЧА №1 (НАИБОЛЬШАЯ ПОДПОСЛЕДОВАТЕЛЬНОСТЬ)
    HashTable<std::string, vector<int> > dict(15);
    vector<std::string> indexes;

    Crochemore(dict, sqnce, indexes);

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

    out + "Результат\n";

    for (int i = 0; i < indexes.size(); i++)
    {
        out += "cтрока: <" + arr[i].name + "> число вхождений: [" + to_string( arr[i].count.size() ) + "]\n";
    }
    return out;
}

string Presenter::BackPack(int k, int size){
    srand(time(nullptr));

    string out;
    int maxSize = size;
    Pack backpack( maxSize );
    list<Item> items; //Список предметов, лежащих в рюкзаке

    //Заполняем список вещей, которые можем положить в рюкзак
    for (int i = 0; i < k; i++) {
        Item x;
        x.length = rand() % 2 + 1;
        x.width = rand() % 300 + 1;
        x.V = x.width * x.length;
        x.cost = rand() % 35 + 5;
        items.push_back(x);
    }

    out += "counter: " + to_string(k) + "\n";
    out += "maxSize: " + to_string(maxSize) + "\n";
    out += "============================================================================================================================================\n";

    backpack.find_best(items);

    int i = 0;
    out += "TOTAL: { V = " + to_string(backpack.total.V) + ", c = " + to_string(backpack.total.cost) + " } | \nCONTAINS:\n[ ";
    for (const Item &item : backpack.items)
    {
        i++;
        out += " (" + to_string(i) + ") " + "{ V = " + to_string(item.V) + ", c = " +  to_string(item.cost) + " }" + "";
    }
    out += "]\n\n";
    return out;
}