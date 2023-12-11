#ifndef DROPDOWN_HPP
#define DROPDOWN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class DropdownMenu
{
private:
    bool isOpen;
    sf::RectangleShape background;
    int selectedIndex;
    sf::Text selectedText;
    std::vector<sf::Text> optionsTexts;
public:
    DropdownMenu(sf::Font& font, std::vector<std::string> options);
    void update();
    void handleEvent(sf::Event& event);
    void render(sf::RenderWindow& window);
    int getSelectedIndex() const;
    bool getIsOpen() const;
};

#endif