#include <iostream>
#include "Graph.h"
using namespace std;
int main(){
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

    vector< vector<int> > arr4 = { {0,1,0,0,1},
                                   {0,0,1,0,0},
                                   {0,0,0,1,0},
                                   {0,1,0,0,0},
                                   {0,0,0,1,0}
    };
    Graph<int> graph1(arr1, 6);

    std::cout<<"Graph 1"<<endl;
    cout << graph1 << endl;

    Graph<int> graph2(arr3, 3);
    std::cout<<"Graph 2"<<endl;
    std::cout<<graph2<<endl;

    Graph<int> graph3(arr3,3);
    std::cout<<"Graph 3"<<endl;
    std::cout<<graph3<<endl;

    Graph<int> graph4(arr4,5);
    std::cout<<"Graph 4"<<endl;
    std::cout<<graph4<<endl;
    graph4.DFS(0);

    graph4.findStrongComponents();
}
