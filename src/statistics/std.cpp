#include "std.h"
#include <cmath>

void Std::update(double next) {
  m_data.push_back(next);
  m_sum += next;
  double mean = m_sum / m_data.size();
  double varianceSum{0.0};
  for (const auto &value : m_data) {
    varianceSum += (value - mean) * (value - mean);
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
