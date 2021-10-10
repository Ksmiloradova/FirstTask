//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container &c, ifstream &ifst, ofstream &ofst) {
    while(!ifst.eof()) {
        if(c.len<10000 && In(c.cont[c.len], ifst)) {
            c.len++;
        } else {
            ofst << "Incorrect transport!\n";
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    while(c.len < size) {
        if(InRnd(c.cont[c.len])) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << "\n";
    for(int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        Out(c.cont[i], ofst);
    }
}

//------------------------------------------------------------------------------
// Упорядочение элементов контейнера сортировкой методом деления пополам
void BinaryInsertion(container &c) {
    int i;
    transport selected;

    for (i = 1; i < c.len; ++i) {
        selected = c.cont[i];
        // Бинарный поиск места вставки
        int low = 0, high = i - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (IdealTravelTime(selected) == IdealTravelTime(c.cont[mid])) {
                low = mid + 1;
                break;
            }
            else if (IdealTravelTime(selected) < IdealTravelTime(c.cont[mid]))
                low = mid + 1;
            else
                high = mid;
        }
        if (high <= low) {
            low = (IdealTravelTime(selected) < IdealTravelTime(c.cont[low])) ? (low + 1) : low;
        }
        int j = i - 1;

        // Перемещение элементов дляя создания пространства для вставки
        for (; j >= low; --j) {
            c.cont[j + 1] = c.cont[j];
        }
        c.cont[j + 1] = selected;
    }
}
