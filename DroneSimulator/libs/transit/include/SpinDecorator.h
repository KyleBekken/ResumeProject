#ifndef SPIN_DECORATOR_H_
#define SPIN_DECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

class SpinDecorator : public CelebrationDecorator {
 public:
 /**
   * @brief Addes functionality for the drone to spin.
   *
   */
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  bool IsCompleted();
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // SPIN_DECORATOR_H_