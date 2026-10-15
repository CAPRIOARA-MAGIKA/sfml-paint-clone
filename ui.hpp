#pragma once
#include <SFML/Graphics.hpp>

struct UI {
    sf::RectangleShape topBar;
    
    sf::RectangleShape colorRedButton;
    sf::RectangleShape colorBlueButton;
    sf::RectangleShape colorGreenButton;
    
    sf::Color selectedColor;

    UI();
    void render(sf::RenderWindow& window);
    void handleEvents(const sf::Event& event);
};