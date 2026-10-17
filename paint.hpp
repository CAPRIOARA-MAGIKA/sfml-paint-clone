#pragma once
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "ui.hpp"
#include <optional>

class Paint{
    public:

        Paint();
        sf::RenderWindow window;

        void run();

    private:

        UI ui;
        
        sf::RenderTexture canvas;
        sf::Sprite canvasSprite;
        sf::CircleShape brush;
        bool isDrawing;
        bool isErasing;
        sf::Vector2f mousePos;
        sf::Color currentColor;
        float drawSize;

        void processEvents();
        void update();
        void render();

        void handleWindowClose(const sf::Event& event);
        void handleInput(const sf::Event& event);

        void getMousePos();
        void brushDraw(sf::Color color);
};
