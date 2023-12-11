/*
 * algorithms.hpp
 */

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <concepts>

#include <SFML/Graphics.hpp>
#include "utils.hpp"

#include <thread>
#include <chrono>

template <typename T>
void insertion_sort(sf::RenderWindow &window,
                    DropdownMenu &dropdown,
                    std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> &v,
                    std::tuple<int, int, int> &curr_index,
                    std::tuple<bool, bool, bool> &is_sorted);

template <typename T>
void merge_sort(sf::RenderWindow &window,
                DropdownMenu &dropdown,
                std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> &v,
                std::tuple<int, int, int> &curr_index,
                std::tuple<bool, bool, bool> &is_sorted,
                int start,
                int end);

template <typename T>
void quick_sort(sf::RenderWindow &window,
                DropdownMenu &dropdown,
                std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> &v,
                std::tuple<int, int, int> &curr_index,
                std::tuple<bool, bool, bool> &is_sorted,
                int start,
                int end);

#include "algorithms.tpp"

#endif
