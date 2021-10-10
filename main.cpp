//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <stdio.h>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>

#include "container.h"

void errMessage1(ofstream &ofst2) {
    ofst2 << "incorrect command line!\n"
             "  Waited:\n"
             "     command -f infile outfile01 outfile02\n"
             "  Or:\n"
             "     command -n number outfile01 outfile02\n";
}

void errMessage2(ofstream &ofst2) {
    ofst2 << "incorrect qualifier value!\n"
             "  Waited:\n"
             "     command -f infile outfile01 outfile02\n"
             "  Or:\n"
             "     command -n number outfile01 outfile02\n";
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    clock_t start = clock();
    if (argc != 5) {
        ofstream ofst2("ErrorFile.txt");
        errMessage1(ofst2);
        return 1;
    }
    ofstream ofst2(argv[4]);

    ofst2 << "Start" << endl;
    container c;
    Init(c);

    if (!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        In(c, ifst, ofst2);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > container::max_len)) {
            ofst2 << "incorrect number of figures = "
                  << size
                  << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    } else {
        errMessage2(ofst2);
        return 2;
    }
    // Упорядочение элементов контейнера сортировкой простыми вставками с бинарным поиском
    BinaryInsertion(c);
    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    Out(c, ofst1);
    Clear(c);

    ofst2 << "Stop" << endl;
    clock_t end = clock();
    // Вывод времени работы программы в "logFile.txt"
    ofst2 << "Total time = " << (double) (end - start) / CLOCKS_PER_SEC << " seconds\n";
    return 0;
}
