//
// Created by Fedor Bulygin on 15.11.2022.
//
#ifndef LAB2_3_HASHTABLE_H
#define LAB2_3_HASHTABLE_H

#include <list>
#include <iostream>
#include <cmath>

using namespace std;
template <class DataType>
ostream& operator<<(ostream& os, const vector<DataType>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "] ";
    return os;
}

namespace testSuiteHashTable
{
    struct testHashTableInsert;
    struct testHashTableDelete;
    struct testHashTableGet;
}
class Presenter;
template<class KeyType, class DataType = KeyType>
class HashTable{
    friend class Presenter;
private:
    //Структуру Хэш-Таблицы
    int size;
    //Структура, хранящая ключ-значение
    struct Node{
        KeyType key;// Ключ хэш таблицы
        DataType data;// Храним всю инфу
        explicit Node(KeyType const &value): key(value), data(key) {}
        Node(KeyType const &value, DataType const &data): key(value), data(data){}
    };
    list<Node> *table; //Хэш таблица, реализованная методом цепочек (с помощью списка из STL)

    //Функции хэширования
    int GetHash(string const &key)
    {
        int P_POW = 1, P_CONST = 31, hashCode = 0,m = 1e9 + 7, n = key.length();
        for (int i = 0; i < n; i++)
        {
            hashCode = (hashCode + (key[i] - 'a' + 1) * P_POW ) % m;
            P_POW = (P_POW * P_CONST) % m;
        }
        return abs(hashCode % size);
    }
    int GetHash(int const &key)
    {
        return abs(key % size);
    }

    friend struct::testSuiteHashTable::testHashTableInsert;
    friend struct::testSuiteHashTable::testHashTableDelete;
    friend struct::testSuiteHashTable::testHashTableGet;

public:
    explicit HashTable(int ts)
    {
        size = ts;
        table = new list<Node>[size];
    }
    int GetSize(){
        return size;
    }
    void InsertItem(KeyType const &x)
    {
        int index = GetHash(x);
        Node a(x);
        //Вывод исключения, если вышли за предел массива
        if (index > size - 1)
            throw out_of_range("Выход за пределы массива!");
        table[index].push_back(a);
    }
    void InsertItem(KeyType const &key, DataType const &data)
    {
        int index = GetHash(key);
        Node a(key,data);

        //Вывод исключения, если вышли за предел массива
        if (index > size - 1)
            throw out_of_range("Выход за пределы массива!");

        table[index].push_back(a);
    }
    void DeleteItem(const KeyType &key)
    {
        // Получаем хэш ключа
        int index = GetHash(key);

        //Вывод исключения, если вышли за предел массива
        if (index > size - 1)
            throw out_of_range("Выход за пределы массива!");

        // Находим ключ в индексах list
        typename list <Node> :: iterator i;
        for (i = table[index].begin();i != table[index].end(); i++)
        {
            if ( (*i).key == key )
                break;
        }
        // Если ключ найден в хэш таблице, удаляем его
        if (i != table[index].end())
            table[index].erase(i);
    }
    bool Search(KeyType const &key){
        // Получаем хэш ключа
        int index = GetHash(key);

        //Вывод исключения, если вышли за предел массива
        if (index > size - 1)
            throw out_of_range("Выход за пределы массива!");

        // Находим ключ в индексах list
        typename list<Node> :: iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++)
        {
            if ( (*i).key == key )
                return true;
        }
        return false;
    }
    Node Get(KeyType const &key){
        if (Search(key))
        {
            int index = GetHash(key);
            typename list <Node> :: iterator i;
            for (i = table[index].begin(); i != table[index].end(); i++)
            {
                if ( (*i).key == key )
                    return *i;
            }
        }
        throw out_of_range("Такого индекса не существует");
    }

    void Resize()
    {
        int prev_size = size;
        size *= 2;
        auto *table1 = new list<Node>[size];
        swap(table, table1);
        for (int i = 0; i < prev_size;i++)
        {
            typename list<Node>::iterator it;
            for (it = table1[i].begin(); it != table1[i].end(); it++)
            {
                InsertItem( (*it).key);
            }
        }
        delete[] table1;
    }
    friend ostream& operator<< (ostream & out, const HashTable<KeyType,DataType> &a)
    {
        for (int i = 0; i < a.size; i++)
        {
            out << i;
            for (auto x : a.table[i]) {
                out << " --> " << x.key << x.data;
            }
            out << endl;
        }
        return out;
    }
    list<Node>& operator[](const KeyType index_){
        int index = GetHash(index_);
        return table[index];
    }
    ~HashTable(){
        delete[] table;
    }
};
#endif //LAB2_3_HASHTABLE_H
