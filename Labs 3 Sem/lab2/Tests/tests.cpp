#define BOOST_TEST_MODULE testHashTable

#include "tests.h"
#include <boost/test/unit_test.hpp>
#include "../Tasks/SubSequence/CountSubSequence.h"
#include "../Tasks/Packing/BagPacking.h"

const int arr1[20] = {23,14,56,35,26,73,67,88, 92, 37,4,
               25, 13, 34, 22, 64,75,43, 34, 32};
const std::string arr2[20] =
        {
        "Антонов Иосиф Еремеевич",
        "Казаков Кондратий Антонович",
        "Блинов Орест Игоревич",
        "Ларионов Богдан Александрович",
        "Панов Пантелеймон Лукьевич",
        "Иванков Дмитрий Ильяович",
        "Киселёв Мирослав Авксентьевич",
        "Александров Гаянэ Миронович",
        "Коновалов Алан Глебович",
        "Щукин Августин Геласьевич",
        "Крылов Модест Гордеевич",
        "Петухов Овидий Ростиславович",
        "Родионов Людвиг Андреевич",
        "Гордеев Антон Макарович",
        "Веселов Венедикт Федотович",
        "Крюков Феликс Рубенович",
        "Самойлов Валерий Лаврентьевич",
        "Макаров Витольд Федосеевич",
        "Субботин Мирон Денисович",
        "Пономарёв Трофим Иванович"
        };
struct Person{
    int age;
    std::string FIO;
    bool married;
};
const struct Person arr3[20] = {arr1[0], arr2[0], false,
                          arr1[1], arr2[1], false,
                          arr1[2], arr2[2], false,
                          arr1[3], arr2[3], true,
                          arr1[4], arr2[4], true,
                          arr1[5], arr2[5], true,
                          arr1[6], arr2[6], false,
                          arr1[7], arr2[7], true,
                          arr1[8], arr2[8], true,
                          arr1[9], arr2[9], true,
                          arr1[10], arr2[10], false,
                          arr1[11], arr2[11], true,
                          arr1[12], arr2[12], false,
                          arr1[13], arr2[13], true,
                          arr1[14], arr2[14], false,
                          arr1[15], arr2[15], true,
                          arr1[16], arr2[16], false,
                          arr1[17], arr2[17], true,
                          arr1[18], arr2[18], true,
                          arr1[19], arr2[19], false
                            };

Sequence<std::string> res[] = {"a", vector<int>{0,3,4,7},
                               "b", vector<int>{1, 2, 5, 6},
                               "abb",vector<int>{0,4},
                               "abba", vector<int>{0,4},
                               "ab", vector<int>{0,4},
                               "bb", vector<int>{1,5},
                               "bba", vector<int>{1,5},
                               "ba", vector<int>{2,6},
                               "bbaa", vector<int>{1},
                               "baa", vector<int>{2},
                               "baab", vector<int>{2},
                               "aa", vector<int>{3},
                               "aab", vector<int>{3},
                               "aabb", vector<int>{3}
};
BOOST_AUTO_TEST_SUITE(testSuiteHashTable) // Начало наборов тестов
struct Fixture{
    HashTable<int> table1;
    HashTable<std::string> table2;
    HashTable<std::string,Person> table3;

    //Для задачи с подстрокой
    HashTable<std::string, vector<int> > dict;
    std::string sqnce;
    vector<std::string> indexes;

    // Инициализируем наши таблицы разного ТД, чтобы работать с ними в дальнейшем
    Fixture(): table1(20), table2(20), table3(20), dict(15), sqnce("abbaabba")
    {
        for (int i = 0; i < 20; i++) {
            table1.InsertItem(arr1[i]);
            table2.InsertItem(arr2[i]);
            table3.InsertItem(arr3[i].FIO, arr3[i]);
        }
    }
};
BOOST_FIXTURE_TEST_CASE(testHashTableGet, Fixture)
{
    BOOST_CHECK_EQUAL(table1.Search(arr1[3]), true );
    BOOST_CHECK_EQUAL(table2.Search(arr2[8]), true);
    BOOST_CHECK_EQUAL(table3.Search(arr3[18].FIO), true);

    BOOST_CHECK_EQUAL(table1.Search(9876), false );
    BOOST_CHECK_EQUAL(table2.Search("АХМАТ СИЛА"), false);
    Person z = {0,"АХМАТ СИЛА", true};
    BOOST_CHECK_EQUAL(table3.Search(z.FIO), false);
}
BOOST_FIXTURE_TEST_CASE(testHashTableInsert, Fixture)
{
    int x = 999;
    table1.InsertItem(x);
    BOOST_CHECK_EQUAL(table1.Search(x), true);
    std::string y = "АХМАТ СИЛА";
    table2.InsertItem(y);
    BOOST_CHECK_EQUAL(table2.Search(y), true);
    Person z = {46, "Рамзан Ахматович Кадыров", true};
    table3.InsertItem(z.FIO, z);
    BOOST_CHECK_EQUAL(table3.Search(z.FIO), true);
}
BOOST_FIXTURE_TEST_CASE(testHashTableDelete, Fixture)
{
    table1.DeleteItem(arr1[0]);
    BOOST_CHECK_EQUAL(table1.Search(arr1[0]), false);
    table2.DeleteItem(arr2[0]);
    BOOST_CHECK_EQUAL(table2.Search(arr2[0]), false);
    table3.DeleteItem(arr3[0].FIO);
    BOOST_CHECK_EQUAL(table3.Search(arr3[0].FIO), false);
}
BOOST_FIXTURE_TEST_CASE(testSubSequence, Fixture)
{
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

    for (int i = 0; i < indexes.size(); i++)
    {
        std::cout<<"["<<i<<"]"<<endl;
        BOOST_CHECK_EQUAL_COLLECTIONS(res[i].count.begin(), res[i].count.end(), arr[i].count.begin(), arr[i].count.end());
    }
}

BOOST_AUTO_TEST_SUITE_END() // Конец набора тестов