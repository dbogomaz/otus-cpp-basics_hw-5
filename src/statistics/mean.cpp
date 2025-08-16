#include "mean.h"


void Mean::update(double next) {
  m_sum += next;
  ++m_count;
}

double Mean::eval() const {
  if (m_count == 0) {
    return 0.0;
  }
  return m_sum / m_count;
}

const char *Mean::name() const { return "mean"; }
