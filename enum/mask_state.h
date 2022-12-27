#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include "../colors.h"

constexpr int R[] = {
    3, 7, 11, 15,
    2, 6, 10, 14,
    1, 5, 9, 13,
    0, 4, 8, 12
};
constexpr int T[] = {
    3, 2, 1, 0,
    7, 6, 5, 4,
    11, 10, 9, 8,
    15, 14, 13, 12
};
constexpr int D[] = {
    0, 4, 8, 12,
    1, 5, 9, 13,
    2, 6, 10, 14,
    3, 7, 11, 15
};


bool visited[16];
void clear() {
    for (bool &x: visited) {
        x = false;
    }
}

class state {
private:
    int mask;

public:
    state(int m) {
        mask = m;
    }

    bool operator==(const state& S) const {
        return mask == S.mask;
    }
    void print() const {
        int m = mask;
        m += (1<<16);
        int row = 0;
        std::string img;
        while (m > 1) {
            if (row == 4) {
                row = 0;
                img.push_back('\n');
            }
            img.push_back((m & 1) ? ('B') : ('W'));
            row++;
            m /= 2;
        }
        std::reverse(img.begin(), img.end());
        std::cout << '\n';
        for (char c : img) {
            if (c != '\n') {
                std::cout << color(c);
            } else {
                std::cout << c;
            }
        }
        std::cout << '\n';
    }
    void rec_mask(const int* M, const int source, int& __mask, int v, int mem = 0, bool first = true) const {
        if (visited[v]) {
            return;
        }
        if (!first) {
            visited[v] = true;
        }
        __mask |= mem << v;
        mem = bool(source & (1<<v));
        rec_mask(M, source, __mask, M[v], mem, false);
    }

    state rotate() const {
        clear();
        int __mask_r = 0;
        for (int i = 0; i < 16; i++) {
            if (!visited[i]) {
                rec_mask(R, mask, __mask_r, i);
            }
        }
        return state(__mask_r);
    }
    state reflect() const {
        clear();
        int __mask_r = 0;
        for (int i = 0; i < 16; i++) {
            if (!visited[i]) {
                rec_mask(T, mask, __mask_r, i);
            }
        }
        return state(__mask_r);
    }
    state reflect_diag() const {
        clear();
        int __mask_r = 0;
        for (int i = 0; i < 16; i++) {
            if (!visited[i]) {
                rec_mask(D, mask, __mask_r, i);
            }
        }
        return state(__mask_r);
    }
};
