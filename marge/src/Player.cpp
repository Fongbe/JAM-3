/*
** EPITECH PROJECT, 2022
** JAM-3
** File description:
** Player
*/

#include <iostream>
#include "Player.hpp"

Player::Player(grf::Vector v, int id) : GameObject(id)
{
    pos.x = v.x;
    pos.y = v.y;
    hspeed = 0;
    vspeed = 0;
    sprites.push_back(grf::SpriteSheet("Smarge", "sprites/marge.png", 1, 17, 76, 0, 0));
    sprites.push_back(grf::SpriteSheet("SmargeLeft", "sprites/margeLeft.png", 5, 42, 70, 0, 0));
    sprites.push_back(grf::SpriteSheet("SmargeRight", "sprites/margeRight.png", 5, 42, 70, 0, 0));
    sprites.push_back(grf::SpriteSheet("SmargeUp", "sprites/margeUp.png", 6, 20, 73, 0, 0));
    sprites.push_back(grf::SpriteSheet("SmargeDown", "sprites/margeDown.png", 7, 19, 71, 0, 0));
    sprites[0].setOrigin(grf::Vector(10, 71));
    sprites[1].setOrigin(grf::Vector(18, 65));
    sprites[2].setOrigin(grf::Vector(24, 65));
    sprites[3].setOrigin(grf::Vector(11, 68));
    sprites[4].setOrigin(grf::Vector(9, 66));
    sprite = sprites[0];
    imageSpeed = 0.2;
}

Player::~Player()
{
}

void Player::draw(grf::Window &window)
{
    if (sprite.getSize() != 0 && imageIndex < sprite.getSize())
        window.drawSprite(sprite, imageIndex, grf::Vector(920, 540));
}

bool Player::collide(std::vector<std::string> map, int x, int y)
{
    if (x < 0)
        return true;
    if (y < 0)
        return true;
    if (y >= map.size())
        return true;
    if (x >= map[y].size())
        return true;
    if (map[y][x] == 'X')
        return true;
    return false;
}

void Player::move(std::vector<std::string> map, grf::Event ev)
{
    int xx = this->pos.x;
    int yy = this->pos.y;

    if (xx % 170 == 0 && yy % 170 == 0)
    {
        vspeed = 0;
        hspeed = 0;
        if (ev.KEY_Q)
            hspeed = -1;
        else if (ev.KEY_D)
            hspeed = 1;
        else if (ev.KEY_Z)
            vspeed = -1;
        else if (ev.KEY_S)
            vspeed = 1;
        if (vspeed != 0 || hspeed != 0)
        {
            int xgo = (pos.x - xx % 170) / 170 + hspeed;
            int ygo = (pos.y - yy % 170) / 170 + vspeed;
            if (collide(map, xgo, ygo)) {
                vspeed = 0;
                hspeed = 0;
            }
        }
    }
    pos.x += hspeed * 5;
    pos.y += vspeed * 5;
    imageIndex += imageSpeed;
    if (imageIndex > sprite.getSize())
        imageIndex -= sprite.getSize();
    if (hspeed > 0)
        sprite = sprites[2];
    else if (hspeed < 0)
        sprite = sprites[1];
    else if (vspeed > 0)
        sprite = sprites[4];
    else if (vspeed < 0)
        sprite = sprites[3];
    else {
        sprite = sprites[0];
        imageIndex = 0;
    }
}