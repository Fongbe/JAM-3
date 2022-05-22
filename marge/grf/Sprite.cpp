/*
** EPITECH PROJECT, 2022
** libSfml
** File description:
** Sprite
*/

#include "Sprite.hpp"
#include <iostream>

grf::Sprite::Sprite()
{
    drawable = false;
}

grf::Sprite::Sprite(const std::string &file)
{
    if (!_texture.loadFromFile(file)) {
        std::cerr << "Error loading " << file << std::endl;
        drawable = false;
    } else {
        _sprite.setTexture(_texture);
        drawable = true;
    }
}

grf::Sprite::Sprite(const std::string &file, grf::Vector po, grf::Vector pr)
{
    if (!_texture.loadFromFile(file, sf::IntRect(po.x, po.y, pr.x, pr.y))) {
        std::cerr << "Error loading " << file << std::endl;
        drawable = false;
    } else {
        _sprite.setTexture(_texture);
        drawable = true;
    }
}

grf::Sprite::~Sprite()
{
}

void grf::Sprite::setPosition(grf::Vector v)
{
    _sprite.setPosition(sf::Vector2f(v.x, v.y));
}

sf::Sprite grf::Sprite::getSprite(void)
{
    return _sprite;
}

void grf::Sprite::setOrigin(grf::Vector v)
{
    _sprite.setOrigin(sf::Vector2f(v.x, v.y));
}

void grf::Sprite::setAngle(float angle)
{
    _sprite.setRotation(angle);
}

void grf::Sprite::setScale(Vector scale)
{
    _sprite.setScale(sf::Vector2f(scale.x, scale.y));
}

bool grf::Sprite::isDrawable(void)
{
    return drawable;
}

// -----------------------------------------------------------------------------------------------------------------------

grf::SpriteSheet::SpriteSheet(void)
{
    _size = 0;
}

grf::SpriteSheet::SpriteSheet(const std::string &n, const std::string &file, unsigned int nb, int w, int h, int x, int y)
{
    name = n;
    for (unsigned int i = 0; i < nb; i++) {
        std::shared_ptr<grf::Sprite> spr = std::make_shared<grf::Sprite>(file, grf::Vector(i*w+x, y), grf::Vector(w, h));
        _sheet.push_back(spr);
    }
    _size = nb;
}

grf::SpriteSheet::~SpriteSheet(void)
{
}

std::vector<std::shared_ptr<grf::Sprite>> grf::SpriteSheet::getSheet(void)
{
    return _sheet;
}

unsigned int grf::SpriteSheet::getSize(void)
{
    return _size;
}

void grf::SpriteSheet::setOrigin(grf::Vector v)
{
    for (size_t i = 0; i < _sheet.size(); i++)
        _sheet[i]->setOrigin(v);
}

void grf::SpriteSheet::setPosition(grf::Vector v)
{
    for (size_t i = 0; i < _sheet.size(); i++)
        _sheet[i]->setPosition(v);
}

void grf::SpriteSheet::setAngle(float angle)
{
    for (size_t i = 0; i < _sheet.size(); i++)
        _sheet[i]->setAngle(angle);
}

void grf::SpriteSheet::setScale(Vector scale)
{
    for (size_t i = 0; i < _sheet.size(); i++)
        _sheet[i]->setScale(scale);
}