#include <SFML/Graphics.hpp>
#include <TetrisConstants.h>
#include <Tetris.h>

int main(int argc, char const *argv[])
{
    using namespace TetrisConstants;

    sf::RenderWindow window(sf::VideoMode(TETRIS_WIDTH + 1, TETRIS_HEIGHT + 1), "Tetris", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(0, 0, 8));

    Tetris tetris(&window);

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
        tetris.update();
        window.display();
    }

    return 0;
}
