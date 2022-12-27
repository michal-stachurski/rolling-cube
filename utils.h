#pragma once

template<typename _Tp>
void cyclic_swap(_Tp& __a, _Tp& __b, _Tp& __c, _Tp& __d) {
    _Tp __tmp = _GLIBCXX_MOVE(__a);
    __a = _GLIBCXX_MOVE(__d);
    __d = _GLIBCXX_MOVE(__c);
    __c = _GLIBCXX_MOVE(__b);
    __b = _GLIBCXX_MOVE(__tmp);
}

template<typename _Tp>
void swap(_Tp& __a, _Tp& __b) {
    _Tp __tmp = _GLIBCXX_MOVE(__a);
    __a = _GLIBCXX_MOVE(__b);
    __b = _GLIBCXX_MOVE(__tmp);
}
