/*
** EPITECH PROJECT, 2022
** JAM-3
** File description:
** Block
*/

#include "Block.hpp"

Block::Block(grf::Vector v, int id) : GameObject(id)
{
    pos.x = v.x;
    pos.y = v.y;
    sprite = grf::SpriteSheet("Sblock", "sprites/house.png", 3, 170, 170, 0, 0);
    imageIndex = rand()%3;
}

Block::~Block()
{
}

void Block::onStep(std::vector<std::shared_ptr<GameObject>> &listObject, std::vector<grf::SpriteSheet> listSprite, grf::Event ev)
{
}