#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include "vec.h"
#include "Circle.h"


bool detectCollision(Circle& circle1, Circle& circle2);

void ObjCollision(Circle& circle1, Circle& circle2);

void gravityCollision(Circle& circle, float dt);

void collisionWalls(Circle& circle);

void move(Circle& circle, float dt);


#endif // !PHYSICS_ENGINE_H
