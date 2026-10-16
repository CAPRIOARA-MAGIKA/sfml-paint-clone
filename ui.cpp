#include "ui.hpp"
#include "config.hpp"
#include <iostream>

UI::UI() 
{
    init();
}

void UI::init(){
    topBarInit();
    colorsInit();
}

void UI::topBarInit(){
    sf::Color topBarColor(128,128,128);
    topBar.setFillColor(topBarColor);
    topBar.setOrigin({0.0f, 0.0f});
    topBar.setPosition({0.0f, 0.0f});
    topBar.setSize({GameConfig::SCREEN_RESOLUTION_X, GameConfig::UI_OFFSET_Y});
}

void UI::colorsInit(){
    std::vector<sf::Color> colors = {
        sf::Color::Black, sf::Color::White,
        sf::Color(127, 127, 127), sf::Color(195, 195, 195),
        sf::Color(136, 0, 21), sf::Color(185, 122, 87),
        sf::Color::Red, sf::Color(255, 174, 201),
        sf::Color(255, 127, 39), sf::Color(255, 201, 14),
        sf::Color::Yellow, sf::Color(239, 228, 176),
        sf::Color::Green, sf::Color(181, 230, 29),
        sf::Color(0, 162, 232), sf::Color(153, 217, 234),
        sf::Color(63, 72, 204), sf::Color(112, 146, 190),
        sf::Color(163, 73, 164), sf::Color(200, 191, 231)
    };

    for(int i = 0; i < GameConfig::UI_BUTTONS_COLORS_NUMBER; i++){
        ColorButtons currentColorButton;
        currentColorButton.color = colors[i];
        
        currentColorButton.button.setSize({GameConfig::UI_BUTTONS_COLORS_SIZE, GameConfig::UI_BUTTONS_COLORS_SIZE});
        currentColorButton.button.setFillColor(currentColorButton.color);
        currentColorButton.button.setOutlineColor(sf::Color::Black);
        currentColorButton.button.setOutlineThickness(5);
        currentColorButton.button.setPosition({
            GameConfig::UI_BUTTONS_COLORS_STARTINGPOS_X + (i/2) * (GameConfig::UI_BUTTONS_COLORS_GAP_SIZE + GameConfig::UI_BUTTONS_COLORS_SIZE),
            GameConfig::UI_BUTTONS_COLORS_STARTINGPOS_Y + (i%2) * (GameConfig::UI_BUTTONS_COLORS_GAP_SIZE + GameConfig::UI_BUTTONS_COLORS_SIZE)
        });

        cButtons.push_back(currentColorButton);
    }
}

bool UI::mouseInUI(sf::Vector2f mousePos){
    if (mousePos.y < GameConfig::UI_OFFSET_Y){
        return true;
    }
    return false;
}

bool UI::pressedColor(sf::Vector2f mousePos){
    for(int i = 0; i < GameConfig::UI_BUTTONS_COLORS_NUMBER; i++){
        if(cButtons[i].button.getGlobalBounds().contains(mousePos)){
            selectedColor = getColor(i);
            return true;
        }
    }
    return false;
}

void UI::render(sf::RenderWindow& window){
    window.draw(topBar);
    for(int i = 0; i<cButtons.size(); i++){
        window.draw(cButtons[i].button);
    }
}