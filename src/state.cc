#include <iostream>
#include "../state.h"

state::state() {
    loop() {
        grid[i][j] = white;
    }
}
void state::read() {
    int x, y;
    std::cin >> x >> y;
    cuboid = cube(x, y);
    loop() {
        bool x;
        std::cin >> x;
        grid[i][j] = (x) ? (blue) : (white);
    }
}
state state::move(direction d) const {
    state r = *this;
    if (!cuboid.valid(d)) {
        return r;
    }
    r.cuboid.roll(d);
    std::swap(r.cuboid.side[D], r.grid[r.cuboid.x][r.cuboid.y]);
    return r;
}
bool state::solved() const {
    loop() {
        if (grid[i][j] == blue) {
            return false;
        }
    }
    return true;
}
bool state::operator==(const state& s) const {
    loop() {
        if (grid[i][j] != s.grid[i][j]) {
            return false;
        }
    }
    return (cuboid == s.cuboid);
}
