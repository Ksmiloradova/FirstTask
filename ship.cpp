//------------------------------------------------------------------------------
// ship.cpp - содержит функции обработки корабля
//------------------------------------------------------------------------------

#include "ship.h"

//------------------------------------------------------------------------------
// Ввод параметров корабля из потока
bool In(ship &s, ifstream &ifst) {
    int t;
    ifst >> t;
    switch (t % 3 + 1) {
        case 1:
            s.t = ship::LINER;
            break;
        case 2:
            s.t = ship::TUG;
            break;
        case 3:
            s.t = ship::TANKER;
            break;
    }
    ifst >> s.displacement;

    return (s.displacement >= 20000 && s.displacement <= 500000);
}

// Случайный ввод параметров корабля
void InRnd(ship &s) {
    s.displacement = 50000 + rand() % (300000 - 50000 + 1);
    s.t = static_cast<ship::type>(rand() % 3 + 1);
}

//------------------------------------------------------------------------------
// Вывод параметров корабля в поток
void Out(ship &s, ofstream &ofst) {
    ofst << "It is Ship: Displacement = "
         << s.displacement << " kg, Type = ";
    switch (static_cast<int>(s.t)) {
        case 1:
            ofst << "Liner";
            break;
        case 2:
            ofst << "Tug";
            break;
        case 3:
            ofst << "Tanker";
            break;
    }
}
