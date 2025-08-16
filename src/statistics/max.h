#ifndef MAX_H
#define MAX_H

#include "istatistics.h"
#include <limits>

class Max : public IStatistics {
public:
  void update(double next) override;
  double eval() const override;
  const char *name() const override;

private:
  double m_max{std::numeric_limits<double>::min()};
};
#endif // MAX_H