//
// Created by Fedor Bulygin on 04.12.2022.
//
#ifndef LAB2_3_BAGPACKING_H
#define LAB2_3_BAGPACKING_H

#include <list>
#include <algorithm>
#include <iostream>
using namespace std;
struct Item
{
    int length = 0;
    int width = 0;
    int V = length * width;
    int cost = 0;

    static Item guardian()
    {
        return { numeric_limits<int>::max(),numeric_limits<int>::max(), numeric_limits<int>::max(), numeric_limits<int>::max() };
    }

    bool is_guardian() const
    {
        return V == numeric_limits<int>::max();
    }

    Item &operator +=(const Item &rhs)
    {
        V += rhs.V;
        cost += rhs.cost;
        return *this;
    }

    Item &operator -=(const Item &rhs)
    {
        V -= rhs.V;
        cost -= rhs.cost;
        return *this;
    }

    bool is_better_than(const Item &rhs) const
    {
        return cost > rhs.cost;
    }

    friend ostream &operator <<(ostream &strm, const Item &item)
    {
        strm << "{ V = " << item.V << ", c = " << item.cost << " }";
        return strm;
    }
};
class Presenter;
class Pack
{
    friend class Presenter;
private:
    list<Item> items;   // Дерево всевозможных комбинаций, полный перебор.
    Item total; //Результат, самое оптимальное решение
    int max_v;  //Максимальный объём, который вмещает в себя рюкзак

    // Удаляем элемент из итогового результат
    void pop_back()
    {
        Item item = items.back();
        items.pop_back();
        total -= item;
    }

    // Добавляем элемент в итоговый результат, если он не превышает V и возвращаем true, в противном случае возвращаем false
    bool push_back(Item item)
    {
        if (total.V + item.V > max_v)
            return false;

        total += item;
        items.push_back(item);

        return true;
    }
    //   Рекурсивный метод нахождения лучшей комбинации
    void find_best(Pack &current, list<Item>::const_iterator it_remaining)
    {
        if (it_remaining->is_guardian())
        {
            cout << "Leaf: " << current << endl;
            if (current.total.is_better_than(total))
                *this = current;
            return;
        }

        find_best(current, next(it_remaining));

        if (current.push_back(*it_remaining))
        {
            find_best(current, next(it_remaining));
            current.pop_back();
        }
    }

public:

    Pack(int max_v) : max_v(max_v){}

    // Метод нахождения лучшей комбинации
    Item find_best(list<Item> &source)
    {
        source.push_back(Item::guardian());
        items.clear();
        Pack current(max_v);

        //  Переходим к методу нахождения лучшей комбинации в приватном поле
        find_best(current, source.begin());
        return total;
    }

    //Переопределение оператора вывода
    friend ostream &operator <<(ostream &os, const Pack &items)
    {
        int i = 0;
        os << "TOTAL: " << items.total << " | CONTAINS: [ ";
        for (const Item &item : items.items) {
            i++;
            os <<"("<<i<<") " << item << " | ";
        }
        os << " ]";
        return os;
    }


};


#endif //LAB2_3_BAGPACKING_H
