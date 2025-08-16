#include "pst.h"
#include <cmath>
#include <algorithm>

void Pst::update(double next) {
  m_data.push_back(next);
  std::sort(m_data.begin(), m_data.end());
  const double percentile = 90;
  double rank = (percentile / 100.0) * m_data.size(); // Ранг перцентиля 
  // Интерполяция
  double index = rank - 1; // Сдвиг на 1, так как индексы с 0
  int lower = static_cast<int>(index);
  double fraction = index - lower;

  if (lower + 1 < m_data.size()) {
    m_pst = m_data[lower] + fraction * (m_data[lower + 1] - m_data[lower]);
  } else {
    m_pst = m_data[m_data.size() - 1]; // Последний элемент, если ранг выходит за пределы
  }
}

double Pst::eval() const {
  if (m_data.empty()) {
    return 0.0;
  }
  return m_pst;
}

const char *Pst::name() const { return "pst"; }
