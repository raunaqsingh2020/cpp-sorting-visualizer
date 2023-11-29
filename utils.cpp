/*
 * utils.cpp
 */

#include "utils.hpp"

void render(sf::RenderWindow &window, std::vector<int> &v, int curr_index, bool is_sorted)
{
    sf::sleep(sf::milliseconds(5)); // slight delay for visualization
    window.clear();

    for (auto i = 0; i < v.size(); i++)
    {
        sf::RectangleShape block(sf::Vector2f(10, v[i]));
        block.setPosition(i * 12, 720 - v[i]);
        block.setFillColor(is_sorted ? sf::Color::Green : (i == curr_index ? sf::Color::Magenta : sf::Color::White));
        window.draw(block);
    }

    window.display();
}