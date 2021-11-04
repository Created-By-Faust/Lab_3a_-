//
//  g_num.cpp
//  laba 3 ++
//
//  Created by Дмитрий Емелин on 04.11.2021.
//

#include "g_num.hpp"

using namespace std;
using namespace LIB;

int Func::saveUzels(int SZ_uz, Func U){
    if (SZ_uz > SZ){
        cout << " Количество узлов превосходит разрешённое";
        return -1;
    }
    int i = 0;
    while (i < SZ_uz) {
        cout << "Enter X:";
        get_num(x_coor[i]);
        
        cout << "Enter Y:";
        get_num(y_coor[i]);
        

        cout << "\n";

        i++;
    }
    size_coor = SZ_uz;
    return 0;
    }
int Func::add_Uzel(Func U){
    
    if (size_coor < SZ) {
        cout << "Enter X:";
        get_num(x_coor[size_coor]);
        
        cout << "Enter Y:";
        get_num(y_coor[size_coor]);
        

        cout << "\n";

        size_coor++;
    }
    else{
        cout<< "Количество узлов максимально";
    }
    
    
    return 0;
}

int dialog(){
    int size;
    Func p;


    int res;
    while (true) {
        cout
            << "1. сортировка\n"
            << "2. создание узла(-ов)\n"
            << "3. вывод узлов\n"
            << "4. добавление узла\n"
            << "5. тип функции n\n"
            << "6. вычисление в х0\n"
            << "7. минимум и максимум функции\n"
            << "8. выход\n"
            << endl;
        get_num(res);
        switch (res) {
            case 1:
                p.sortBubl();
            break;

            case 2:
                cout << "Сколько узлов ты хочешь создать?\n"
                ":";
                get_num(size);
                
                
                if (p.saveUzels(size, p) < 0) break;
                p.printFunc(p);

                break;
            case 3:
                p.printFunc(p);
                break;
            case 4:
                p.add_Uzel(p);
                break;
            case 5:
                p.typeF(p);
                break;
            case 6:
                int x0;
                get_num(x0);
                cout << "f ("<< x0 << ") = " << p.calculateF(p, x0) << "\n";
                break;
            case 7:
                p.maxMinFunc(p);
                break;
            case 8:
                return 0;

        }
    }
}
