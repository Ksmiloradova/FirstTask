#include "transport.h"
//------------------------------------------------------------------------------
// transport.cpp - содержит процедуры связанные с обработкой обобщенного транспорта
// и создания произвольного транспорта
//------------------------------------------------------------------------------

#include "transport.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного транспорта из файла
bool In(transport &tr, ifstream &ifst) {
    int k;
    ifst >> k;
    ifst >> tr.speed >> tr.distance;
    switch (k) {
        case 1:
            tr.k = transport::AIRPLANE;
            return In(tr.a, ifst) && !(tr.speed < 500 || tr.speed > 900);
        case 2:
            tr.k = transport::TRAIN;
            return In(tr.t, ifst) && !(tr.speed < 80 || tr.speed > 200);
        case 3:
            tr.k = transport::SHIP;
            return In(tr.s, ifst) && !(tr.speed < 19 || tr.speed > 67);
        default:
            return false;
    }
}

// Случайный ввод обобщенного транспорта
bool InRnd(transport &tr) {
    // Генерация расстояния от 1000 до 20000.99 км
    tr.distance = 1000 + rand() % (20000 - 1000 + 1) + rand() % 100 / 100.0;
    auto k = rand() % 3 + 1;
    switch (k) {
        case 1:
            tr.k = transport::AIRPLANE;
            InRnd(tr.a);
            // Генерация скорости самолёта от 500 до 900 км/ч
            tr.speed = 500 + rand() % (900 - 500 + 1);
            return true;
        case 2:
            tr.k = transport::TRAIN;
            InRnd(tr.t);
            // Генерация скорости поезда от 80 до 200 км/ч
            tr.speed = 80 + rand() % (200 - 80 + 1);
            return true;
        case 3:
            tr.k = transport::SHIP;
            InRnd(tr.s);
            // Генерация скорости корабля от 19 до 67 км/ч
            tr.speed = 19 + rand() % (67 - 19 + 1);
            return true;
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего транспорта в поток
void Out(transport &tr, ofstream &ofst) {
    switch (tr.k) {
        case transport::AIRPLANE:
            Out(tr.a, ofst);
            ofst << "\n" << "   IdealTravelTime = " << IdealTravelTime(tr) << " h. Speed = " << tr.speed
                 << " km/h. Distance to destination = " << tr.distance << " km\n";
            break;
        case transport::TRAIN:
            Out(tr.t, ofst);
            ofst << "\n" << "   IdealTravelTime = " << IdealTravelTime(tr) << " h. Speed = " << tr.speed
                 << " km/h. Distance to destination = " << tr.distance << " km\n";
            break;
        case transport::SHIP:
            Out(tr.s, ofst);
            ofst << "\n" << "   IdealTravelTime = " << IdealTravelTime(tr) << " h. Speed = " << tr.speed
                 << " km/h. Distance to destination = " << tr.distance << " km\n";
            break;
        default:
            ofst << "Incorrect transport!" << "\n";
    }
}

//------------------------------------------------------------------------------
// Вычисление идеального времени прохождения пути
double IdealTravelTime(transport &tr) {
    return tr.distance / tr.speed;
}
