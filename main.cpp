#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "SFML_Process.h"
#include "Graph.h"
#include "outputProcess.h"

using namespace std;

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
    outputProcess::inputGraph(&emailGraph);
    int from = 10608;
    int to = 21340;
    bool connected = emailGraph.checkConnection(from, to);
    cout << connected << endl;
    emailGraph.BFSprintGraph(from,to,36692);
    cout << endl;
    emailGraph.DFSprintGraph(from,to,36692);

    SFML_Process::window();
    return 0;
}
