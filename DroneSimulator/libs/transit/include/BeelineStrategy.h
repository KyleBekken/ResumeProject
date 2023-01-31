#ifndef BEELINE_H_
#define BEELINE_H_

/**
 * include
 */
#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for
 * generating the beeline that the drone will take.
 */
class BeelineStrategy : public IStrategy {
 public:
  /**
   * @brief Constructs a new BeelineStrategy object.
   *
   * @param position The starting position for the beeline.
   * @param destination The destination for the beeline.
   */
  BeelineStrategy(Vector3 position, Vector3 destination);
  /**
   * @brief Destuctor for the BeelineStrategy object.
   */
  ~BeelineStrategy();
  /**
   * @brief Moves the entity along the beeline.
   *
   * @param entity The entity to move.
   * @param dt The time step.
   */
  void Move(IEntity* entity, double dt);
  /**
   * @brief Returns whether the beeline has been completed.
   *
   * @return bool if compleated
   */
  bool IsCompleted();

 private:
  Vector3 position;
  Vector3 destination;
};      // end class
#endif  // BEELINE_H_