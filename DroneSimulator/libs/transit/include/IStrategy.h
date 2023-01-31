#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

#include <vector>

#include "IEntity.h"
#include "graph.h"

using namespace routing;

class IStrategy {
 public:
  /**
   * @brief Moves entity for the given strategy.
   *
   * @param entity The entity to move.
   * @param dt The time step.
   */
  virtual void Move(IEntity* entity, double dt) = 0;
  /**
   * @brief Returns whether the strategy has been completed.
   *
   * @return bool if compleated
   */
  virtual bool IsCompleted() = 0;

 protected:
  // IGraph object to be used in the simulation.
  double EmissionEQ(double mass, double dt, float speed);
  const IGraph* graph;
};  // close class

#endif  // ISTRATEGY_H_