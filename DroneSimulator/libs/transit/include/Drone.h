#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
class Drone : public IEntity {
 public:
  /**
   * @brief Constructs a new instance of Drone with the given name.
   *
   * @param obj The JSON representation of the drone.
   */
  // Drones are created with a name
  Drone(JsonObject& obj);
  /**
   * @brief Destuctor of the drone
   */
  // Destructor
  ~Drone();
  /**
   * @brief Gets the speed of the drone.
   *
   * @return speed of the drone
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets the number of passengers
   *
   * @return The number of passengers
   *
   */
  int GetNumPassengers() const { return numPassengers; }
  /**
   * @brief Gets the mass of the drone.
   *
   * @return The mass of the drone
   */
  double GetMass() const { return mass; }
  /**
   * @brief Gets the current position of the drone.
   *
   * @return The current position of the drone.
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets the current destination of the drone.
   *
   * @return The current destination of the drone.
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets the current destination of the drone.
   *
   * @return The current destination of the drone.
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets the details of the drone as a JSON object.
   *
   * @return The details of the drone as a JSON object.
   */
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Gets the availability of the drone.
   *
   * @return True if the drone is available, false otherwise.
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Gets the nearest entity to the drone.
   *
   * @param scheduler The vector of entities to search for the nearest entity.
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);
  /**
   * @brief Updates the drone's position based on its velocity and direction.
   *
   * @param dt The elapsed time since the last update
   * @param scheduler The vector IENTITY to search for the nearest entity.
   */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief Sets the position of the drone.
   *
   * @param pos_ The new position of the drone.
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the position of the drone.
   *
   * @param pos_ The new position of the drone.
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the destination of the drone.
   *
   * @param des_ The new destination of the drone.
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Does nothing, since drones do not have passengers.
   *
   * @param pass_ The number of passengers to set.
   *
   */
  void SetNumPassengers(int pass_) {}

  /**
   * @brief Rotates the drone by the given angle.
   *
   * @param angle The angle to rotate the drone by
   */
  void Rotate(double angle);
  /**
   * @brief Jumps a given amount
   *
   * @param height a height to jump by
   */
  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that drones cannot be coppied.
  Drone(const Drone& drone) = delete;
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
  Vector3 destination;
  float speed;
  int numPassengers;
  double mass;
  bool massChanged;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
};

#endif
