#ifndef COP3530FINALPROJECT_OUTPUTPROCESS_H
#define COP3530FINALPROJECT_OUTPUTPROCESS_H

#include <iostream>
#include "Graph.h"
#include "SFML_Process.h"

using namespace std;

class outputProcess
{
    static int input1;
    static int input2;
    static Graph* graph;
public:
    static string getBFSOutput();
    static string getDFSOutput();
    static void getInput();
    static void inputGraph(Graph* g);

private:

};





#endif //COP3530FINALPROJECT_OUTPUTPROCESS_H
