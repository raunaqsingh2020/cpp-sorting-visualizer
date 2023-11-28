/*
 * utils.cpp
 */

#include "utils.hpp"

void render(sf::RenderWindow &window, std::vector<int> &v, int curr_index)
{
    sf::sleep(sf::milliseconds(1)); // slight delay for visualization
    window.clear();

    for (auto i = 0; i < v.size(); i++)
    {
        sf::RectangleShape block(sf::Vector2f(10, v[i]));
        block.setPosition(i * 12, 600 - v[i]);
        block.setFillColor(i == curr_index ? sf::Color::Red : sf::Color::White);
        window.draw(block);
    }

    window.display();
}