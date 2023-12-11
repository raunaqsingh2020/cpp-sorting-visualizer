/*
 * utils.hpp
 */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <tuple>

#include <SFML/Graphics.hpp>
#include "dropdown.hpp"

void render(
    sf::RenderWindow &window,
    DropdownMenu &dropdown,
    std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> &v,
    std::tuple<int, int, int> &curr_index,
    std::tuple<bool, bool, bool> &is_sorted);

#endif
