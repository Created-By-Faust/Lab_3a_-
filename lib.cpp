#include "lib.hpp"

#include <iomanip>


using namespace std;
namespace LIB{


    
    /*Func(double X_coor, double Y_coor, uzel Uz[])
    {
        for (size_t i = 0; i < size_coor; i++)
        {
            Uz[i].x_coor = X_coor;
            Uz[i].y_coor = Y_coor;
        }
        size_coor++;
    }

    Func(double X_coor, double Y_coor) //конструктор по добавлению одного узла
    {
        if (size_coor < SZ) {
            x_coor[size_coor] = X_coor;
            y_coor[size_coor] = Y_coor;
            size_coor++;
        }
    }

    Func(int SZ, uzel U[]) //конструктор с инициализацией количеством узлов и значениями функции в узла
    {
        for (size_t i = 0; i < SZ; i++)
        {
            x_coor[i] = U[i].x_coor;
            y_coor[i] = U[i].y_coor;
        }

    }

    Func(int SZ, uzel U[], double x, double y)
    {
        for (size_t i = 0; i < SZ; i++)
        {
            U[i].x_coor = x;
            U[i].y_coor = y;
        }
        size_coor = SZ;
    }*/

    //Пузырьковая сортировка
    void Func::sortBubl() {
        int last = SZ; bool ok;
        do {
            last = last - 1;
            ok = true;
            for (int i = 0; i < last; i++) {
                if (x_coor[i] > x_coor[i + 1]) {
                    int x = x_coor[i];
                    int y = y_coor[i];
                    x_coor[i] = x_coor[i + 1];
                    y_coor[i] = y_coor[i + 1];
                    x_coor[i + 1] = x;
                    y_coor[i + 1] = y;
                    ok = false;
                }
            }
        } while (!ok);
    }

    //Поиск максимального и минимального элемента
    void Func::maxMinFunc(Func f)
    {
        int indexMax = 0;
        int indexMin = 0;
        double maxVal = f.y_coor[0], minVal = f.y_coor[0];
        for (size_t i = 0; i < 20; i++)
        {
            if (f.y_coor[i] > maxVal)
            {
                indexMax = i;
                maxVal = f.y_coor[i];
            }
            if (f.y_coor[i] < minVal)
            {
                indexMin = i;
                minVal = f.y_coor[i];
            }
        }
        cout << "f (" << f.x_coor[indexMax] << ") = " << maxVal << "\n";
        cout << "f (" << f.x_coor[indexMin] << ") = " << minVal << "\n";


    }

    void Func::typeF(Func f)
    {
        f.sortBubl();
        int ub = 0;
        int vozr = 0;
        int post = 0;
        for (size_t i = 0; i < SZ-1; i++)
        {
            if (f.y_coor[i + 1] > f.y_coor[i])
                vozr++;
            else if (f.y_coor[i + 1] < f.y_coor[i])
                ub++;
            else
                post++;
        }
        if (ub > 0 and vozr > 0)
            cout << "f  = variable(?)" << "\n";
        else if (ub > 0 and vozr == 0 and post == 0)
            cout << "f  = decreases(-)" << "\n";
        else if (vozr > 0 and ub == 0 and post == 0)
            cout << "f = increases(+)" << "\n";
        else if (post > 0 and ub == 0 and vozr == 0)
            cout << "f = constant(=)" << "\n";
    }


    double Func::calculateF(Func f, double xO)
    {
        f.sortBubl();
        int max = f.x_coor[0];
        int indexMax = 0;  // индекс
        for (int i = 0; i < SZ; i++)
        {
            if (f.x_coor[i] <= max && xO <= f.x_coor[i]) { max = f.x_coor[i]; indexMax = i; }
        }
        // вычисление ближайшего меньшего и его индекса

        int min = f.x_coor[SZ-1];
        int indexMin = 0;
        for (int i = 0; i < SZ; i++)
        {
            if (f.x_coor[i] >= min && xO >= f.x_coor[i]) { min = f.x_coor[i]; indexMin = i; };
        }
        double Y = (double(max - xO) / (max - min)) * f.y_coor[indexMin] + (double(xO - min) / (max - min)) * f.y_coor[indexMax];
        return Y;

    }

    void Func::printFunc( Func f)
    {   int size = SZ;
        cout << "-----------------------------------------------------------------------------\n";
        cout << " X ||";
        for (size_t i = 0; i < size; i++)
        {
            cout << setw(2) << f.x_coor[i] << setw(2) << "|";
        }
        cout << "\n";
        cout << "-----------------------------------------------------------------------------\n";
        cout << " Y ||";
        for (size_t i = 0; i < size; i++)
        {
            cout << setw(2) << f.y_coor[i] << setw(2) << "|";
        }
        cout << "\n";
        cout << "-----------------------------------------------------------------------------\n";
    }

  

    
}


