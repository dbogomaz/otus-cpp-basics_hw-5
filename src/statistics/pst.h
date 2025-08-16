#ifndef PST_H
#define PST_H

#include "istatistics.h"
#include <vector>

class Pst : public IStatistics {
public:
  void update(double next) override;
  double eval() const override;
  const char *name() const override;

private:
  std::vector<double> m_data;
  double m_pst{0.0};
};
#endif // PST_H