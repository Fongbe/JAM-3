/*
** EPITECH PROJECT, 2022
** libSfml
** File description:
** Vector
*/

#include "Vector.hpp"

grf::Vector::Vector()
{
    x = 0;
    y = 0;
}

grf::Vector::Vector(float _x, float _y)
{
    x = _x;
    y = _y;
}

grf::Vector::~Vector()
{
}