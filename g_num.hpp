//
//  g_num.hpp
//  laba 3 ++
//
//  Created by Дмитрий Емелин on 04.11.2021.
//

#ifndef g_num_hpp
#define g_num_hpp
#include <iostream>
#include <stdio.h>
#include "lib.hpp"

template <class T>
int get_num(T& a) {
    std::cin >> a;
    if (!std::cin.good())
        return -1;
    return 1;

}

int dialog();

#endif /* g_num_hpp */
