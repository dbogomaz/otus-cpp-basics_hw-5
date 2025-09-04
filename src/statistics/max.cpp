#include "max.h"

#include <stdexcept>

void Max::update(double next) {
    if (!m_max || next > *m_max) {
        m_max = next;
    }
}

double Max::eval() const {
    if (!m_max) {
        throw std::runtime_error("Max::eval() нет данных для вычисления максимума");
    }
    return *m_max;
}

const char* Max::name() const { return "max"; }
