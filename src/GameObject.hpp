/*
** EPITECH PROJECT, 2022
** test
** File description:
** Iobject
*/

#ifndef IOBJECT_HPP_
#define IOBJECT_HPP_

#include "../grf/grf.h"

class GameObject {
    public:
        GameObject(int id);
        ~GameObject();
        
        virtual void onStep(std::vector<std::shared_ptr<GameObject>> &listObject, std::vector<grf::SpriteSheet> listSprite, grf::Event ev) = 0;
        void draw(grf::Window &window);
        void destroy(std::vector<std::shared_ptr<GameObject>> &listObject);

        float depth;
        float imageIndex;
        float imageSpeed;
        grf::SpriteSheet sprite;
        grf::Vector pos;
        int ID;
};

#endif /* !IOBJECT_HPP_ */