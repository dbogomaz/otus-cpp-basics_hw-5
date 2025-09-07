// @file bug_fix_tests.cpp
#include <gtest/gtest.h>

#include <cmath>
#include <sstream>
// Полный путь не нужен, т.к. в CMakeLists.txt добавлен include_directories
#include "istatistics.h"
#include "max.h"
#include "mean.h"
#include "min.h"
#include "pst.h"
#include "std.h"

// 1. Вывод может быть неожиданным для пользователя нашего класса:
// std::cout << Min{}.eval() << std::endl; Мелочь, не оговоренная явно в задании,
// но всегда лучше обрабатывать граничные случаи.
TEST(BugFixTests, Bug1) {
    Min min;
    EXPECT_THROW(min.eval(), std::runtime_error);  // должно выбросить исключение
    Max max;
    EXPECT_THROW(max.eval(), std::runtime_error);  // должно выбросить исключение
    Mean mean;
    EXPECT_DOUBLE_EQ(mean.eval(), 0.0);  // должно быть 0, т.к. сумма 0 и count 0
    Std std;
    EXPECT_DOUBLE_EQ(std.eval(), 0.0);  // должно быть 0, т.к. сумма 0 и count 0
    Pst pst(90);
    EXPECT_DOUBLE_EQ(pst.eval(), 0.0);  // должно быть 0,
}

// 2.Вывод этого кода обескураживает, точно стоит исправить:
// Max max;
// max.update(0);
// std::cout << "max: " << max.eval() << std::endl;
TEST(BugFixTests, Bug2) {
    Max max;
    max.update(0);
    EXPECT_DOUBLE_EQ(max.eval(), 0.0);
}

// 3. В Std можно переиспользовать реализацию Mean.
// Mean mean;
// std::cout << mean.eval() << std::endl;

// 4. Расчет varianceSum и т.п. лучше проводить непосредственно в eval,
// т.к. в общем случае логично предположить, что eval вызывается реже
// update и сейчас часть вычислений игнорируется.
TEST(BugFixTests, Bug4) {
    Std std;
    for (size_t i = 0; i < 11; i++) {
        std.update(i);
    }
    EXPECT_DOUBLE_EQ(std.eval(), std::sqrt(10.0));
}
