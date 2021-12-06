#include "SFML_Process.h"

vector<bool> SFML_Process::button = {true, false};
vector<bool> SFML_Process::inputBox = {false, false};
string SFML_Process::input[2] = {"", ""};
bool SFML_Process::key_Enter = false;
bool SFML_Process::isEnter = false;
bool SFML_Process::isDFSWindow = true;
string SFML_Process::displayOnce="";
bool SFML_Process::stop=false;


void SFML_Process::window()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Graph Methods Compare");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            ///text input
            for (int i = 0; i < inputBox.size(); ++i)
                if(inputBox[i])
                    if(event.type == sf::Event::TextEntered)
                    {
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                        {
                            input[i].pop_back();
                            isEnter = false;
                        }
                        else
                            if(isdigit(static_cast<char>(event.text.unicode)))
                                input[i] += static_cast<char>(event.text.unicode);
                    }

            ///key 'Enter'
            if (event.type == sf::Event::KeyReleased)
                if (event.key.code == sf::Keyboard::Enter)
                    key_Enter = true;
        }

        window.clear(sf::Color::White);
        windowProcess(window);
        window.display();
    }
}

void SFML_Process::windowProcess(sf::RenderWindow& window)
{
    Menu(window);
    window.draw(line());
    projectInfo(window);
    inputWindow(window);
    processButton(window);
    resetButton(window);
    if (isEnter)
    {
        if (isDFSWindow)
            DFS_Output(window);
        else
            BFS_Output(window);
            stop=true;
    }
}

void SFML_Process::displayText(sf::RenderWindow& window, string output, int fontStyle, float x, float y, bool isCenter)
{
    sf::Text t;
    sf::Font f1;
    if (fontStyle == 1)
        f1.loadFromFile("../src/SFML-source/Font/OpenSans-Bold.ttf");
    else if (fontStyle == 2)
        f1.loadFromFile("../src/SFML-source/Font/OpenSans-Italic.ttf");
    t.setFont(f1);
    t.setString(output);
    t.setCharacterSize(35);
    t.setFillColor(sf::Color::Black);
    sf::FloatRect textRect = t.getLocalBounds();
    if (isCenter)
        t.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    t.setPosition(sf::Vector2f(x / 2.0f, y / 2.0f));
    window.draw(t);
}

void SFML_Process::Menu(sf::RenderWindow& window)
{
    ///menu title
    {
        sf::RectangleShape r1;
        r1.setSize(sf::Vector2<float>(500, 100));
        r1.setFillColor(sf::Color(UINT8_C(0), INT8_C(255), INT8_C(255), 255));
        r1.setPosition(0, 0);
        window.draw(r1);
        displayText(window, "Menu", 1, 500, 100, true);
    }

    ///Button "RUN AS DFS"
    {
        sf::RectangleShape r2 = menuButton(10,100.f, 0);
        checkMouseClick(window, r2, 0);
        window.draw(r2);
        displayText(window, "Run as DFS", 2, 500, 300, true);
    }

    ///Button "RUN AS BFS"
    {
        sf::RectangleShape r3 = menuButton(10,220.f, 1);
        checkMouseClick(window, r3, 1);
        window.draw(r3);
        displayText(window, "Run as BFS", 2, 500, 535, true);
    }
}

sf::RectangleShape SFML_Process::line()
{
    sf::RectangleShape line(sf::Vector2f(1920, 8));
    line.setRotation(90);
    line.setPosition(500,0);
    line.setFillColor(sf::Color::Black);
    return line;
}

sf::RectangleShape SFML_Process::menuButton(float x, float y, int buttonIndex)
{
    sf::RectangleShape r2;
    r2.setSize(sf::Vector2<float>(475, 100));
    r2.setPosition(x, y);
    if (!button[buttonIndex])
        r2.setFillColor(sf::Color(UINT8_C(153), INT8_C(255), INT8_C(255), 255));
    else
        r2.setFillColor(sf::Color(UINT8_C(0), INT8_C(153), INT8_C(153), 255));
    r2.setOutlineThickness(10);
    r2.setOutlineColor(sf::Color(UINT8_C(128), INT8_C(128), INT8_C(128), 255));
    return r2;
}

void SFML_Process::checkMouseClick(sf::RenderWindow& window, sf::RectangleShape r, int buttonIndex)
{
    if (buttonIndex > button.size())
    {
        cout << "SFML_Process::checkMouseClick buttonIndex over index" << endl;
    }
    if (r.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            button[buttonIndex] = true;
            if (buttonIndex == 0)
                isDFSWindow = true;
            else
                isDFSWindow = false;
            for(int i = 0; i < button.size(); i++)
                if(i != buttonIndex)
                    button[i] = false;
        }
}

void SFML_Process::projectInfo(sf::RenderWindow& window)
{
    sf::Text t;
    sf::Font f1;
    f1.loadFromFile("../src/SFML-source/Font/OpenSans-Italic.ttf");
    t.setFont(f1);
    t.setString("Project design by:\n"
                "Muning Chen\n"
                "Shoujing Ke\n"
                "Xizhe Li");
    t.setCharacterSize(20);
    t.setFillColor(sf::Color::Black);
    sf::FloatRect textRect = t.getLocalBounds();
    t.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    t.setPosition(sf::Vector2f(500 / 2.0f, 1000));
    window.draw(t);
}

void SFML_Process::inputWindow(sf::RenderWindow& window)
{
    ///input box
    //from
    sf::RectangleShape r;
    r.setSize(sf::Vector2<float>(500, 50));
    r.setPosition(660, 50);
    checkMouseClick_inputBox(window,r,0);
    if(!inputBox[0])
        r.setFillColor(sf::Color::White);
    else
        r.setFillColor(sf::Color(UINT8_C(224),UINT8_C(224),UINT8_C(224),255));
    r.setOutlineThickness(5);
    r.setOutlineColor(sf::Color::Black);
    window.draw(r);
    displayText(window, "From:", 2, 1150, 150, true);

    //to
    sf::RectangleShape r2;
    r2.setSize(sf::Vector2<float>(500, 50));
    r2.setPosition(660, 150);
    checkMouseClick_inputBox(window,r2,1);
    if(!inputBox[1])
        r2.setFillColor(sf::Color::White);
    else
        r2.setFillColor(sf::Color(UINT8_C(224),UINT8_C(224),UINT8_C(224),255));
    r2.setOutlineThickness(5);
    r2.setOutlineColor(sf::Color::Black);
    window.draw(r2);
    displayText(window, "To:", 2, 1150, 350, true);

    ///displayInput
    sf::Font f1;
    f1.loadFromFile("../src/SFML-source/Font/OpenSans-Italic.ttf");
    //from
    sf::Text t;
    t.setFont(f1);
    t.setString(input[0]);
    t.setCharacterSize(35);
    t.setFillColor(sf::Color::Black);
    t.setPosition(665,50);
    window.draw(t);
    //to
    sf::Text t2;
    t2.setFont(f1);
    t2.setString(input[1]);
    t2.setCharacterSize(35);
    t2.setFillColor(sf::Color::Black);
    t2.setPosition(665,150);
    window.draw(t2);
}

void SFML_Process::checkMouseClick_inputBox(sf::RenderWindow &window, sf::RectangleShape r, int inputBoxIndex)
{
    if(r.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            inputBox[inputBoxIndex] = true;
    }else
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            inputBox[inputBoxIndex] = false;
    }
}

void SFML_Process::processButton(sf::RenderWindow &window)
{
    displayText(window,"Press 'Enter' or ", 2, 1375, 550, true);

    ///display button
    sf::RectangleShape r2;
    r2.setSize(sf::Vector2<float>(150, 50));
    r2.setPosition(830, 250);
    if (!r2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))
        r2.setFillColor(sf::Color(UINT8_C(153), INT8_C(255), INT8_C(255), 255));
    else
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            r2.setFillColor(sf::Color(UINT8_C(0), INT8_C(153), INT8_C(153), 255));
            isEnter = true;
        }
    }
    if (key_Enter)
    {
        r2.setFillColor(sf::Color(UINT8_C(0), INT8_C(153), INT8_C(153), 255));
        key_Enter = false;
        isEnter = true;
    }
    r2.setOutlineColor(sf::Color(UINT8_C(128), INT8_C(128), INT8_C(128), 255));
    r2.setOutlineThickness(10);
    window.draw(r2);

    ///text "Enter"
    sf::Text t;
    sf::Font f1;
    f1.loadFromFile("../src/SFML-source/Font/OpenSans-Italic.ttf");
    t.setFont(f1);
    t.setString("Enter");
    t.setCharacterSize(35);
    t.setFillColor(sf::Color::Black);
    sf::FloatRect textRect = t.getLocalBounds();
    t.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    t.setPosition(sf::Vector2f(1815 / 2.0f, 550 / 2.0f));
    window.draw(t);

}

void SFML_Process::resetButton(sf::RenderWindow& window)
{
    sf::RectangleShape r2;
    r2.setSize(sf::Vector2<float>(150, 50));
    r2.setPosition(1300, 100);
    if (!r2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))
        r2.setFillColor(sf::Color(UINT8_C(153), INT8_C(255), INT8_C(255), 255));
    else
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            r2.setFillColor(sf::Color(UINT8_C(0), INT8_C(153), INT8_C(153), 255));
            isEnter = false;
            stop=false;
        }
    }
    r2.setOutlineColor(sf::Color(UINT8_C(128), INT8_C(128), INT8_C(128), 255));
    r2.setOutlineThickness(10);
    window.draw(r2);

    ///text "Reset"
    sf::Text t;
    sf::Font f1;
    f1.loadFromFile("../src/SFML-source/Font/OpenSans-Italic.ttf");
    t.setFont(f1);
    t.setString("Reset");
    t.setCharacterSize(35);
    t.setFillColor(sf::Color::Black);
    sf::FloatRect textRect = t.getLocalBounds();
    t.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    t.setPosition(sf::Vector2f(2750 / 2.0f, 250 / 2.0f));
    window.draw(t);

    ///if pressed: clear all string
    if(r2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            for (int i = 0; i < sizeof(input)/sizeof(input[0]); ++i)
                input[i] = "";
}

string SFML_Process::getInput1()
{
    return input[0];
}

string SFML_Process::getInput2()
{
    return input[1];
}

void SFML_Process::BFS_Output(sf::RenderWindow& window)
{
    outputProcess::getInput();
    //BFS
    displayText(window,"BFS:", 1, 1200, 800, true);
    if(!stop){
        displayOnce=outputProcess::getBFSOutput();
    }
    else{
        displayText(window,displayOnce, 2, 1300, 755, false);
    }
}

void SFML_Process::DFS_Output(sf::RenderWindow &window)
{
    outputProcess::getInput();
    //DFS
    displayText(window,"DFS:", 1, 1200, 800, true);
    if(!stop){
        displayOnce=outputProcess::getDFSOutput();
    }
    else{
        displayText(window,displayOnce, 2, 1300, 755, false);
    }
}




