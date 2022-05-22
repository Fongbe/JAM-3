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
#include <time.h>
#include <chrono>
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
        grf::Vector getRngPos(std::vector<std::string> map);
        void drawTimer(void);
        void handleMenu(void);
        void handleEnd(void);

    private:
        // game
        int status = 0;
        int id = 0;
        int timer;
        std::chrono::steady_clock::time_point tend;
        
        int homer;
        int bart;
        int lisa;
        int maggie;

        grf::Vector posHomer;
        grf::Vector posBart;
        grf::Vector posLisa;
        grf::Vector posMaggie;

        std::shared_ptr<Player> p;
        std::vector<std::string> map;
        std::vector<std::shared_ptr<GameObject>> listObject;
        
        // grf
        grf::Window wn;
        grf::Event ev;
        grf::SpriteSheet Stree;
        grf::SpriteSheet Shomer;
        grf::SpriteSheet Smarge;
        grf::SpriteSheet Sbart;
        grf::SpriteSheet Slisa;
        grf::SpriteSheet Smaggie;
        grf::SpriteSheet charHomer;
        grf::SpriteSheet charBart;
        grf::SpriteSheet charLisa;
        grf::SpriteSheet charMaggie;
        grf::SpriteSheet grass;
        grf::SpriteSheet text;
        grf::SpriteSheet menu;
        grf::SpriteSheet end;
        grf::SpriteSheet button;
};

#endif /* !GAME_HPP_ */