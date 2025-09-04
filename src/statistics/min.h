#ifndef MIN_H
#define MIN_H

#include <optional>

#include "istatistics.h"

class Min : public IStatistics {
public:
    void update(double next) override;
    double eval() const override;
    const char* name() const override;

private:
    std::optional<double> m_min;
};
#endif  // MIN_H