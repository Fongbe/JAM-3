/*
** EPITECH PROJECT, 2022
** libSfml
** File description:
** Vector
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

namespace grf
{
    class Vector {
        public:
            Vector();
            Vector(float x, float y);
            ~Vector();

            float x;
            float y;
    };
}

#endif /* !VECTOR_HPP_ */
