/*
 * algorithms.hpp
 */

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <concepts>

#include <SFML/Graphics.hpp>
#include "utils.hpp"

// template <std::totally_ordered T>
template <typename T>
void insertion_sort(sf::RenderWindow &window, std::vector<T> &v, bool &is_sorted, DropdownMenu &dropdown);

// template <std::totally_ordered T>
template <typename T>
void merge_sort(sf::RenderWindow &window, std::vector<T> &v, int start, int end, bool &is_sorted, DropdownMenu &dropdown);

// template <std::totally_ordered T>
template <typename T>
void quick_sort(sf::RenderWindow &window, std::vector<T> &v, int start, int end, bool &is_sorted, DropdownMenu &dropdown);

#include "algorithms.tpp"

#endif
