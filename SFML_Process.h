#ifndef COP3530FINALPROJECT_SFML_PROCESS_H
#define COP3530FINALPROJECT_SFML_PROCESS_H

#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;

class SFML_Process
{
    static vector<bool> button;
    static vector<bool> inputBox;
    static string input[2];
    static bool key_Enter;

public: static void window();

private:
    static void windowProcess(sf::RenderWindow&);
    static void Menu(sf::RenderWindow&);
    static void displayText(sf::RenderWindow&, string output, int fontStyle, float x, float y);
    static sf::RectangleShape menuButton(float x, float y, int buttonIndex);
    static sf::RectangleShape line();
    static void checkMouseClick(sf::RenderWindow& window, sf::RectangleShape r, int buttonIndex);
    static void projectInfo(sf::RenderWindow& window);
    static void DFS_BFS_processWindow(sf::RenderWindow& window);
    static void checkMouseClick_inputBox(sf::RenderWindow& window, sf::RectangleShape r, int inputBoxIndex);
    static void processButton(sf::RenderWindow& window);
    static void resetButton(sf::RenderWindow& window);
};


#endif //COP3530FINALPROJECT_SFML_PROCESS_H
