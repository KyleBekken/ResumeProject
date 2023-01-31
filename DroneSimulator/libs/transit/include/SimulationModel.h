#ifndef SIMULATION_MODEL_H_
#define SIMULATION_MODEL_H_

#include "CompositeFactory.h"
#include "IController.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/// Simulation Model handling the transit simulation.  The model can communicate
/// with the controller.
class SimulationModel {
 public:
  /**
   * @brief Constructs a SimulationModel object with a reference to the given
   * controller.
   * @param controller A reference to the IController object.
   */
  SimulationModel(IController& controller);
  /**
   * @brief Sets the graph for the simulation model.
   * @param graph A pointer to the IGraph object.
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief Creates an simulation entity based on the given JsonObject.
   * @param entity A JsonObject containing the information to create the
   * simulation entity.
   */
  void CreateEntity(JsonObject& entity);

  /**
   * @brief Schedules a trip for an object in the simulation.
   * @param details A JsonObject containing the necessary details for scheduling
   * the trip.
   */
  void ScheduleTrip(JsonObject& details);

  /**
   * @brief Updates the simulation.
   * @param dt The time step for the update.
   */
  void Update(double dt);

  /**
   * @brief Adds a new entity type to the simulation model.
   * @param factory A pointer to the IEntityFactory object for the new entity
   * type.
   */
  void AddFactory(IEntityFactory* factory);

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  const IGraph* graph;
  CompositeFactory* compFactory;

 private:
  int dtTracker;
};

#endif
