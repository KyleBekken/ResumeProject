#ifndef ASTAR_STRATEGY_H_
#define ASTAR_STRATEGY_H_

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
class AstarStrategy : public IStrategy {
 public:
  AstarStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
  /**
   * @brief Destructor for the AstarStrategy object.
   */
  ~AstarStrategy();
  /**
   * @brief Moves the entity along the path.
   *
   * @param entity The entity to move.
   * @param dt The time step.
   */
  void Move(IEntity* entity, double dt);
  /**
   * @brief Returns whether the path has been completed.
   *
   * @return bool if compleated
   */
  bool IsCompleted();

 private:
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // ASTAR_STRATEGY_H_