#ifndef COP3530FINALPROJECT_SFML_PROCESS_H
#define COP3530FINALPROJECT_SFML_PROCESS_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "outputProcess.h"

using namespace std;

class SFML_Process
{
    static vector<bool> button;
    static vector<bool> inputBox;
    static string input[2];
    static bool key_Enter;
    static bool isEnter;
    static bool isDFSWindow;

public: static void window();
        static string getInput1();
        static string getInput2();

private:
    static void windowProcess(sf::RenderWindow&);
    static void Menu(sf::RenderWindow&);
    static void displayText(sf::RenderWindow&, string output, int fontStyle, float x, float y, bool isCenter);
    static sf::RectangleShape menuButton(float x, float y, int buttonIndex);
    static sf::RectangleShape line();
    static void checkMouseClick(sf::RenderWindow& window, sf::RectangleShape r, int buttonIndex);
    static void projectInfo(sf::RenderWindow& window);
    static void inputWindow(sf::RenderWindow& window);
    static void checkMouseClick_inputBox(sf::RenderWindow& window, sf::RectangleShape r, int inputBoxIndex);
    static void processButton(sf::RenderWindow& window);
    static void resetButton(sf::RenderWindow& window);
    static void BFS_Output(sf::RenderWindow& window);
    static void DFS_Output(sf::RenderWindow& window);
};


#endif //COP3530FINALPROJECT_SFML_PROCESS_H
