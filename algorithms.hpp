/*
 * algorithms.hpp
 */

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <concepts>

template <std::totally_ordered T>
void insertion_sort(std::vector<T> v);

#include "algorithms.tpp"

#endif
