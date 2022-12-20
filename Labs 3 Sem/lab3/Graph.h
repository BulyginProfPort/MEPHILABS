//
// Created by Fedor Bulygin on 15.12.2022.
//

#ifndef LAB3_GRAPH_H
#define LAB3_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <map>
namespace testSuiteGraph // Обратите внимание - это имя набора тестов
{
    // А это имена конкретных тестов
    struct testGraphInitByList;
    struct testGraphInitByMtrx;
    struct testGraph;
}

using namespace std;

template <class T>
struct Edge{
    int from, to;   // from = вершина от которой идет направленное ребро до вершины to с весом weight
    T weight;
};

template <class T>
// Реализация ориентированного графа
class Graph {
    friend struct::testSuiteGraph::testGraphInitByList;
    friend struct::testSuiteGraph::testGraphInitByMtrx;
    friend struct::testSuiteGraph::testGraph;
private:
    vector< vector< pair<int,T> > > arr; // Вектор векторов для представления списков смежности или матрицы инцидентности
    vector< vector<int> > components;   //  Компоненты сильной связности
    vector<int> countOut;
    vector<bool> visited;
    int size, count = 0;
public:
    //  Инициализация графа с помощью списка смежности
    Graph( vector< Edge<T> > const &_init_, int n)
    {
        size = n;
        arr.resize(n);
        countOut.resize(size);
        visited.resize(size, false);
        for (auto &v: _init_){
            arr[v.from].push_back(make_pair(v.to,v.weight));
        }
    }
    //  Инициализация графа с помощью матрицы смежности
    Graph( vector< vector<int> > const &_init_, int n)
    {
        size = n;
        arr.resize(n);
        countOut.resize(size);
        visited.resize(size, false);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (_init_[i][j] != 0)
                    arr[i].push_back(make_pair(j, _init_[i][j]) ); // Добавляем номер вершины и вес до нее
            }
        }

    }
    //  Поиск компонент сильной связности
    void DFS(int vertex)
    {
        countOut[vertex] = count++;
        visited[vertex] = true;
        vector< pair<int,T> > v = arr[vertex];
        for (pair<int,T> i: v)
        {
            if (!visited[i.first])
                DFS(i.first);
        }
        countOut[vertex] = count++; //Время выхода из рекурсии
    }
    //  Инвертирование ориентированного графа
    void inverse()
    {
        vector< vector< pair<int,T> > > result(size);
        int i = 0;
        for (auto &v: arr)
        {
            int j = 0;
            for (auto &element: v)
            {
                if (arr[i][j].first + 1 > size)
                    result.resize(arr[i][j].first + 1);
                result[arr[i][j].first].push_back( make_pair(i,arr[i][j].second) );
                j++;
            }
            i++;
        }
        arr.clear();
        arr = result;
    }
    //  Поиск наилучшего пути
    int  Dijkstra(int start, int end) //  S - вершина с которой начнем искать
    {
        int Inf = numeric_limits<int>::max();
        vector<int> d( arr.size(), Inf );
        priority_queue< pair<int,int> > q;
        d[start] = 0;
        q.push( make_pair(start, 0) );
        while (!q.empty() )
        {
            int v = q.top().first;
            int len = -q.top().second;
            q.pop();
            if (len > d[v])
                continue;
            for (int i = 0; i < size; i++)
            {
                int to = i;
                int length = arr[v][i].second;
                if (d[to] > d[v] + length && length >= 0)
                {
                    d[to] = d[v] + length;
                    q.push( make_pair(to, -d[to]) );
                }
            }
        }
        if (d[end] == Inf)
            throw runtime_error("No path to" + to_string(end) + "node");
        else
            return d[end];
    }
    //  В лучшем O(V+E), в худшем O(V^2)
    void findStrongComponents()
    {
        resetData();
        DFS(0);
        vector< pair<int,int> > dict;
        for (int i= 0 ; i < countOut.size(); i++)
            dict.emplace_back( make_pair(i, countOut[i]) );
        sort(dict.begin(), dict.end(), [&](pair<int,int> &a, pair<int,int> &b){return a.second > b.second;} );
        inverse();
        resetData();
        vector <bool> marked(size);
        for (pair<int,int> v: dict)
        {
            DFS(v.first);
            vector<int> x;
            for (int i = 0; i < visited.size(); i++){
                if (visited[i] && !marked[i] )
                {
                    marked[i] = true;
                    x.push_back(i);
                }
            }
            if(!x.empty())
                components.push_back(x);
        }
        for(auto &x: components)
        {
            cout<<"\nStrong component\n";
            for (auto &y:x)
                cout<<y;
            cout<<endl;
        }
    }
    //  Сброс всех данных
    void resetData()
    {
        count = 0;
        countOut.clear();
        countOut.resize(size);
        visited.assign(size, false);
    }
    //  Функция для печати представления списка смежности Graph
    friend ostream &operator<<(ostream &out, const Graph<T> &graph) {
        for (int i = 0; i < graph.arr.size(); i++)
        {
            // Функция для печати всех соседних вершин данной вершины
            for (pair<int,T> v: graph.arr[i])
            {
                out << "(" << i << ", " << v.first << ", " << v.second << ") ";
            }
            out << endl;
        }
        return out;
    }
};

#endif //LAB3_GRAPH_H
