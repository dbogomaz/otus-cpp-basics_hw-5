#include "min.h"

#include <stdexcept>

void Min::update(double next) {
    if (!m_min || next < *m_min) {
        m_min = next;
    }
}

double Min::eval() const {
    if (!m_min) {
        throw std::runtime_error("Min::eval() нет данных для вычисления минимума");
    }
    return *m_min;
}

const char* Min::name() const { return "min"; }
