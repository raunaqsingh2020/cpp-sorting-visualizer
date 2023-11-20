# CIS 1901 C++ Final Project - Charis Gao, Raunaq Singh

## Proposal


For our project, we will build a sorting algorithm visualizer. Specifically, we will implement a few common sorting algorithms (e.g. insertion sort, merge sort, quick sort, bubble sort, etc.) and have a visual interface display the executions of those algorithms on vectors of comparable elements so that users can interpret how they work. 

We will have it so that users can specify what types of (comparable) elements the vectors consist of (integers, floats, strings, etc.), which will require us to use templated functions in our program as well as concepts. We will also have to utilize different containers from the STL (such as `std::priority_queue`) in order to implement some of the sorting algorithms. We plan on utilizing the SFML (Simple and Fast Multimedia) library for the GUI. We are currently unsure what classes will be required (if any) for doing so; however, we will make sure to structure our code in a well-organized manner (perhaps having a main.cpp file that holds the code for taking any user command line inputs and executing the GUI, and an algorithms.cpp file for the actual sorting algorithm implementations). 

Time permitting, we might explore concurrency and add the ability to change the number of cores / number of elements to sort to visualize which sorts are parallelizable.

We expect to spend around half the time implementing the sorting algorithms themselves and the other half getting the GUI to work and update properly to display the sorting algorithms as they run. We will split this work evenly so that both of us get to work on the different sorting algorithms and on the GUI.
