#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include <vector>
#include <memory>

#include "vec.h"
#include "Object.h"
#include "Circle.h"
#include "Rectangle.h"

//void ObjCollision(Circle& circle1, Circle& circle2);

const int ScreenWidth = 1240;
const int ScreenHeight = 720;


class Physics{
private:

	static Physics* instance_engine;

	sf::RenderWindow m_window;

	std::vector<std::unique_ptr<Circle>> circles;
	std::vector<std::unique_ptr<Rectangle>> rects;


//physics parametrs of this universe

	float m_gravity; 
	
	bool boundaryCollisionHandle = false;

private:

	Physics() = default;

	Physics(const Physics&) = delete;

public:

	static Physics* getInstance(float gravity);

	void run();

	void addCircle(Circle& c);
	void addRect(Rectangle& r);

	float getGravity();

	void setGravity(float g);

	void boundaryCollisionTurn(bool handler);

	void generateBalls(size_t count);

private:
	void render();

	void collision();

	void gravityUpdate(float dt);

	void gravity(Circle& c, float dt);
	
};


#endif // !PHYSICS_ENGINE_H
