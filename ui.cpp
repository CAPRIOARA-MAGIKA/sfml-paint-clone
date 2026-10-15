#include "ui.hpp"
#include "config.hpp"

UI::UI() 
{
    topBar.setFillColor(sf::Color::Black);
    topBar.setOrigin({0.0f, 0.0f});
    topBar.setPosition({0.0f, 0.0f});
    topBar.setSize({GameConfig::SCREEN_RESOLUTION_X, GameConfig::UI_OFFSET_Y});
}

void UI::render(sf::RenderWindow& window){
    window.draw(topBar);
}