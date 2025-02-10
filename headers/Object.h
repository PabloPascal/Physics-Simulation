#ifndef OBJECT_H
#define OBJECT_H


#include <SFML/Graphics.hpp>

#include "../headers/vec.h"


class Object {

public:
//getters

	virtual vec2 getPosition() const = 0;

	virtual vec2 getVelocity() const = 0;

	virtual sf::FloatRect getBounds() const = 0;

	virtual bool getGravityIndicate() const = 0;
	virtual bool getCollisionIndicate() const = 0;

//setters

	virtual void setVelocity(vec2) = 0;

	virtual void setPosition(vec2 coords) = 0;

//physics

	virtual void activateGravity(bool handler) = 0;

	virtual void activateCollision(bool handler) = 0;

	virtual void update(float dt) = 0;
};

#endif //OBJECT_H