#ifndef THEFIRSTTASK_TRAIN_H
#define THEFIRSTTASK_TRAIN_H
//------------------------------------------------------------------------------
// train.h - содержит описание поезда
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// поезд
struct train {
    int numberOfWagons; // количество вагонов
};

// Ввод параметров поезда из файла
bool In(train &t, ifstream &ifst);

// Случайный ввод параметров поезда
void InRnd(train &e);

// Вывод параметров поезда в форматируемый поток
void Out(train &t, ofstream &ofst);

#endif //THEFIRSTTASK_TRAIN_H
