#ifndef THEFIRSTTASK_SHIP_H
#define THEFIRSTTASK_SHIP_H
//------------------------------------------------------------------------------
// ship.h - содержит описание корабля
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// корабль
struct ship {
    int displacement; // водоизмещение
    enum type {LINER = 1, TUG = 2, TANKER = 3};
    type t;
};

// Ввод параметров корабля из файла
bool In(ship &s, ifstream &ifst);

// Случайный ввод параметров корабля
void InRnd(ship &e);

// Вывод параметров корабля в форматируемый поток
void Out(ship &s, ofstream &ofst);

#endif //THEFIRSTTASK_SHIP_H
