//
// Created by ksmil on 10/7/2021.
//

#ifndef THEFIRSTTASK_AIRPLANE_H
#define THEFIRSTTASK_AIRPLANE_H

//------------------------------------------------------------------------------
// rectangle.h - содержит описание самолёта  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

// прямоугольник
struct airplane {
    int flightRange, loadCapacity; // дальность полета, грузоподъемность
};

// Ввод параметров самолёта из файла
bool In(airplane &r, ifstream &ifst);

// Случайный ввод параметров самолёта
void InRnd(airplane &a);

// Вывод параметров самолёта в форматируемый поток
void Out(airplane &a, ofstream &ofst);

#endif //THEFIRSTTASK_AIRPLANE_H
