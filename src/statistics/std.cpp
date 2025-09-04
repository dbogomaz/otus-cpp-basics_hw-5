#include "std.h"
#include <cmath>

void Std::update(double next) {
  m_data.push_back(next);
  m_mean.update(next);
  double varianceSum{0.0};
  for (const auto &value : m_data) {
    varianceSum += (value - m_mean.eval()) * (value - m_mean.eval());
  }
  m_std = std::sqrt(varianceSum / m_data.size());
}

double Std::eval() const {
  if (m_data.empty()) {
    return 0.0;
  }
  return m_std;
}

const char *Std::name() const { return "std"; }
