#ifndef STD_H
#define STD_H

#include "istatistics.h"
#include <vector>

class Std : public IStatistics {
public:
  void update(double next) override;
  double eval() const override;
  const char *name() const override;

private:
  std::vector<double> m_data;
  double m_std{0.0};
  double m_sum{0.0};
};
#endif // STD_H