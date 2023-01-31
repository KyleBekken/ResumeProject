#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

class RobotFactory : public IEntityFactory {
 public:
  /**
   * @brief Creates a Robot object based on the given JsonObject.
   * @param entity A JsonObject containing info to create robot
   * @return A pointer to the created Robot object.
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif