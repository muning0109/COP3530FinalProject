#include "outputProcess.h"

int outputProcess::input1 = 0;
int outputProcess::input2 = 0;
Graph* outputProcess::graph;

string outputProcess::getBFSOutput()
{
    return graph->BFSprintGraph(input1,input2,36692);
}

void outputProcess::getInput()
{
    if (SFML_Process::getInput1() != "" && SFML_Process::getInput2() != "")
    {
        input1 = stoi(SFML_Process::getInput1());
        input2 = stoi(SFML_Process::getInput2());
    } else
    {
        input1 = -1;
        input2 = -1;
    }
}

void outputProcess::inputGraph(Graph* g)
{
    graph = g;
}

string outputProcess::getDFSOutput()
{
    return graph->DFSprintGraph(input1,input2,36692);
}
