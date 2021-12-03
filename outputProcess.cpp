#include "outputProcess.h"

string outputProcess::BFSOutput = "";
int outputProcess::input1 = 0;
int outputProcess::input2 = 0;
Graph* outputProcess::graph;

string outputProcess::getBFSOutput()
{
    cout << graph << endl;
    BFSOutput = graph->printGraph(input1,input2,10000);
    return BFSOutput;
}

void outputProcess::getInput()
{
    input1 = SFML_Process::getInput1();
    input2 = SFML_Process::getInput2();
}

void outputProcess::getGraph(Graph* g)
{
    graph = g;
}
