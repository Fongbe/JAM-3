/*
** EPITECH PROJECT, 2022
** JAM-3
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "GameObject.hpp"

class Player : public GameObject {
    public:
        Player(grf::Vector v, int id);
        ~Player();
        void move(std::vector<std::string> map, grf::Event ev);
        bool collide(std::vector<std::string> map, int x, int y);
        void draw(grf::Window &window);

    private:
        std::vector<grf::SpriteSheet> sprites;
        float hspeed;
        float vspeed;
};

#endif /* !PLAYER_HPP_ */