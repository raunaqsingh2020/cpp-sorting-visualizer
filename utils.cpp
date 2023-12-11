/*
 * utils.cpp
 */

#include "utils.hpp"

void render(
    sf::RenderWindow &window,
    DropdownMenu &dropdown,
    std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> &v,
    std::tuple<int, int, int> &curr_index,
    std::tuple<bool, bool, bool> &is_sorted)
{
    window.clear();

    auto &[v1, v2, v3] = v;
    int index = dropdown.getSelectedIndex();
    if (index == 3)
    { // ALL
        for (auto i = 0; i < v1.size(); i++)
        {
            sf::RectangleShape block(sf::Vector2f(10, v1[i]));
            block.setPosition(i * 12, 200 - v1[i]);
            block.setFillColor(std::get<0>(is_sorted) ? sf::Color::Green : (i == std::get<0>(curr_index) ? sf::Color::Magenta : sf::Color::White));
            window.draw(block);
        }

        for (auto i = 0; i < v2.size(); i++)
        {
            sf::RectangleShape block(sf::Vector2f(10, v2[i]));
            block.setPosition(i * 12, 400 - v2[i]);
            block.setFillColor(std::get<1>(is_sorted) ? sf::Color::Green : (i == std::get<1>(curr_index) ? sf::Color::Magenta : sf::Color::White));
            window.draw(block);
        }

        for (auto i = 0; i < v3.size(); i++)
        {
            sf::RectangleShape block(sf::Vector2f(10, v3[i]));
            block.setPosition(i * 12, 600 - v3[i]);
            block.setFillColor(std::get<2>(is_sorted) ? sf::Color::Green : (i == std::get<2>(curr_index) ? sf::Color::Magenta : sf::Color::White));
            window.draw(block);
        }
    }
    else if (index != -1)
    {
        std::vector<int> &v_i = index == 0 ? v1 : index == 1 ? v2
                                                             : v3;
        int &curr_index_i = index == 0 ? std::get<0>(curr_index) : index == 1 ? std::get<1>(curr_index)
                                                                              : std::get<2>(curr_index);
        bool &is_sorted_i = index == 0 ? std::get<0>(is_sorted) : index == 1 ? std::get<1>(is_sorted)
                                                                             : std::get<2>(is_sorted);
        for (auto i = 0; i < v_i.size(); i++)
        {
            sf::RectangleShape block(sf::Vector2f(10, 3 * v_i[i]));
            block.setPosition(i * 12, 600 - 3 * v_i[i]);
            block.setFillColor(is_sorted_i ? sf::Color::Green : (i == curr_index_i ? sf::Color::Magenta : sf::Color::White));
            window.draw(block);
        }
    }

    dropdown.render(window);
    window.display();
}