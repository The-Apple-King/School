#ifndef RESTAURANT_H_
#define RESTAURANT_H_

#include "IEntity.h"
#include "math/vector3.h"
//
// Rough Start for what restaurant class will have.
//
class Restaurant : public IEntity {
 public:

  Restaurant(JsonObject& obj);

  ~Restaurant();

  JsonObject GetDetails() const { return details; }

  Vector3 GetPosition() const { return position; }

  void SetPosition(Vector3 pos_) { position = pos_; }

 private:
  JsonObject details;
  Vector3 position;
  bool available;

} ;

#endif