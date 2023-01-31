#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

#include <vector>

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"

class DroneFactory : public IEntityFactory {
 public:
  /**
   * @brief destructor for DroneFactory.
   */
  virtual ~DroneFactory() {}
  /**
   * @brief Creates a new Drone object.
   *
   * @param entity The JSON representation of the drone.
   *
   * @return A pointer to the newly created Drone object.
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif