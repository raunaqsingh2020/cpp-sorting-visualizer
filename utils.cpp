/*
 * utils.cpp
 */

#include "utils.hpp"

void render(sf::RenderWindow &window, std::vector<int> &v)
{
    window.clear();

    for (auto i = 0; i < v.size(); i++)
    {
        sf::RectangleShape block(sf::Vector2f(10, v[i]));
        block.setPosition(i * 12, 600 - v[i]);
        // block.setFillColor(sorted || i == index ? sf::Color::Green : sf::Color::White);
        window.draw(block);
    }

    window.display();
}