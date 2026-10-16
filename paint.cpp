#include "paint.hpp"
#include <iostream>

Paint::Paint() : window(sf::VideoMode({GameConfig::SCREEN_RESOLUTION_X, GameConfig::SCREEN_RESOLUTION_Y}), "Paint_Clone"),
                 canvas({GameConfig::SCREEN_RESOLUTION_X, GameConfig::SCREEN_RESOLUTION_Y - GameConfig::UI_OFFSET_Y}),
                 canvasSprite(canvas.getTexture()),
                 isDrawing(false),
                 isErasing(false)
{
    canvas.clear(sf::Color::White);
    canvas.display();
    canvasSprite.setPosition({0.0f, GameConfig::UI_OFFSET_Y});
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
    if(isDrawing){
        brushDraw(currentColor);
    }
    if(isErasing){
        brushDraw(sf::Color::White);
    }
}

void Paint::render(){
    window.clear(sf::Color::White);

    window.draw(canvasSprite);
    ui.render(window);

    window.display();
}

void Paint::handleWindowClose(const sf::Event& event){
    if(event.is<sf::Event::Closed>()){
        window.close();
    }
}

void Paint::handleInput(const sf::Event& event){
    if(const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()){
        if(mousePressed->button == sf::Mouse::Button::Left){
            getMousePos();
            if(ui.mouseInUI(mousePos)){
                if(ui.pressedColor(mousePos)){
                    currentColor = ui.selectedColor;
                }
            } else {
                isDrawing = true;
            }
        }
    }
    if(const auto* mouseReleased = event.getIf<sf::Event::MouseButtonReleased>()){
        if(mouseReleased->button == sf::Mouse::Button::Left){
            isDrawing = false;
        }
    }
    if(const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()){
        if(mousePressed->button == sf::Mouse::Button::Right){
            isErasing = true;
        }
    }
    if(const auto* mouseReleased = event.getIf<sf::Event::MouseButtonReleased>()){
        if(mouseReleased->button == sf::Mouse::Button::Right){
            isErasing = false;
        }
    }
}

void Paint::getMousePos(){
    sf::Vector2i mousePixelPos = sf::Mouse::getPosition(window);
    mousePos = window.mapPixelToCoords(mousePixelPos);
}

void Paint::brushDraw(sf::Color color){
    getMousePos();
    sf::Vector2f mouseCanvasPos = {
        mousePos.x,
        mousePos.y - GameConfig::UI_OFFSET_Y
    };
    brush.setFillColor(color);
    brush.setOrigin({10.0f, 10.0f});
    brush.setRadius(10.0f);
    brush.setPosition(mouseCanvasPos); 

    canvas.draw(brush);
    canvas.display();
}

// make different structs for line, brush, pencil, fill_bucket (styles of drawin -> struct DrawStyle) in paint.hpp and define in paint.cpp