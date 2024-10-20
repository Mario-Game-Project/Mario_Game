#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    int height = 32 * 25;
    int width = int(16.0 / 9.0 * height);

    sf::RenderWindow window(sf::VideoMode(width, height), "Mario ", sf::Style::Close);

    // Setting icon to window title-bar :
    sf::Image icon;
    if (icon.loadFromFile("./Assets/Icon/logo-0.png")) {  // Replace "icon.png" with the path to your icon file
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }

    window.setVerticalSyncEnabled(true); // enabling vSync


    /*========================== Game Loop =================================*/
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}
