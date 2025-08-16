#ifndef PST_H
#define PST_H

#include "istatistics.h"
#include <vector>
#include <string>

class Pst : public IStatistics {
public:
  Pst(double percentile = 50.0);
  void update(double next) override;
  double eval() const override;
  const char *name() const override;

private:
  std::vector<double> m_data;
  double m_pst{0.0};
  const double m_percentile{50};
  std::string m_name{"pst"};
};
#endif // PST_H