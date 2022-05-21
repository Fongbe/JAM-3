/*
** EPITECH PROJECT, 2022
** libSfml
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Vector.hpp"
#include <string>
#include <vector>
#include <memory>

namespace grf
{
    class Sprite {
        public:
            Sprite();
            Sprite(const std::string &file);
            Sprite(const std::string &file, Vector position, Vector proportion);
            ~Sprite();
            sf::Sprite getSprite(void);
            void setOrigin(Vector origin);
            void setPosition(Vector position);
            void setAngle(float angle);
            void setScale(Vector scale);
            bool isDrawable(void);

        private:
            bool drawable;
            sf::Sprite _sprite;
            sf::Texture _texture;
    };

    class SpriteSheet {
        public:
            SpriteSheet();
            SpriteSheet(const std::string &name, const std::string &file, unsigned int imageNumber, int width, int height, int x, int y);
            ~SpriteSheet();
            std::vector<std::shared_ptr<Sprite>> getSheet(void);
            unsigned int getSize(void);
            void setOrigin(Vector origin);
            void setPosition(Vector position);
            void setAngle(float angle);
            void setScale(Vector scale);
            std::string name;
        
        private:
            std::vector<std::shared_ptr<Sprite>> _sheet;
            unsigned int _size;
    };
}

#endif /* !SPRITE_HPP_ */