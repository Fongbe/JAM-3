/*
** EPITECH PROJECT, 2022
** libSfml
** File description:
** Window
*/

#include "Window.hpp"
#include <iostream>

grf::Window::Window()
{
    _wn = nullptr;
}

grf::Window::~Window()
{
    if (_wn != nullptr)
        destroy();
}

bool grf::Window::isRunning(void)
{
    if (_wn == nullptr)
        return false;
    return _wn->isOpen();
}

void grf::Window::init(int w, int h, std::string title)
{
    if (_wn != nullptr)
        destroy();
    _wn = new sf::RenderWindow();
    _wn->create(sf::VideoMode(w, h, 32), title);
    _wn->setVerticalSyncEnabled(true);
    _wn->setFramerateLimit(60);
    _wn->setKeyRepeatEnabled(true);
}

void grf::Window::destroy(void)
{
    if (_wn != nullptr)
    {
        _wn->close();
        delete _wn;
        _wn = nullptr;
    }
}

void grf::Window::clear(void)
{
    if (_wn != nullptr)
        _wn->clear();
}

void grf::Window::update(void)
{
    if (_wn != nullptr)
        _wn->display();
}

grf::Event grf::Window::getEvent(void)
{
    sf::Event event;
    grf::Event ev;

    if (_wn == nullptr)
        return ev;
    sf::Vector2i v = sf::Mouse::getPosition();
    ev.MOUSE_POS.x = v.x;
    ev.MOUSE_POS.y = v.y;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        ev.MOUSE_LEFT = true;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        ev.MOUSE_RIGHT = true;
    while (_wn->pollEvent(event))
    {
        if (event.type == event.Closed)
            ev.QUIT = true;
        if (event.type == event.MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
                ev.MOUSE_LEFTDOWN = true;
            if (event.mouseButton.button == sf::Mouse::Right)
                ev.MOUSE_RIGHTDOWN = true;
        }
        if (event.type == event.MouseButtonReleased)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
                ev.MOUSE_LEFTUP = true;
            if (event.mouseButton.button == sf::Mouse::Right)
                ev.MOUSE_RIGHTUP = true;
        }
        if (event.type == event.KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Left)
                ev.KEY_LEFT_RELEASED = true;
            if (event.key.code == sf::Keyboard::Right)
                ev.KEY_RIGHT_RELEASED = true;
            if (event.key.code == sf::Keyboard::Up)
                ev.KEY_UP_RELEASED = true;
            if (event.key.code == sf::Keyboard::Down)
                ev.KEY_DOWN_RELEASED = true;
            if (event.key.code == sf::Keyboard::Escape)
                ev.KEY_ESCAPE_RELEASED = true;
            if (event.key.code == sf::Keyboard::Enter)
                ev.KEY_ENTER_RELEASED = true;
            if (event.key.code == sf::Keyboard::Space)
                ev.KEY_SPACE_RELEASED = true;
            if (event.key.code == sf::Keyboard::A)
                ev.KEY_A_RELEASED = true;
            if (event.key.code == sf::Keyboard::B)
                ev.KEY_B_RELEASED = true;
            if (event.key.code == sf::Keyboard::C)
                ev.KEY_C_RELEASED = true;
            if (event.key.code == sf::Keyboard::D)
                ev.KEY_D_RELEASED = true;
            if (event.key.code == sf::Keyboard::E)
                ev.KEY_E_RELEASED = true;
            if (event.key.code == sf::Keyboard::F)
                ev.KEY_F_RELEASED = true;
            if (event.key.code == sf::Keyboard::G)
                ev.KEY_G_RELEASED = true;
            if (event.key.code == sf::Keyboard::H)
                ev.KEY_H_RELEASED = true;
            if (event.key.code == sf::Keyboard::I)
                ev.KEY_I_RELEASED = true;
            if (event.key.code == sf::Keyboard::J)
                ev.KEY_J_RELEASED = true;
            if (event.key.code == sf::Keyboard::K)
                ev.KEY_K_RELEASED = true;
            if (event.key.code == sf::Keyboard::L)
                ev.KEY_L_RELEASED = true;
            if (event.key.code == sf::Keyboard::M)
                ev.KEY_M_RELEASED = true;
            if (event.key.code == sf::Keyboard::N)
                ev.KEY_N_RELEASED = true;
            if (event.key.code == sf::Keyboard::O)
                ev.KEY_O_RELEASED = true;
            if (event.key.code == sf::Keyboard::P)
                ev.KEY_P_RELEASED = true;
            if (event.key.code == sf::Keyboard::Q)
                ev.KEY_Q_RELEASED = true;
            if (event.key.code == sf::Keyboard::R)
                ev.KEY_R_RELEASED = true;
            if (event.key.code == sf::Keyboard::S)
                ev.KEY_S_RELEASED = true;
            if (event.key.code == sf::Keyboard::T)
                ev.KEY_T_RELEASED = true;
            if (event.key.code == sf::Keyboard::U)
                ev.KEY_U_RELEASED = true;
            if (event.key.code == sf::Keyboard::V)
                ev.KEY_V_RELEASED = true;
            if (event.key.code == sf::Keyboard::W)
                ev.KEY_W_RELEASED = true;
            if (event.key.code == sf::Keyboard::X)
                ev.KEY_X_RELEASED = true;
            if (event.key.code == sf::Keyboard::Y)
                ev.KEY_Y_RELEASED = true;
            if (event.key.code == sf::Keyboard::Z)
                ev.KEY_Z_RELEASED = true;
        }
        if (event.type == event.KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Left)
                ev.KEY_LEFT_PRESSED = true;
            if (event.key.code == sf::Keyboard::Right)
                ev.KEY_RIGHT_PRESSED = true;
            if (event.key.code == sf::Keyboard::Up)
                ev.KEY_UP_PRESSED = true;
            if (event.key.code == sf::Keyboard::Down)
                ev.KEY_DOWN_PRESSED = true;
            if (event.key.code == sf::Keyboard::Escape)
                ev.KEY_ESCAPE_PRESSED = true;
            if (event.key.code == sf::Keyboard::Enter)
                ev.KEY_ENTER_PRESSED = true;
            if (event.key.code == sf::Keyboard::Space)
                ev.KEY_SPACE_PRESSED = true;
            if (event.key.code == sf::Keyboard::A)
                ev.KEY_A_PRESSED = true;
            if (event.key.code == sf::Keyboard::B)
                ev.KEY_B_PRESSED = true;
            if (event.key.code == sf::Keyboard::C)
                ev.KEY_C_PRESSED = true;
            if (event.key.code == sf::Keyboard::D)
                ev.KEY_D_PRESSED = true;
            if (event.key.code == sf::Keyboard::E)
                ev.KEY_E_PRESSED = true;
            if (event.key.code == sf::Keyboard::F)
                ev.KEY_F_PRESSED = true;
            if (event.key.code == sf::Keyboard::G)
                ev.KEY_G_PRESSED = true;
            if (event.key.code == sf::Keyboard::H)
                ev.KEY_H_PRESSED = true;
            if (event.key.code == sf::Keyboard::I)
                ev.KEY_I_PRESSED = true;
            if (event.key.code == sf::Keyboard::J)
                ev.KEY_J_PRESSED = true;
            if (event.key.code == sf::Keyboard::K)
                ev.KEY_K_PRESSED = true;
            if (event.key.code == sf::Keyboard::L)
                ev.KEY_L_PRESSED = true;
            if (event.key.code == sf::Keyboard::M)
                ev.KEY_M_PRESSED = true;
            if (event.key.code == sf::Keyboard::N)
                ev.KEY_N_PRESSED = true;
            if (event.key.code == sf::Keyboard::O)
                ev.KEY_O_PRESSED = true;
            if (event.key.code == sf::Keyboard::P)
                ev.KEY_P_PRESSED = true;
            if (event.key.code == sf::Keyboard::Q)
                ev.KEY_Q_PRESSED = true;
            if (event.key.code == sf::Keyboard::R)
                ev.KEY_R_PRESSED = true;
            if (event.key.code == sf::Keyboard::S)
                ev.KEY_S_PRESSED = true;
            if (event.key.code == sf::Keyboard::T)
                ev.KEY_T_PRESSED = true;
            if (event.key.code == sf::Keyboard::U)
                ev.KEY_U_PRESSED = true;
            if (event.key.code == sf::Keyboard::V)
                ev.KEY_V_PRESSED = true;
            if (event.key.code == sf::Keyboard::W)
                ev.KEY_W_PRESSED = true;
            if (event.key.code == sf::Keyboard::X)
                ev.KEY_X_PRESSED = true;
            if (event.key.code == sf::Keyboard::Y)
                ev.KEY_Y_PRESSED = true;
            if (event.key.code == sf::Keyboard::Z)
                ev.KEY_Z_PRESSED = true;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        ev.KEY_LEFT = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        ev.KEY_RIGHT = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        ev.KEY_UP = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        ev.KEY_DOWN = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        ev.KEY_ESCAPE = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        ev.KEY_ENTER = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        ev.KEY_SPACE = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        ev.KEY_A = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        ev.KEY_B = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        ev.KEY_C = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        ev.KEY_D = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        ev.KEY_E = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        ev.KEY_F = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        ev.KEY_G = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        ev.KEY_H = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        ev.KEY_I = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        ev.KEY_J = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        ev.KEY_K = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        ev.KEY_L = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        ev.KEY_M = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
        ev.KEY_N = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
        ev.KEY_O = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        ev.KEY_P = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        ev.KEY_Q = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        ev.KEY_R = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        ev.KEY_S = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
        ev.KEY_T = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        ev.KEY_U = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
        ev.KEY_V = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        ev.KEY_W = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        ev.KEY_X = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        ev.KEY_Y = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        ev.KEY_Z = true;
    return ev;
}

void grf::Window::drawSprite(grf::Sprite spr, grf::Vector v)
{
    if (_wn != nullptr && spr.isDrawable())
    {
        spr.setPosition(v);
        _wn->draw(spr.getSprite());
    }
}

void grf::Window::drawSprite(grf::SpriteSheet spr, unsigned int i, grf::Vector v)
{
    if (_wn != nullptr && i < spr.getSize())
    {
        if (spr.getSheet()[i]->isDrawable())
        {
            spr.setPosition(v);
            _wn->draw(spr.getSheet()[i]->getSprite());
        }
    }
}

void grf::Window::drawSpriteExt(grf::Sprite spr, grf::Vector v, int a, Vector s)
{
    if (_wn != nullptr && spr.isDrawable())
    {
        spr.setPosition(v);
        spr.setAngle(a);
        spr.setScale(s);
        _wn->draw(spr.getSprite());
    }
}

void grf::Window::drawSpriteExt(grf::SpriteSheet spr, unsigned int i, grf::Vector v, float a, Vector s)
{
    if (_wn != nullptr && i < spr.getSize())
    {
        if (spr.getSheet()[i]->isDrawable())
        {
            spr.setPosition(v);
            spr.setAngle(a);
            spr.setScale(s);
            _wn->draw(spr.getSheet()[i]->getSprite());
        }
    }
}