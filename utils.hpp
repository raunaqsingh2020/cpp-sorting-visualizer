/*
 * utils.hpp
 */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>

#include <SFML/Graphics.hpp>
#include "dropdown.hpp"

void render(sf::RenderWindow &window, std::vector<int> &v, int curr_index, bool is_sorted, DropdownMenu &dropdown);

#endif
