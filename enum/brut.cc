#include "mask_state.h"
#include <iostream>

int main() {
    int count = 0;
    for (int mask = 0; mask < (1<<16); mask++) {
        if (__builtin_popcount(mask) == 6) {
            state m(mask);
            if (m == m.reflect_diag()) {
                m.print();
                count++;
            }
        }
    }
    std::cout << count << '\n';
}