//
// Created by Fedor Bulygin on 16.12.2022.
//
#define BOOST_TEST_MODULE testGraph

#include <boost/test/unit_test.hpp>
#include "Graph.h"
namespace std
{
    template<typename T1, typename T2>
    ostream& operator<< (ostream& out, const pair<T1, T2>& p)
    {
        return (out << "( " << p.first << ", " << p.second << " )");
    }

    template<typename T>
    ostream& operator<< (ostream& out, const vector<T>& v)
    {
        out << "(";
        for (auto itr = v.begin(); itr != v.end(); ++itr)
            out << " " << *itr;
        out << " )";

        return out;
    }
}

vector< Edge<int> > arr1 = { {0, 1, 6},
                             {1, 2, 7},
                             {2, 0, 5}, {2, 1, 4},
                             {3, 2, 10},
                             {4, 5, 3},
                             {5, 4, 1}
};
vector< vector<int> > arr2 = { {0,6,0,0,0,0},
                               {0,0,7,0,0,0},
                               {5,4,0,0,0,0},
                               {0,0,10,0,0,0},
                               {0,0,0,0,0,3},
                               {0,0,0,0,1,0}
};
vector< vector<int> > arr3 = { {0,1,1},
                               {4,0,1},
                               {2,1,0}
};
BOOST_AUTO_TEST_SUITE(testSuiteGraph)// Начало наборов тестов
struct Fixture{
    Graph<int> graph1, graph2, graph3;

    Fixture(): graph1(arr1, 6), graph2(arr2, 6), graph3(arr3,3){}
};
BOOST_FIXTURE_TEST_CASE(testGraphInitByList, Fixture)
{
    vector< vector< pair<int,int> > > arr =
                                { {make_pair(1, 6)},
                                  {make_pair(2, 7)},
                                  {make_pair(0, 5), make_pair(1, 4)},
                                  {make_pair(2, 10)},
                                  {make_pair(5, 3)},
                                  {make_pair(4, 1)} };
    BOOST_CHECK_EQUAL_COLLECTIONS(graph1.arr.begin(),graph1.arr.end(), arr.begin(), arr.end() );
}
BOOST_FIXTURE_TEST_CASE(testGraphInitByMtrx, Fixture)
{
    vector< vector< pair<int,int> > > arr =
            { {make_pair(1, 6)},
              {make_pair(2, 7)},
              {make_pair(0, 5), make_pair(1, 4)},
              {make_pair(2, 10)},
              {make_pair(5, 3)},
              {make_pair(4, 1)} };
    BOOST_CHECK_EQUAL_COLLECTIONS(graph2.arr.begin(),graph2.arr.end(), arr.begin(), arr.end() );
}
BOOST_FIXTURE_TEST_CASE(testGraphDijkstra, Fixture)
{
    int r1 = 1, r2 = 2, r3 = 3, r4 = 1, r5 = 2, r6 = 1;
    std::cout<<graph2.Dijkstra(1,0)<<endl;
    BOOST_CHECK_EQUAL(graph3.Dijkstra(0,1), r1);
    BOOST_CHECK_EQUAL(graph3.Dijkstra(0,2), r2);
    BOOST_CHECK_EQUAL(graph3.Dijkstra(1,0), r3);
    BOOST_CHECK_EQUAL(graph3.Dijkstra(1,2), r4);
    BOOST_CHECK_EQUAL(graph3.Dijkstra(2,0), r5);
    BOOST_CHECK_EQUAL(graph3.Dijkstra(2,1), r6);
}

BOOST_FIXTURE_TEST_CASE(testGraphFindStrongComponents, Fixture)
{

}
BOOST_FIXTURE_TEST_CASE(testGraph, Fixture)
{

}

BOOST_AUTO_TEST_SUITE_END() // Конец набора тестов