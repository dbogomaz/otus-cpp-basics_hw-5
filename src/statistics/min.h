#ifndef MIN_H
#define MIN_H

#include "istatistics.h"
#include <limits>

class Min : public IStatistics {
public:
  void update(double next) override;
  double eval() const override;
  const char *name() const override;

private:
  double m_min{std::numeric_limits<double>::max()};
};
#endif // MIN_H