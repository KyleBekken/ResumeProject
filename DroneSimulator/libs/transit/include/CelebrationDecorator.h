#ifndef CELEBRATION_DECORATOR_H_
#define CELEBRATION_DECORATOR_H_

#include <vector>

#include "IStrategy.h"

class CelebrationDecorator : public IStrategy {
 public:
  /**
   * @brief Constructs a new instance of CelebrationDecorator that decorates
   *        the given strategy.
   *
   * @param strategy_ The IStrategy to decorate with the celebration behavior.
   */
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }
  /**
   * @brief Makes the strategy perform its movement and updates the
   *        celebration behavior.
   *
   * @param entity The entity to move.
   * @param dt The elapsed time since the last update, in seconds.
   */
  void Move(IEntity *entity, double dt);
  /**
   * @brief Returns whether the  strategy and the celebration
   *        behavior have both completed.
   *
   * @return True if the strategy and the celebration behavior
   *         have completed, false otherwise.
   */
  bool IsCompleted();

 protected:
  IStrategy *strategy;
  float time;
};  // close class

#endif  // CELEBRATION_DECORATOR_H_