#ifndef CUBE_H
#define CUBE_H

#include <cstddef>
#include "enum.h"

class cube {
public:
    int x, y;
    color side[6];

    cube(int, int);
    bool valid(direction) const;
    void roll(direction);
    bool operator==(const cube&) const;

    size_t cantor() const;
    size_t hash() const;
};

#endif