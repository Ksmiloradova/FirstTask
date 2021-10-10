#ifndef THEFIRSTTASK_CONTAINER_H
#define THEFIRSTTASK_CONTAINER_H

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "transport.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
struct container {
    enum {max_len = 10000}; // максимальная длина
    int len; // текущая длина
    transport cont[max_len];
};

// Инициализация контейнера
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока
void In(container &c, ifstream &ifst, ofstream &ofst);

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container &c, ofstream &ofst);

// Упорядочение элементов контейнера сортировкой
// простыми вставками с бинарным поиском
void BinaryInsertion(container &c);

#endif //THEFIRSTTASK_CONTAINER_H
