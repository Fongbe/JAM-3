/*
** EPITECH PROJECT, 2022
** libSfml
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Sprite.hpp"
#include "Event.hpp"
#include <string>

namespace grf
{
    class Window {
        public:
            Window();
            ~Window();
            void init(int width, int height, std::string title);
            void destroy(void);
            void clear(void);
            void update(void);
            bool isRunning(void);
            Event getEvent(void);

            void drawSprite(Sprite sprite, Vector pos);
            void drawSprite(SpriteSheet spriteSheet, unsigned int imageIndex, Vector pos);

            void drawSpriteExt(Sprite sprite, Vector pos, int imageAngle, Vector scale);
            void drawSpriteExt(SpriteSheet spriteSheet, unsigned int imageIndex, Vector pos, float imageAngle, Vector scale);

        //private:
            sf::RenderWindow *_wn;
    };
}

#endif /* !WINDOW_HPP_ */