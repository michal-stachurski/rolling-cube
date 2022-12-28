#include "../cube.h"
#include <initializer_list>
#include <utility>

template<typename _Tp>
void cyclic_swap(_Tp* array, int i, int j, int k, int l) {
    _Tp tmp = std::move(array[l]);
    array[l] = std::move(array[k]);
    array[k] = std::move(array[j]);
    array[j] = std::move(array[i]);
    array[i] = std::move(tmp);
}


cube::cube(int _x, int _y) : x(_x), y(_y) {
    for (cube_side s : {U, D, R, L, F, B}) {
        side[s] = white;
    }
}
bool cube::valid(direction d) const {
    int _x = x + dx[d];
    int _y = y + dy[d];
    return (_x >= 0 && _y >= 0 && _x < 4 && _y < 4);
}
void cube::roll(direction d) {
    x += dx[d];
    y += dy[d];
    switch (d) {
        case up: return cyclic_swap(side, D, F, U, B);
        case right: return cyclic_swap(side, D, L, U, R);
        case down: return cyclic_swap(side, D, B, U, F);
        case left: return cyclic_swap(side, D, R, U, L);
    }
}
bool cube::operator==(const cube& other) const {
    for (cube_side s : {U, D, R, L, F, B}) {
        if (side[s] != other.side[s]) {
            return false;
        }
    }
    return (x == other.x) && (y == other.y);
}
