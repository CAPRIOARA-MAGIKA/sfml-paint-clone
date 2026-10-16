#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct ColorButtons{
    sf::RectangleShape button;
    sf::Color color;
};

struct UI {
    sf::RectangleShape topBar;
    std::vector<ColorButtons> cButtons;
    
    sf::Color selectedColor;

    UI();
    
    void init();
    void topBarInit();
    void colorsInit();
    sf::Color getColor(int index) const {return cButtons[index].color;}

    bool mouseInUI(sf::Vector2f mousePos);
    bool pressedColor(sf::Vector2f mousePos);

    void render(sf::RenderWindow& window);
    void handleEvents(const sf::Event& event);
};