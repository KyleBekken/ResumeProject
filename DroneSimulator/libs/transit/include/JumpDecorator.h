#ifndef JUMP_DECORATOR_H_
#define JUMP_DECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

class JumpDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief Constructor for the JumpDecorator class.
   *
   * @param strategy_ A pointer to the strategy to be decorated.
   */
  JumpDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  /**
   * @brief Determines whether the decorated strategy has been completed.
   *
   * @return bool if compleated
   */
  bool IsCompleted();
  /**
   * @brief Makes the decorated strategy move and adds a jumping behavior.
   *
   * @param entity A pointer to the entity using the strategy.
   * @param dt The time elapsed
   */
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // JUMP_DECORATOR_H_