#ifndef DFS_STRATEGY_H_
#define DFS_STRATEGY_H_

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
class DfsStrategy : public IStrategy {
 public:
  /**
   * @brief Constructs a new instance of DFSStrategy that finds a path between
   *        the given start and end points in the given graph.
   *
   * @param position The start position for the path.
   * @param destination The end position for the path.
   * @param graph The graph to search for the path.
   */
  DfsStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
  /**
   * @brief Destuctor for instance of DFSStrategy.
   */
  ~DfsStrategy();
  /**
   * @brief Makes the entity move along the path found by the DFSStrategy.
   *
   * @param entity The entity to move.
   * @param dt time since the last update
   */
  void Move(IEntity* entity, double dt);
  /**
   * @brief Returns whether if end of the path has been reached.
   *
   * @return bool if the end of the path is reached
   */
  bool IsCompleted();

 private:
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // DFS_STRATEGY_H_