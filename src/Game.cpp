/*
** EPITECH PROJECT, 2022
** JAM-3
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    timer = 0;
    tend = std::chrono::steady_clock::now() + std::chrono::seconds(1);
    text = grf::SpriteSheet("", "sprites/font.png", 38, 38, 46, 0, 0);
    Stree = grf::SpriteSheet("stree", "sprites/tree.png", 1, 200, 200, 0, 0);
    Shomer = grf::SpriteSheet("stree", "sprites/treeHomer.png", 2, 200, 200, 0, 0);
    Smarge = grf::SpriteSheet("stree", "sprites/treeMarge.png", 1, 200, 200, 0, 0);
    Sbart = grf::SpriteSheet("stree", "sprites/treeBart.png", 2, 200, 200, 0, 0);
    Slisa = grf::SpriteSheet("stree", "sprites/treeLisa.png", 2, 200, 200, 0, 0);
    Smaggie = grf::SpriteSheet("stree", "sprites/treeMaggie.png", 2, 200, 200, 0, 0);
    charHomer = grf::SpriteSheet("", "sprites/homer.png", 1, 25, 67, 0, 0);
    charBart = grf::SpriteSheet("", "sprites/bart.png", 1, 24, 51, 0, 0);
    charLisa = grf::SpriteSheet("", "sprites/lisa.png", 1, 30, 45, 0, 0);
    charMaggie = grf::SpriteSheet("", "sprites/maggie.png", 1, 33, 27, 0, 0);
    charHomer.setOrigin(grf::Vector(12, 60));
    charBart.setOrigin(grf::Vector(12, 45));
    charLisa.setOrigin(grf::Vector(15, 40));
    charMaggie.setOrigin(grf::Vector(16, 30));
    grass = grf::SpriteSheet("", "sprites/grass.png", 1, 2560, 1536, 0, 0);
    homer = 1;
    bart = 1;
    lisa = 1;
    maggie = 1;
}

Game::~Game()
{
}

void Game::handleObjects(void)
{
    if (std::chrono::steady_clock::now() >= tend)
    {
        timer += 1;
        tend = std::chrono::steady_clock::now() + std::chrono::seconds(1);
    }
    p->move(map, ev);
    if (p->pos.x == posHomer.x && p->pos.y == posHomer.y)
        homer = 0;
    if (p->pos.x == posLisa.x && p->pos.y == posLisa.y)
        lisa = 0;
    if (p->pos.x == posBart.x && p->pos.y == posBart.y)
        bart = 0;
    if (p->pos.x == posMaggie.x && p->pos.y == posMaggie.y)
        maggie = 0;
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

void Game::drawTimer(void)
{
    int min = timer / 60;
    int sec = timer % 60;
    std::string t = "";
    t += std::to_string(min);
    t += ":";
    t += std::to_string(sec);
    for (size_t i = 0; i < t.size(); i++) {
        if (t[i] == ':')
            wn.drawSprite(text, 36, grf::Vector(20+i*38, 20));
        else
            wn.drawSprite(text, 26 + t[i] - '0', grf::Vector(20+i*38, 20));
    }
}

void Game::draw(void)
{
    int xx = p->pos.x;
    int yy = p->pos.y;
    wn.drawSprite(grass, 0, grf::Vector(-xx % 128, -yy % 128));
    for (size_t i = 0; i < listObject.size(); i++)
        listObject[i]->draw(wn, p->pos);
    if (homer)
        wn.drawSprite(charHomer, 0, grf::Vector(posHomer.x - p->pos.x + 920, posHomer.y - p->pos.y + 540));
    if (bart)
        wn.drawSprite(charBart, 0, grf::Vector(posBart.x - p->pos.x + 920, posBart.y - p->pos.y + 540));
    if (lisa)
        wn.drawSprite(charLisa, 0, grf::Vector(posLisa.x - p->pos.x + 920, posLisa.y - p->pos.y + 540));
    if (maggie)
        wn.drawSprite(charMaggie, 0, grf::Vector(posMaggie.x - p->pos.x + 920, posMaggie.y - p->pos.y + 540));
    p->draw(wn);
    wn.drawSprite(Stree, 0, grf::Vector(1700, 20));
    wn.drawSprite(Shomer, homer, grf::Vector(1700, 20));
    wn.drawSprite(Smarge, 0, grf::Vector(1700, 20));
    wn.drawSprite(Sbart, bart, grf::Vector(1700, 20));
    wn.drawSprite(Slisa, lisa, grf::Vector(1700, 20));
    wn.drawSprite(Smaggie, maggie, grf::Vector(1700, 20));
    drawTimer();
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
    posBart = getRngPos(map);
    posLisa = getRngPos(map);
    posMaggie = getRngPos(map);
    posHomer = getRngPos(map);
}

grf::Vector Game::getRngPos(std::vector<std::string> map)
{
    int x = 0;
    int y = 0;

    y = rand() % map.size();
    x = rand() % map[y].size();
    while (map[y][x] != 'M' && map[y][x] != 'V' && map[y][x] != 'H' && map[y][x] != '1' && map[y][x] != '2' && map[y][x] != '3' && map[y][x] != '4') {
        x = rand() % map[0].size();
        y = rand() % map.size();
    }
    return grf::Vector(x*170, y*170);
}