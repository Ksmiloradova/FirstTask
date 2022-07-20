//------------------------------------------------------------------------------
// airplane_In.cpp - содержит процедуру ввода параметров
// для уже созданного самолета
//------------------------------------------------------------------------------

#include "airplane.h"

//------------------------------------------------------------------------------
// Ввод параметров самолёта из файла
bool In(airplane &r, ifstream &ifst) {
    ifst >> r.flightRange >> r.loadCapacity;
    if (r.flightRange > 20000 || r.flightRange < 5000 ||
    r.loadCapacity < 16000 || r.loadCapacity > 150000) {
        return false;
    }
    return true;
}

// Случайный ввод параметров самолёта
void InRnd(airplane &r) {
    r.flightRange = 20000 + rand() % (5000 + 1);
    r.loadCapacity = 16000 + rand()%(150000 - 16000 + 1);
}

//------------------------------------------------------------------------------
// Вывод параметров самолета в форматируемый поток
void Out(airplane &r, ofstream &ofst) {
    ofst << "It is Airplane: flightRange = " << r.flightRange << " km, loadCapacity = " << r.loadCapacity << " kg";
}
