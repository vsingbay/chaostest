// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>



// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;


/*// select the font
text.setFont(font); // font is a sf::Font

// set the string to display
text.setString("Hello world");

// set the character size
text.setCharacterSize(24); // in pixels, not points!

// set the color
text.setFillColor(sf::Color::Red);

// set the text style
text.setStyle(sf::Text::Bold | sf::Text::Underlined);

...

// inside the main loop, between window.clear() and window.display()
window.draw(text);
*/
int main()
{
   
    // Create a video mode object
    VideoMode vm(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);
    // Create and open a window for the game
    RenderWindow window(vm, "Chaos Game!!", Style::Default);

    View view;
	view.setSize(1920.0, 1080.0);
	view.setCenter(1920.0 / 2.0, 1080.0 / 2.0);
	window.setView(view);

    vector<Vector2f> vertices;
    vector<Vector2f> points;
    sf::Font font;

    sf::Text text;

   //font.loadFromFile("Star Shield.ttf");
    if (!font.loadFromFile("fonts/KOMIKAP_.ttf"))
    {
        cout << "error" << endl;
    }
    //sf::Text text;
    text.setFont(font);
    text.setString("Click any three points");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(0, 0);
    while (window.isOpen())
    {
       // window.draw(text);

        /*
        ****************************************
        Handle the players input
        ****************************************
        */

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                // Quit the game when the window is closed
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if (vertices.size() < 3)
                    {
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    else if (points.size() == 0)
                    {
                        ///fourth click
                        ///push back to points vector
                        points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));

                    }
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        /*
        ****************************************
        Update
        ****************************************
        */

        // Run program: Ctrl + F5 or Debug > Start Without Debugging menu
        // Debug program: F5 or Debug > Start Debugging menu
        if (points.size() > 0)
        {
            //vector<Vector2f> randomVertex;
            int randVertex = rand() % 3;
            //randomVertex.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
            float pointx = (points[points.size() - 1].x + vertices[randVertex].x) / 2;
            float pointy = (points[points.size() - 1].y + vertices[randVertex].y) / 2;
            points.push_back(Vector2f(pointx, pointy));

            ///generate more point(s)
            ///select random vertex
            ///calculate midpoint between random vertex and the last point in the vector
            ///push back the newly generated coord.
        }

        // Tips for Getting Started: 
        //   1. Use the Solution Explorer window to add/manage files
        //   2. Use the Team Explorer window to connect to source control
        //   3. Use the Output window to see build output and other messages
        //   4. Use the Error List window to view errors
        //   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
        //   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
                /*
                ****************************************
                Draw
                ****************************************
                */
        window.clear();
        window.draw(text);

        for (int i = 0; i < vertices.size(); i++)
        {
            RectangleShape rect(Vector2f(10, 10));
            rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            rect.setFillColor(Color::Blue);
            window.draw(rect);
        }

        for (int i = 0; i < points.size(); i++)
        {
            RectangleShape rect(Vector2f(10, 10));
            rect.setPosition(Vector2f(points[i].x, points[i].y));
            rect.setFillColor(Color::Blue);
            window.draw(rect);
        }
       
       // window.draw(text);

        window.display();
    }

}
