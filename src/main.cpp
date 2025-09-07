// @file main.cpp
#include <iostream>
#include <vector>
// Полный путь не нужен, т.к. в CMakeLists.txt добавлен include_directories
#include "max.h"
#include "mean.h"
#include "min.h"
#include "pst.h"
#include "std.h"

int main() {
    std::cout << "Test program for statistics calculations" << std::endl;

    const size_t statistics_count = 6;
    IStatistics* statistics[statistics_count];

    statistics[0] = new Min{};
    statistics[1] = new Max{};
    statistics[2] = new Mean{};
    statistics[3] = new Std{};
    statistics[4] = new Pst{90};
    statistics[5] = new Pst{95};

    // double val = 0;
    // while (std::cin >> val) {
    //	for (size_t i = 0; i < statistics_count; ++i) {
    //		statistics[i]->update(val);
    //	}
    // }

    std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::cout << "Input data: ";
    for (const auto& val : data) {
        for (size_t i = 0; i < statistics_count; ++i) {
            statistics[i]->update(val);
        }
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Handle invalid input data
    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    }

    // Print results if any
    for (size_t i = 0; i < statistics_count; ++i) {
        std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
    }

    // Clear memory - delete all objects created by new
    for (size_t i = 0; i < statistics_count; ++i) {
        delete statistics[i];
    }

    return 0;
}