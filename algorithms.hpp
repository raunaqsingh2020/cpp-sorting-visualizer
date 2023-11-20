/*
 * algorithms.hpp
 */

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <concepts>

template <typename T>
void insertion_sort(std::vector<T> v)
    requires std::totally_ordered<T>;

#include "algorithms.tpp"

#endif
