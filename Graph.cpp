#include "Graph.h"

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

bool Graph::DFScheckConnection(int &source, int &destiny, int *prev,int n) {
    set<int> visited;
    stack<int> s;
    visited.insert(source);
    s.push(source);

    for(unsigned int i =0;i<n;i++){
        prev[i]=-1;
    }
    while(!s.empty()){
        int u = s.top();
        s.pop();
        vector<int> adj = adjacentVertices(u);
        for(auto v: adj){
            if(visited.find(v)==visited.end()){
                visited.insert(v);
                s.push(v);
                prev[v]=u;
                if(v==destiny) {
                    return true;
                }
            }
        }
    }
    return false;
}

string Graph::BFSprintGraph(int &source, int &destiny, int n) {
    stringstream ss;
    int prev[n];

    if(!BFScheckConnection(source,destiny,prev,n)){
        ss <<"No connection";
        return ss.str();
    }

    vector<int>path;
    int trace=destiny;
    path.push_back(trace);
    while(prev[trace]!=-1){
        path.push_back(prev[trace]);
        trace=prev[trace];
    }

    for(unsigned int i =0;i<path.size();i++){
        ss <<path[i];
        if(i != path.size() - 1)
            ss << "->";
        if (i % 9 == 0 && i != 0)
            ss << endl;
    }
    return ss.str();
}

string Graph::DFSprintGraph(int &source, int &destiny, int n) {
    stringstream ss;
    int prev[n];

    if(!DFScheckConnection(source,destiny,prev,n)){
        ss <<"No connection";
        return ss.str();
    }

    vector<int>path;
    int trace=destiny;
    path.push_back(trace);
    while(prev[trace]!=-1){
        path.push_back(prev[trace]);
        trace=prev[trace];
    }

    for(unsigned int i =0;i<path.size();i++){
        ss << path[i];
        if (i != path.size() - 1)
            ss <<"->";
        if (i % 9 == 0 && i != 0)
            ss << endl;
    }
    return ss.str();
}