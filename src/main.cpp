#include <SFML/Graphics.hpp>
#include <Tetris.h>

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(400, 700), "Tetris", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(0, 0, 8));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();

        window.display();
    }

    return 0;
}
