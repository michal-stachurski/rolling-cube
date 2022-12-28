#include "../state.h"

size_t state::hash::operator()(const state& s) const {
    size_t mask = 0, bit = 0;
    loop() {
            mask |= bool(s.grid[i][j]) << bit;
        bit++;
    }
    return (mask * s.cuboid.hash());
}

#include <initializer_list>
#include "../cube.h"

size_t cube::cantor() const {
    return ((x+y) * (x+y+1)) / 2 + y; // cantor pairing
}

size_t cube::hash() const {
    size_t mask = 0;
    for (cube_side s : {U, D, R, L, F, B}) {
        mask |= side[s] << s;
    }
    return this->cantor() ^ mask;
}
