#include "dropdown.hpp"

DropdownMenu::DropdownMenu(sf::Font& font, std::vector<std::string> options) {
    isOpen = false;
    selectedIndex = 0;

    // set up dropdown background
    background.setSize(sf::Vector2f(200, 120));
    background.setFillColor(sf::Color::White);
    background.setOutlineColor(sf::Color::Black);
    background.setOutlineThickness(1.0f);

    // set up selected text
    selectedText.setFont(font);
    selectedText.setCharacterSize(16);
    selectedText.setFillColor(sf::Color::Black);

    // set up options
    for (const auto& option : options) {
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::Black);
        text.setString(option);
        optionsTexts.push_back(text);
    }

    background.setPosition(900, 10);
    selectedText.setPosition(900, 10);
    for (size_t i = 0; i < optionsTexts.size(); ++i) {
        optionsTexts[i].setPosition(900, 15 + static_cast<float>((i + 1) * 30));
    }
}

void DropdownMenu::update() {
    selectedText.setString(optionsTexts[selectedIndex].getString());
    for (size_t i = 0; i < optionsTexts.size(); ++i) {
        optionsTexts[i].setPosition(900, 15 + static_cast<float>((i + 1) * 30));
    }
}

void DropdownMenu::handleEvent(sf::Event& event) {
    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
    if (isOpen) { // dropdown open, mouse is inside an option
        for (size_t i = 0; i < optionsTexts.size(); ++i) {
            if (optionsTexts[i].getGlobalBounds().contains(mousePos)) {
                selectedIndex = static_cast<int>(i);
                isOpen = false;
                break;
            }
        }
    } else { // mouse is inside the background --> open dropdown
        if (background.getGlobalBounds().contains(mousePos)) {
            isOpen = true;
        }
    }
}

void DropdownMenu::render(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(selectedText);

    if (isOpen) { // render options texts when dropdown is open
        for (const auto& text : optionsTexts) {
            window.draw(text);
        }
    }
}

int DropdownMenu::getSelectedIndex() const {
    return selectedIndex;
}

bool DropdownMenu::getIsOpen() const {
    return isOpen;
}