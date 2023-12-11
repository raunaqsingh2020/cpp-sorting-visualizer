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
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Sorting Visualizer");

    std::vector<int> v(100);
    std::iota(v.begin(), v.end(), 1);
    auto rng = std::default_random_engine{};
    std::shuffle(v.begin(), v.end(), rng);

    bool is_sorted = false;

    std::vector<std::string> options = {"Insertion Sort", "Merge Sort", "Quick Sort"};
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) std::cout << "Error loading font\n";

    DropdownMenu dropdown(font, options);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else {
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    dropdown.handleEvent(event);
                    if (!dropdown.getIsOpen()) {
                        is_sorted = false;
                        std::shuffle(v.begin(), v.end(), rng);
                    }
                }
            }
        }

        dropdown.update();
        window.clear();
        dropdown.render(window);
        window.display();

        int index = dropdown.getSelectedIndex();
        if (index == 0 && !is_sorted)
        {
            render(window, v, 0, is_sorted, dropdown);
            insertion_sort(window, v, is_sorted, dropdown);
        }
        else if (index == 1 && !is_sorted)
        {
            render(window, v, 0, is_sorted, dropdown);
            merge_sort(window, v, 0, v.size() - 1, is_sorted, dropdown);
        }
        else if (index == 2 && !is_sorted)
        {
            render(window, v, 0, is_sorted, dropdown);
            quick_sort(window, v, 0, v.size() - 1, is_sorted, dropdown);
        }
    }
}