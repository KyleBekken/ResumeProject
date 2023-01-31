#ifndef CO2TRACKER_H_
#define CO2TRACKER_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief This class tracks the total amount of CO2 emitted and the amount
 * of CO2 emitted using different strategys.
 */
class CO2Tracker {
 private:
  /**
   * @brief constructor
   */
  CO2Tracker() {
    totalCO2 = 0;
    astarCO2 = 0;
    beelineCO2 = 0;
    dijkstraCO2 = 0;
  }
  CO2Tracker(const CO2Tracker&) {}
  /**
   * @brief assignment operator
   */
  CO2Tracker& operator=(const CO2Tracker&) {}

  /**
   * @brief The total amount of CO2 emitted.
   */
  double totalCO2;
  /**
   * @brief The amount of CO2 emitted using the Astar strategy.
   */
  double astarCO2;
  /**
   * @brief The amount of CO2 emitted using the Beeline strategy.
   */
  double beelineCO2;
  /**
   * @brief The amount of CO2 emitted using the DFS strategy.
   */
  double DFSCO2;
  /**
   * @brief The amount of CO2 emitted using the Dijkstra strategy.
   */
  double dijkstraCO2;

 public:
  /**
   * @brief Gets a single instance of the CO2Tracker class.
   *
   * @return a single instance of the CO2Tracker class.
   */
  static CO2Tracker& GetInstance() {
    static CO2Tracker* instance = NULL;
    if (instance == NULL) {
      instance = new CO2Tracker();
    }
    return *instance;
  }

  /**
   * @brief Adds to the total amount of CO2 emitted.
   *
   * @return The amount of CO2 that has been emitted over the course of the
   * simulation.
   */
  double GetTotalCO2() { return totalCO2; }

  /**
   * @brief Adds to the amount of CO2 emitted using the Astar strategy.
   *
   * @return The amount of CO2 that has been emitted by drones following the
   * Astar movement strategy over the course of the simulation.
   */
  double GetAstarCO2() { return astarCO2; }

  /**
   * @brief Adds to the amount of CO2 emitted using the Beeline strategy.
   *
   * @return The amount of CO2 that has been emitted by drones following the
   * Beeline movement strategy over the course of the simulation.
   */
  double GetBeelineCO2() { return beelineCO2; }

  /**
   * @brief Adds to the amount of CO2 emitted using the DFS strategy.
   *
   * @return The amount of CO2 that has been emitted by drones following the DFS
   * movement strategy over the course of the simulation.
   */
  double GetDFSCO2() { return DFSCO2; }

  /**
   * @brief Adds to the amount of CO2 emitted using the Dijkstra strategy.
   *
   * @return The amount of CO2 that has been emitted by drones following the
   * Dijkstra movement strategy over the course of the simulation.
   */
  double GetDijkstraCO2() { return dijkstraCO2; }

  /**
   * @brief Adds to the total amount of CO2 emitted.
   *
   * @param x The amount of CO2 to add to the total.
   */
  void AddTotalCO2(double x, double dt, int y) { totalCO2 += x; }

  /**
   * @brief Adds to the amount of CO2 emitted using the Astar strategy.
   *
   * @param x The amount of CO2 to add to the total for Astar strategy.
   */
  void AddAstarCO2(double x) {
    totalCO2 += x;
    astarCO2 += x;
  }

  /**
   * @brief Adds to the amount of CO2 emitted using the Beeline strategy.
   *
   * @param x The amount of CO2 to add to the total for the Beeline strategy.
   */
  void AddBeelineCO2(double x) {
    totalCO2 += x;
    beelineCO2 += x;
  }

  /**
   * @brief Adds to the amount of CO2 emitted using the DFS strategy.
   *
   * @param x The amount of CO2 to add to the total for DFS strategy.
   */
  void AddDFSCO2(double x) {
    totalCO2 += x;
    DFSCO2 += x;
  }

  /**
   * @brief Adds to the amount of CO2 emitted using the Dijkstra strategy.
   *
   * @param x The amount of CO2 to add to the total for Dijkstra strategy.
   */
  void AddDijkstraCO2(double x) {
    totalCO2 += x;
    dijkstraCO2 += x;
  }
};

#endif