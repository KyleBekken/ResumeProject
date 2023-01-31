#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View
/// Controller Pattern
/**
 * @class IEntity
 *
 * @brief Abstract class representing an entity in the Transit Service program.
 *
 */
class IEntity {
 public:
  /**
   * @brief Constructor for IEntity.
   *
   */
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }
  /**
   * @brief destructor for IEntity.
   */
  virtual ~IEntity() {}
  /**
   * @brief Gets the ID
   */
  virtual int GetId() const { return id; }
  /**
   * @brief Gets the position of the entity.
   *
   * @return The position of the entity as a Vector3 object.
   */
  virtual Vector3 GetPosition() const = 0;
  /**
   * @brief Gets the direction of the entity.
   *
   * @return The direction of the entity as a Vector3 object.
   */
  virtual Vector3 GetDirection() const = 0;
  /**
   * @brief Gets the details of the entity.
   *
   * @return The details of the entity as a JsonObject.
   */
  virtual Vector3 GetDestination() const = 0;
  /**
   * @brief Gets the details of the entity.
   *
   * @return The details of the entity as a JsonObject.
   */
  virtual JsonObject GetDetails() const = 0;
  /**
   * @brief Gets the mass of the entity.
   *
   * @return The mass of the entity as a double.
   */
  virtual double GetMass(){};
  /**
   * @brief Gets the speed of the entity.
   *
   * @return The speed of the entity as a float.
   */
  virtual float GetSpeed() const = 0;
  /**
   * @brief Gets the availability of the entity.
   *
   * @return The availability of the entity as bool.
   */
  virtual bool GetAvailability() const {};
  /**
   * @brief Gets the name of the strategy used by the entity.
   *
   * @return The name of the strategy as a string.
   */
  virtual std::string GetStrategyName() {}
  /**
   * @brief Gets the number of passengers carried by the entity.
   *
   * @return The number of passengers as an int.
   */
  virtual int GetNumPassengers() const = 0;
  /**
   * @brief Sets the availability of the entity.
   *
   * @param choice The new availability of the entity as a bool.
   */
  virtual void SetAvailability(bool choice) {}
  /**
   * @brief Updates the state of the entity.
   *
   * @param dt The time step for the update.
   * @param scheduler A vector of IEntity objects representing the entites
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}
  /**
   * @brief Sets the graph used by the entity.
   *
   * @param graph A pointer to the IGraph object used by the entity.
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
   * @brief Sets the position of the entity.
   *
   * @param pos_ The new position of the entity as a Vector3 object.
   */
  virtual void SetPosition(Vector3 pos_) {}
  /**
   * @brief Sets the direction of the entity.
   *
   * @param dir_ The new direction of the entity as a Vector3 object.
   */
  virtual void SetDirection(Vector3 dir_) {}
  /**
   * @brief Sets the destination of the entity.
   *
   * @param des_ The new destination of the entity as a Vector3 object.
   */
  virtual void SetDestination(Vector3 des_) {}
  /**
   * @brief Sets the name of the strategy used by the entity.
   *
   * @param strategyName_ The new name of the strategy as a string.
   */
  virtual void SetStrategyName(std::string strategyName_) {}
  /**
   * @brief Sets the number of passengers carried by the entity.
   *
   * @param numPassengers_ The new  number of passengers as an int.
   */
  virtual void SetNumPassengers(int numPassengers_) {}
  /**
   * @brief Makes the entity jump.
   *
   * @param height The height of the jump.
   */
  virtual void Rotate(double angle) {}
  /**
   * @brief The ID of the entity.
   */
  virtual void Jump(double height) {}

 protected:
  int id;
  const IGraph* graph;
};

#endif
