/*
** EPITECH PROJECT, 2022
** JAM-3
** File description:
** Block
*/

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "GameObject.hpp"
#include <random>

class Block : public GameObject {
    public:
        Block(grf::Vector v, int id);
        ~Block();
};

#endif /* !BLOCK_HPP_ */