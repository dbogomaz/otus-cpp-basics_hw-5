#ifndef MAX_H
#define MAX_H

#include "istatistics.h"
#include <optional>

class Max : public IStatistics {
public:
  void update(double next) override;
  double eval() const override;
  const char *name() const override;

private:
  std::optional<double> m_max;
};
#endif // MAX_H