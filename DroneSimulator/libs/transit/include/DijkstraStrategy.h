#ifndef Dijkstra_STRATEGY_H_
#define Dijkstra_STRATEGY_H_

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
class DijkstraStrategy : public IStrategy {
 public:
  /**
   * @brief Constructs a new instance of DijStrategy that finds a path between
   *        the given start and end points in the given graph.
   *
   * @param position The start position for the path.
   * @param destination The end position for the path.
   * @param graph The graph to search for the path.
   */
  DijkstraStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
  /**
   * @brief Destuctor for the Dijistra Strategy
   */
  ~DijkstraStrategy();
  void Move(IEntity* entity, double dt);
  bool IsCompleted();

 private:
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // Dijkstra_STRATEGY_H_