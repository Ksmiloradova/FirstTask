#ifndef THEFIRSTTASK_TRANSPORT_H
#define THEFIRSTTASK_TRANSPORT_H

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include "airplane.h"
#include "train.h"
#include "ship.h"

//------------------------------------------------------------------------------
// структура, обобщающая весь имеющийся транспорт
struct transport {
    // значения ключей для каждого транспорта
    enum key {
        AIRPLANE, TRAIN, SHIP
    };
    key k; // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию
        airplane a;
        train t;
        ship s;
    };

    int speed; // скорость
    double distance; // расстояние между пунктами отправления и назначения
};

// Ввод обобщенного транспорта
bool In(transport &tr, ifstream &ifdt);

// Случайный ввод обобщенного транспорта
bool InRnd(transport &tr);

// Вывод обобщенного транспорта
void Out(transport &tr, ofstream &ofst);

// Вычисление идеального времени прохождения пути
double IdealTravelTime(transport &tr);

#endif //THEFIRSTTASK_TRANSPORT_H
