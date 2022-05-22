/*
** EPITECH PROJECT, 2022
** JAM-3
** File description:
** Road
*/

#include "Road.hpp"

Road::Road(grf::Vector v, int id) : GameObject(id)
{
    pos.x = v.x;
    pos.y = v.y;
    sprite = grf::SpriteSheet("Sroad", "sprites/road.png", 7, 170, 170, 0, 0);
}

Road::~Road()
{
}

void Road::onStep(std::vector<std::shared_ptr<GameObject>> &listObject, std::vector<grf::SpriteSheet> listSprite, grf::Event ev)
{
}
