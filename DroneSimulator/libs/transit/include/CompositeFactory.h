#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

#include "IEntityFactory.h"

class CompositeFactory : public IEntityFactory {
 public:
  /**
   * @brief Creates an entity.
   *
   * @param entity The JSON object of entity to create.
   *
   * @return A pointer to the created entity
   */
  IEntity* CreateEntity(JsonObject& entity);
  /**
   * @brief Adds an entity factory to the composite factory.
   *
   * @param factoryEntity The entity factory to add to the composite factory.
   */
  void AddFactory(IEntityFactory* factoryEntity);
  /**
   * @brief destuctor for instance of CompositeFactory.
   */
  virtual ~CompositeFactory();

 private:
  std::vector<IEntityFactory*> componentFactories;
};

#endif