// @file bug_fix_tests.cpp
#include <gtest/gtest.h>

#include <cmath>
#include <sstream>

#include "../src/statistics/istatistics.h"
#include "../src/statistics/max.h"
#include "../src/statistics/mean.h"
#include "../src/statistics/min.h"
#include "../src/statistics/pst.h"
#include "../src/statistics/std.h"

// 1. Вывод может быть неожиданным для пользователя нашего класса:
// std::cout << Min{}.eval() << std::endl; Мелочь, не оговоренная явно в задании,
// но всегда лучше обрабатывать граничные случаи.
TEST(BugFixTests, Bug1) {
    Min min;
    std::cout << "Initial min: " << min.eval() << std::endl;
    // Проверяем, что до обновления значение eval() возвращает NaN
    EXPECT_TRUE(std::isnan(min.eval()));
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
TEST(BugFixTests, Bug3) {
    Mean mean;
    for (size_t i = 0; i < 11; i++) {
        mean.update(i);
    }
    EXPECT_DOUBLE_EQ(mean.eval(), 5.0);
}

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
