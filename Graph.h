#ifndef COP3530FINALPROJECT_GRAPH_H
#define COP3530FINALPROJECT_GRAPH_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

class Graph
{
public:
    map<int, vector<int>> graph;
    void insertEdge(int& from, int& to);
    vector<int> adjacentVertices(int& source);
    bool checkConnection(int& source, int& destiny);
    bool BFScheckConnection(int& source, int& destiny, int *prev,int n);
    string BFSprintGraph(int& source, int& destiny, int n);
    bool DFScheckConnection(int &source, int &destiny, int *prev,int n);
    string DFSprintGraph(int& source, int& destiny, int n);
};


#endif //COP3530FINALPROJECT_GRAPH_H
