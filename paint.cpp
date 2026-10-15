#include "paint.hpp"
#include <iostream>

Paint::Paint() : window(sf::VideoMode({GameConfig::SCREEN_RESOLUTION_X, GameConfig::SCREEN_RESOLUTION_Y}), "Paint_Clone"),
                 canvas({GameConfig::SCREEN_RESOLUTION_X, GameConfig::SCREEN_RESOLUTION_Y}),
                 canvasSprite(canvas.getTexture()),
                 isDrawing(false)
{
    canvas.clear(sf::Color::White);
    canvas.display();
    canvasSprite.setPosition({0.0f, 0.0f});
}

void Paint::run(){
    while(window.isOpen()){
        processEvents();

        update();

        render();
    }
}

void Paint::processEvents(){
    while(const std::optional<sf::Event> event = window.pollEvent()){
        handleWindowClose(*event);

        handleInput(*event);
    }
}

void Paint::update(){
    brushDraw();
}

void Paint::render(){
    window.clear(sf::Color::White);

    window.draw(canvasSprite);
    window.draw(brush);

    window.display();
}

void Paint::handleWindowClose(const sf::Event& event){
    if(event.is<sf::Event::Closed>()){
        window.close();
    }
}

void Paint::handleInput(const sf::Event& event){
    if(event.is<sf::Event::MouseButtonPressed>()){
        isDrawing = true;
    }
    if(event.is<sf::Event::MouseButtonReleased>()){
        isDrawing = false;
    }
}

void Paint::brushDraw(){
    if(isDrawing){
        sf::Vector2i mousePixelPos = sf::Mouse::getPosition(window);
        sf::Vector2f mouseActualPos = window.mapPixelToCoords(mousePixelPos);
        brush.setFillColor(sf::Color::Red);
        brush.setOrigin({10.0f, 10.0f});
        brush.setRadius(10.0f);
        brush.setPosition(mouseActualPos); 

        canvas.draw(brush);
        canvas.display();
    }
}

// make different structs for line, brush, pencil, fill_bucket (styles of drawin -> struct DrawStyle) in paint.hpp and define in paint.cpp