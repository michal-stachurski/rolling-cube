#ifndef ENUM_H
#define ENUM_H

enum cube_side {
    U, D, R, L, F, B
};

enum direction {
    up, right, down, left
};

const char* print(direction);

// offsets for moving in `direction`
const int dx[] = {-1, 0, +1, 0};
const int dy[] = {0, +1, 0, -1};

enum color {
    white, blue
};

#endif
