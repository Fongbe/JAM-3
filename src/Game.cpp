/*
** EPITECH PROJECT, 2022
** JAM-3
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::loop(void)
{
    wn.init(1920, 1080, "Marge's Family");
    while (wn.isRunning()) {
        ev = wn.getEvent();
        if (ev.QUIT)
            wn.destroy();
        wn.clear();
        draw();
        wn.update();
    }
    wn.destroy();
}

void Game::draw(void)
{

}

void Game::openMap(void)
{

}