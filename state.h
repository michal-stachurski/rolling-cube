#ifndef STATE_H
#define STATE_H

#include <cstddef>
#include "cube.h"
#include "enum.h"

class state {
private:
    color grid[4][4];
    cube cuboid = cube(0,0);

public:
    state();
    void read();
    state move(direction) const;
    bool solved() const;
    bool operator==(const state&) const;

    struct hash {
        size_t operator()(const state&) const;
    };
};

#endif
