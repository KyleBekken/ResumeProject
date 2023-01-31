#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

class Robot : public IEntity {
 public:
  /**
   * @brief Constructor for the Robot class.
   *
   * @param obj A JSON object containing the initialization data for the robot.
   */
  Robot(JsonObject& obj);
  /**
   * @brief Destructor for the Robot class.
   */
  ~Robot() override = default;
  /**
   * @brief Gets the position of the robot.
   *
   * @return The position of the robot.
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets the direction of the robot.
   *
   * @return The direction of the robot.
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets the destination of the robot.
   *
   * @return The destination of the robot.
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets the availability of the robot.
   *
   * @return A boolean indicating whether the robot is available.
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Gets the details of the robot.
   *
   * @return A JSON object containing the details of the robot.
   */
  JsonObject GetDetails() const override;
  /**
   * @brief Gets the speed of the robot.
   *
   * @return The speed of the robot.
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets the number of passengers carried by the robot.
   *
   * @return The number of passengers carried by the robot.
   */
  int GetNumPassengers() const { return numPassengers; }
  /**
   * @brief Get the mass of the robot.
   * @return The mass of the robot (0.0 for robots, as they have no mass).
   */
  double GetMass() const { return 0.0; }
  /**
   * @brief Get the name of the strategy being used by the robot.
   * @return The name of the strategy.
   */
  std::string GetStrategyName() { return strategyName; }
  /**
   * @brief Set the availability status of the robot.
   * @param choice True if the robot should be available, false if it should be
   * unavailable.
   */
  void SetAvailability(bool choice);
  /**
   * @brief Sets the position of the entity.
   *
   * @param pos_ The new position of the entity as a Vector3 object.
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the direction of the entity.
   *
   * @param dir_ The new direction of the entity as a Vector3 object.
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the destination of the entity.
   *
   * @param des_ The new destination of the entity as a Vector3 object.
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Sets the number of passengers carried by the entity.
   *
   * @param numPassengers_ The new  number of passengers as an int.
   */
  void SetNumPassengers(int pass_) { numPassengers = pass_; }
  /**
   * @brief Sets the name of the strategy used by the entity.
   *
   * @param strategyName_ The new name of the strategy as a string.
   */
  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }

  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  int numPassengers;
  bool available;
  std::string strategyName;
};

#endif  // ROBOT_H
