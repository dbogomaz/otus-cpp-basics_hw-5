#ifndef MEAN_H
#define MEAN_H

#include "istatistics.h"
#include <cstddef>

class Mean : public IStatistics {
public:
  void update(double next) override;
  double eval() const override;
  const char *name() const override;

private:
  double m_sum{0};
  size_t m_count{0};
};
#endif // MEAN_H