/*
** EPITECH PROJECT, 2022
** test
** File description:
** GameObject
*/

#include "GameObject.hpp"

GameObject::GameObject(int id)
{
    ID = id;
    imageIndex = 0;
    pos = grf::Vector();
    imageSpeed = 1;
}

GameObject::~GameObject()
{
}

void GameObject::draw(grf::Window &window)
{
    if (sprite.getSize() != 0 && imageIndex < sprite.getSize())
        window.drawSprite(sprite, imageIndex, pos);
}

void GameObject::destroy(std::vector<std::shared_ptr<GameObject>> &listObject)
{
    for (size_t i = 0; i < listObject.size(); i++) {
        if (listObject[i]->ID == ID) {
            listObject.erase(listObject.begin() + i);
            return;
        }
    }
}