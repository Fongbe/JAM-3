/*
** EPITECH PROJECT, 2022
** JAM-3
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../grf/grf.h"

class Game {
    public:
        Game();
        ~Game();
        void loop(void);
        void openMap(void);
        void draw(void);

    private:
        // game
        int timer;
        std::vector<std::string> map;
        
        // grf
        grf::Window wn;
        grf::Event ev;
};

#endif /* !GAME_HPP_ */