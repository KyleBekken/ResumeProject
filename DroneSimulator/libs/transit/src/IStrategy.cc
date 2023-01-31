#include "IStrategy.h"

#include <vector>

double IStrategy::EmissionEQ(double mass, double dt, float speed) {
  return (((9.8 * mass) + (double)(0.58434375 * pow(speed, 2))) *
          (dt * speed)) /
         2944800;
}