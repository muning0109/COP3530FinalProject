#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <stack>
#include <queue>
#include "SFML_Process.h"
using namespace std;

class Graph{
public:
    map<int, vector<int>> graph;
    void insertEdge(int& from, int& to);
    vector<int> adjacentVertices(int& source);
    bool checkConnection(int& source, int& destiny);
    bool BFScheckConnection(int& source, int& destiny, int *prev,int n);
    void printGraph(int& source, int& destiny, int n);
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
            if (v == destiny) {
                return true;
            }
            if (visited.find(v) == visited.end())
            {
                visited.insert(v);
                s.push(v);
            }
        }
    }
    return false;
}

bool Graph::BFScheckConnection(int &source, int &destiny, int *prev,int n) {
    set<int> visited;
    queue<int> q;
    visited.insert(source);
    q.push(source);

    for(unsigned int i =0;i<n;i++){
        prev[i]=-1;
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vector<int> adj = adjacentVertices(u);
        for(auto v: adj){
            if(visited.find(v)==visited.end()){
                visited.insert(v);
                q.push(v);
                prev[v]=u;
                if(v==destiny) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Graph::printGraph(int &source, int &destiny, int n) {
    int prev[n];

    if(!BFScheckConnection(source,destiny,prev,n)){
        cout<<"No connection"<<endl;
    }

    vector<int>path;
    int trace=destiny;
    path.push_back(trace);
    while(prev[trace]!=-1){
        path.push_back(prev[trace]);
        trace=prev[trace];
    }

    for(unsigned int i =0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
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

    emailGraph.printGraph(from,to,36692);

    SFML_Process::window();

    return 0;
}
