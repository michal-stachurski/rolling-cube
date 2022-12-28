#ifndef UTILS_H
#define UTILS_H

#define loop() for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++)

template<typename _Tp>
void cyclic_swap(_Tp*, int, int, int, int);

template<typename _Tp>
void swap(_Tp&, _Tp&);

#endif
