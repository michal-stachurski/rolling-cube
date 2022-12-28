#include "../enum.h"

const char* print(direction d) {
    switch (d) {
        case up: return "up";
        case right: return "right";
        case down: return "down";
        case left: return "left";
        default: return "none";
    }
}

#include "../utils.h"
#include <utility>

template<typename _Tp>
void cyclic_swap(_Tp* array, int i, int j, int k, int l) {
    _Tp tmp = std::move(array[l]);
    array[l] = std::move(array[k]);
    array[k] = std::move(array[j]);
    array[j] = std::move(array[i]);
    array[i] = std::move(tmp);
}

template<typename _Tp>
void swap(_Tp& __a, _Tp& __b) {
    _Tp __tmp = std::move(__a);
    __a = std::move(__b);
    __b = std::move(__tmp);
}
