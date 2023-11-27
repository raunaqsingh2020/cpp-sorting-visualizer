/*
 * algorithms.hpp
 */

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <concepts>

#include <SFML/Graphics.hpp>

template <std::totally_ordered T>
void insertion_sort(sf::RenderWindow &window, std::vector<T> &v, bool &is_sorted);

#include "algorithms.tpp"

#endif
