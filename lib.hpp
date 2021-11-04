//
//  lib.hpp
//  laba 3 ++
//
//  Created by Дмитрий Емелин on 21.10.2021.
//

#ifndef lib_hpp
#define lib_hpp
#include <iostream>
#include <stdio.h>

namespace LIB{
class Func
{
private:
    static const int SZ = 5;
    double x_coor[SZ];
    double y_coor[SZ];
    int size_coor = 0;

public:
    Func() //пустой конструктор
    {
        for (size_t i = 0; i < SZ; i++)
        {
            x_coor[i] = 0;
            y_coor[i] = 0;
        }
    }


    //Пузырьковая сортировка
    void sortBubl();

    //Поиск максимального и минимального элемента
    void maxMinFunc(Func f);

    void typeF(Func f);

    double calculateF(Func f, double xO);
    void printFunc( Func f);

  
    int saveUzels(int SZ_uz, Func U);
    int add_Uzel(Func U);

    };

}
#endif /* lib_hpp */
