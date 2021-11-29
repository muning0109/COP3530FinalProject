#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <stack>
using namespace std;

class Graph{
public:
    map<int, vector<int>> graph;
    void insertEdge(int& from, int& to);
    vector<int> adjacentVertices(int& source);
    bool checkConnection(int& source, int& destiny);
};


void Graph::insertEdge(int& from, int& to)
{
    graph[from].push_back(to);
}

vector<int> Graph::adjacentVertices(int& source)
{
    vector<int> adjVertices = graph.find(source)->second;
    return adjVertices;
}

bool Graph::checkConnection(int& source, int& destiny)
{
    set<int> visited;
    stack<int> s;
    visited.insert(source);
    s.push(source);
    while(!s.empty())
    {
        int u = s.top();
        s.pop();
        vector<int> adj = adjacentVertices(u);
        for(auto v: adj)
        {
            if (v == destiny)
                return true;
            if (visited.find(v) == visited.end())
            {
                visited.insert(v);
                s.push(v);
            }
        }
    }
    return false;
}

void ReadFile(Graph& emailGraph)
{
    fstream dataFile;
    dataFile.open("email-Enron.txt", ios::in);
    string line;
    while(getline(dataFile, line))
    {
        int pos = line.find('\t');
        int from = stoi(line.substr(0, pos));
        int to = stoi(line.substr(pos));
        emailGraph.insertEdge(from, to);
    }
}

int main()
{
    Graph emailGraph;
    ReadFile(emailGraph);
    int from = 10608;
    int to = 21340;
    bool connected = emailGraph.checkConnection(from, to);
    cout << connected << endl;
    return 0;
}
