#pragma once

#include <iostream>
#include "colors.h"
#include "utils.h"
#include <cassert>
#include <list>
using std::list;

#define loop() for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++)

constexpr int dx[] = {-1, 0, +1, 0};
constexpr int dy[] = {0, +1, 0, -1};

enum direction {
    top, right, bottom, left
};

struct point {
    int x, y;
    bool operator==(const point& p) const {
        return (x == p.x) && (y == p.y);
    }
    point() {
        x = 0;
        y = 0;
    }
    void move(direction d) {
        x += dx[d];
        y += dy[d];
        assert(x >= 0 && y >= 0 && x < 4 && y < 4);
    }
    bool valid(direction d) const {
        int _x = x + dx[d];
        int _y = y + dy[d];
        return (_x >= 0 && _y >= 0 && _x < 4 && _y < 4);
    }
    size_t hash() const {
        /* Cantor Pairing */
        return ((x+y)*(x+y+1))/2 + y;
    }
    void print() const {
        printf("(%d,%d)\n", x, y);
    }
};

enum color_t {
    white, blue
};

class cube_t {
public:
    point pos;
    color_t U, D, R, L, F, B;

    cube_t() {
        pos = point();
        U = D = R = L = F = B = white;
    }
    void roll(direction d) {
        pos.move(d);
        switch (d) {
            case top: { cyclic_swap(D, F, U, B); break; }
            case right: { cyclic_swap(D, L, U, R); break; }
            case bottom: { cyclic_swap(D, B, U, F); break; }
            case left: { cyclic_swap(D, R, U, L); break; }
        }
    }
    void print() const {
        std::cout << color() << color(B) << '\n';
        std::cout << color(L) << color(D) << color(R) << '\n';
        std::cout << color() << color(F) << '\n';
        std::cout << color() << color(U) << '\n';
    }
    bool operator==(const cube_t& c) const {
        if (U != c.U) {
            return false;
        } if (D != c.D) {
            return false;
        } if (R != c.R) {
            return false;
        } if (L != c.L) {
            return false;
        } if (F != c.F) {
            return false;
        } if (B != c.B) {
            return false;
        }
        return (pos == c.pos);
    }
    size_t hash() const {
        size_t mask = 0;
        mask |= bool(U)<<0;
        mask |= bool(D)<<1;
        mask |= bool(F)<<2;
        mask |= bool(B)<<3;
        mask |= bool(R)<<4;
        mask |= bool(L)<<5;
        return pos.hash() ^ mask;
    }
};

class state {
private:
    color_t grid[4][4];
    cube_t cube;

public:
    struct hash {
        size_t operator()(const state& s) const {
            int mask = 0, bit = 0;
            loop() {
                mask |= bool(s.grid[i][j]) << bit;
                bit++;
            }
            return (mask * s.cube.hash());
        }
    };

    state() {
        cube = cube_t();
        loop() {
            grid[i][j] = white;
        }
        grid[2][1] = blue;
        grid[3][1] = blue;

        grid[1][0] = blue;
        grid[1][1] = blue;
        grid[1][2] = blue;
        grid[1][3] = blue;
    }
    state move(direction d) const {
        state r = *this;
        r.cube.roll(d);
        swap(r.cube.D, r.grid[r.cube.pos.x][r.cube.pos.y]);
        return r;
    }
    void print() const {
        cube.pos.print();
        return;
        loop() {
            if (j == 0) {
                std::cout << '\n';
            }
            std::cout << color(grid[i][j]);
        }
        std::cout << '\n' << '\n';
        cube.print();
        std::cout << '\n';
    }
    list<state> possible() const {
        list<state> r;
        for (direction d : {top, right, bottom, left}) {
            if (cube.pos.valid(d)) {
                r.push_back(this->move(d));
            }
        }
        return r;
    }
    bool solved() const {
        loop() {
            if (grid[i][j] == blue) {
                return false;
            }
        }
        return true;
    }
    bool operator==(const state& s) const {
        loop() {
            if (grid[i][j] != s.grid[i][j]) {
                return false;
            }
        }
        return (cube == s.cube);
    }
};
