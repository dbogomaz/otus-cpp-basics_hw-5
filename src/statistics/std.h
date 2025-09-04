#ifndef STD_H
#define STD_H

#include "istatistics.h"
#include <vector>
#include "mean.h"

class Std : public IStatistics {
public:
  void update(double next) override;
  double eval() const override;
  const char *name() const override;

private:
  std::vector<double> m_data;
  Mean m_mean;
};
#endif // STD_H