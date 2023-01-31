#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View
/// Controller Pattern
class IController {
 public:
  /**
   * @brief destructor for IController.
   */
  virtual ~IController() {}
  /**
   * @brief Adds an entity to the program.
   *
   * @param entity The entity to add.
   */
  virtual void AddEntity(const IEntity& entity) = 0;
  /**
   * @brief Updates an entity in the program.
   *
   * @param entity The updated entity.
   */
  virtual void UpdateEntity(const IEntity& entity) = 0;
  /**
   * @brief Removes an entity from the program.
   *
   * @param id The ID of the entity to remove.
   */
  virtual void RemoveEntity(int id) = 0;
  /**
   * @brief Adds a path to the program.
   *
   * @param id The ID of the entity to add the path to.
   * @param path The path to add.
   */
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;
  /**
   * @brief Removes a path from the program.
   *
   * @param id The ID of the entity to remove the path from.
   */
  virtual void RemovePath(int id) = 0;
  /**
   * @brief Allows messages to be passed back to the view.
   *
   * @param event The name objectof the event.
   * @param details The details object of the event.
   */
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif
