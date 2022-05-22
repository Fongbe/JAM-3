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

void Game::handleObjects(void)
{
    p->move(map, ev);
}

void Game::loop(void)
{
    wn.init(1920, 1080, "Marge's Family");
    openMap();
    while (wn.isRunning())
    {
        ev = wn.getEvent();
        if (ev.QUIT)
            wn.destroy();
        handleObjects();
        wn.clear();
        draw();
        wn.update();
    }
    wn.destroy();
}

void Game::draw(void)
{
    for (size_t i = 0; i < listObject.size(); i++)
        listObject[i]->draw(wn, p->pos);
    p->draw(wn);
}

void Game::openMap(void)
{
    std::ifstream flux("map.map");
    std::string str;

    while (std::getline(flux, str))
        map.push_back(str);
    for (size_t y = 0; y < map.size(); y++)
    {
        for (size_t x = 0; x < map[y].size(); x++)
        {
            if (map[y][x] == 'P')
            {
                listObject.push_back(std::make_shared<Road>(grf::Vector(x * 170, y * 170), id));
                listObject[listObject.size() - 1]->imageIndex = 1;
                id++;
                p = std::make_shared<Player>(grf::Vector(x * 170, y * 170), id);
                id++;
            }
            if (map[y][x] == 'X')
            {
                listObject.push_back(std::make_shared<Block>(grf::Vector(x * 170, y * 170), id));
                id++;
            }
            if (map[y][x] == 'H')
            {
                listObject.push_back(std::make_shared<Road>(grf::Vector(x * 170, y * 170), id));
                listObject[listObject.size() - 1]->imageIndex = 0;
                id++;
            }
            if (map[y][x] == 'M')
            {
                listObject.push_back(std::make_shared<Road>(grf::Vector(x * 170, y * 170), id));
                listObject[listObject.size() - 1]->imageIndex = 1;
                id++;
            }
            if (map[y][x] == 'V')
            {
                listObject.push_back(std::make_shared<Road>(grf::Vector(x * 170, y * 170), id));
                listObject[listObject.size() - 1]->imageIndex = 2;
                id++;
            }
            if (map[y][x] == '1')
            {
                listObject.push_back(std::make_shared<Road>(grf::Vector(x * 170, y * 170), id));
                listObject[listObject.size() - 1]->imageIndex = 3;
                id++;
            }
            if (map[y][x] == '2')
            {
                listObject.push_back(std::make_shared<Road>(grf::Vector(x * 170, y * 170), id));
                listObject[listObject.size() - 1]->imageIndex = 4;
                id++;
            }
            if (map[y][x] == '3')
            {
                listObject.push_back(std::make_shared<Road>(grf::Vector(x * 170, y * 170), id));
                listObject[listObject.size() - 1]->imageIndex = 5;
                id++;
            }
            if (map[y][x] == '4')
            {
                listObject.push_back(std::make_shared<Road>(grf::Vector(x * 170, y * 170), id));
                listObject[listObject.size() - 1]->imageIndex = 6;
                id++;
            }
        }
    }
}