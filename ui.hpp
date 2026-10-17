#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct ColorButtons{
    sf::RectangleShape button;
    sf::Color color;
};

struct UI {
    sf::RectangleShape topBar;
    sf::RectangleShape sizeBar;
    sf::RectangleShape sizeBarLimiter;
    sf::CircleShape sizeBarBall;
    std::vector<ColorButtons> cButtons;
    bool isDraggingSizeBall;
    float drawSize;

    
    sf::Color selectedColor;

    UI();
    
    void init();
    void topBarInit();
    void colorsInit();
    void sizeBarInit();

    sf::Color getColor(int index) const {return cButtons[index].color;}

    bool mouseInUI(sf::Vector2f mousePos);
    bool pressedColor(sf::Vector2f mousePos);
    bool pressedSizeLimiter(sf::Vector2f mousePos);
    
    void setDrawSize(sf::Vector2f mousePos);

    void render(sf::RenderWindow& window);
    void update(sf::Vector2f mousePos);
    void handleEvents(const sf::Event& event);
};