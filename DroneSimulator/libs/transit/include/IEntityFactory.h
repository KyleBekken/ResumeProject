#ifndef I_ENTITY_FACTORY_H_
#define I_ENTITY_FACTORY_H_

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"
#include "util/json.h"
/**
 * @brief An interface for creating entities.
 */
class IEntityFactory {
 public:
  /**
   * @brief destructor for the IEntityFactory.
   */
  virtual ~IEntityFactory() {}
  /**
   * @brief Creates an entity.
   *
   * @param entity A JsonObject containing the details of the entity to be
   *
   *
   * @return A pointer to the created entity.
   */
  virtual IEntity* CreateEntity(JsonObject& entity) = 0;
};

#endif