/*
 * main.cpp
 */

#include <iostream>
#include <numeric>
#include <random>

#include "algorithms.hpp"
#include "dropdown.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 640), "Sorting Visualizer");

    std::vector<int> v(100);
    std::iota(v.begin(), v.end(), 1);
    auto rng = std::default_random_engine{};
    std::shuffle(v.begin(), v.end(), rng);

    bool is_sorted = false;

    std::vector<std::string> options = {"Insertion Sort", "Merge Sort", "Bubble Sort"};
    DropdownMenu dropdown = DropdownMenu(options);
    dropdown.render(window);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                dropdown.update_selection(event);
                dropdown.render(window);
            }
        }

<<<<<<< HEAD
        // if (!is_sorted)
        // {
        //     render(window, v, 0, is_sorted);
        //     insertion_sort(window, v, is_sorted);
        //     // merge_sort(window, v, 0, v.size() - 1, is_sorted);
        // }
=======
        if (!is_sorted)
        {
            render(window, v, 0, is_sorted);
            // insertion_sort(window, v, is_sorted);
            // merge_sort(window, v, 0, v.size() - 1, is_sorted);
            quick_sort(window, v, 0, v.size() - 1, is_sorted);
        }
>>>>>>> 2ce14308fed9db97cfd04c949a38051740513a88
    }
}