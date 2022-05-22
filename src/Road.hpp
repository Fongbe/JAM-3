/*
** EPITECH PROJECT, 2022
** JAM-3
** File description:
** Road
*/

#ifndef ROAD_HPP_
#define ROAD_HPP_

#include "GameObject.hpp"

class Road : public GameObject {
    public:
        Road(grf::Vector v, int id);
        ~Road();
        void onStep(std::vector<std::shared_ptr<GameObject>> &listObject, std::vector<grf::SpriteSheet> listSprite, grf::Event ev) override;

    protected:
    private:
};

#endif /* !ROAD_HPP_ */