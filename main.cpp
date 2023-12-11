/*
 * main.cpp
 */

#include <iostream>
#include <numeric>
#include <random>
#include <thread>
#include <tuple>

#include "algorithms.hpp"
#include "dropdown.hpp"

void extra_render_period(sf::RenderWindow &window,
                         DropdownMenu &dropdown,
                         std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> &v,
                         std::tuple<int, int, int> &curr_index,
                         std::tuple<bool, bool, bool> &is_sorted)
{
    auto now = std::chrono::steady_clock::now;
    using namespace std::chrono_literals;
    auto duration = 3s;
    auto start = now();
    while ((now() - start) < duration)
        render(window, dropdown, v, curr_index, is_sorted);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Sorting Visualizer");

    std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> v;
    auto rng = std::default_random_engine{};
    const int size = 100;
    auto &[v1, v2, v3] = v;
    v1.resize(size);
    v2.resize(size);
    v3.resize(size);
    std::iota(v1.begin(), v1.end(), 1);
    std::iota(v2.begin(), v2.end(), 1);
    std::iota(v3.begin(), v3.end(), 1);
    std::shuffle(v1.begin(), v1.end(), rng);
    std::shuffle(v2.begin(), v2.end(), rng);
    std::shuffle(v3.begin(), v3.end(), rng);

    std::tuple<int, int, int> curr_index{-1, -1, -1};
    std::tuple<bool, bool, bool> is_sorted{false, false, false};

    std::vector<std::string> options = {"Insertion Sort", "Merge Sort", "Quick Sort", "All"};
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf"))
        std::cout << "Error loading font\n";

    DropdownMenu dropdown(font, options);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else
            {
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                {
                    dropdown.handleEvent(event);
                    if (!dropdown.getIsOpen())
                    {
                        is_sorted = {false, false, false};
                        curr_index = {-1, -1, -1};
                        std::shuffle(v1.begin(), v1.end(), rng);
                        std::shuffle(v2.begin(), v2.end(), rng);
                        std::shuffle(v3.begin(), v3.end(), rng);
                    }
                }
            }
        }

        dropdown.update();
        window.clear();
        dropdown.render(window);
        window.display();

        int index = dropdown.getSelectedIndex();
        if (index == 0 && !std::get<0>(is_sorted))
        {
            render(window, dropdown, v, curr_index, is_sorted);
            std::thread t(insertion_sort<int>, std::ref(window), std::ref(dropdown), std::ref(v), std::ref(curr_index), std::ref(is_sorted));
            while (window.isOpen() && !std::get<0>(is_sorted))
                render(window, dropdown, v, curr_index, is_sorted);
            extra_render_period(window, dropdown, v, curr_index, is_sorted);

            t.join();
        }
        else if (index == 1 && !std::get<1>(is_sorted))
        {
            render(window, dropdown, v, curr_index, is_sorted);
            std::thread t(merge_sort<int>, std::ref(window), std::ref(dropdown), std::ref(v), std::ref(curr_index), std::ref(is_sorted), 0, size - 1);
            while (window.isOpen() && !std::get<1>(is_sorted))
                render(window, dropdown, v, curr_index, is_sorted);
            extra_render_period(window, dropdown, v, curr_index, is_sorted);

            t.join();
        }
        else if (index == 2 && !std::get<2>(is_sorted))
        {
            render(window, dropdown, v, curr_index, is_sorted);
            std::thread t(quick_sort<int>, std::ref(window), std::ref(dropdown), std::ref(v), std::ref(curr_index), std::ref(is_sorted), 0, size - 1);
            while (window.isOpen() && !std::get<2>(is_sorted))
                render(window, dropdown, v, curr_index, is_sorted);
            extra_render_period(window, dropdown, v, curr_index, is_sorted);

            t.join();
        }
        else if (index == 3 && (!std::get<0>(is_sorted) || !std::get<1>(is_sorted) || !std::get<2>(is_sorted)))
        {
            render(window, dropdown, v, curr_index, is_sorted);
            std::thread t1(insertion_sort<int>, std::ref(window), std::ref(dropdown), std::ref(v), std::ref(curr_index), std::ref(is_sorted));
            std::thread t2(merge_sort<int>, std::ref(window), std::ref(dropdown), std::ref(v), std::ref(curr_index), std::ref(is_sorted), 0, size - 1);
            std::thread t3(quick_sort<int>, std::ref(window), std::ref(dropdown), std::ref(v), std::ref(curr_index), std::ref(is_sorted), 0, size - 1);
            while (window.isOpen() && (!std::get<0>(is_sorted) || !std::get<1>(is_sorted) || !std::get<2>(is_sorted)))
                render(window, dropdown, v, curr_index, is_sorted);
            extra_render_period(window, dropdown, v, curr_index, is_sorted);

            t1.join();
            t2.join();
            t3.join();
        }
    }
}