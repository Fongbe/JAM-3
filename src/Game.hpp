/*
** EPITECH PROJECT, 2022
** JAM-3
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../grf/grf.h"
#include "GameObject.hpp"
#include "Road.hpp"
#include "Block.hpp"
#include "Player.hpp"
#include <fstream>
#include <iostream>

class Game {
    public:
        Game();
        ~Game();
        void loop(void);
        void openMap(void);
        void draw(void);
        void handleObjects(void);

    private:
        // game
        int id = 0;
        int timer;
        std::shared_ptr<Player> p;
        std::vector<std::string> map;
        std::vector<std::shared_ptr<GameObject>> listObject;
        
        // grf
        grf::Window wn;
        grf::Event ev;
};

#endif /* !GAME_HPP_ */