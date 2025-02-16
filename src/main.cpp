/*
	programm's simulating physics
	
	1) balls collision
	2) free fall (gravity)
	3) rectangle and balls-rect collision
	
*/


#include <iostream>


#include "../headers/PhysicsEngine.h"




int main() {

	Physics* engine = Physics::getInstance(1000);

	
	Circle c1({ 650,100 }, 5, 50);
	Circle c2({ 100,200 }, 4, 30);
	Circle c3({ 1050, 500 }, 6, 200);

	c1.setFillColor(sf::Color(250, 0, 0));
	c2.setFillColor(sf::Color::Blue);
	c3.setFillColor(sf::Color::Yellow);

	c1.setElastic(0.1);
	c2.setElastic(0.1);
	c3.setElastic(0.1);

	c1.setVelocity({ -15, 40 });
	c2.setVelocity({ 15, 10 });
	c3.setVelocity({ 20, 5 });

	c1.activateCollision(true);
	c2.activateCollision(true);
	c3.activateCollision(true);

	//c1.activateGravity(true);
	//c2.activateGravity(true);

	c1.activateGravityForce(true);
	c2.activateGravityForce(true);
	c3.activateGravityForce(true);

	engine->addCircle(c1);
	engine->addCircle(c2);
	engine->addCircle(c3);
	

	//Rectangle r1({ 500, 600 }, { 100, 500 }, 200);
	//Rectangle r2({ 300, 400 }, { 100, 200 }, 200);
	//Rectangle r3({ 1000, 500 }, { 100, 100 }, 200);
	//r1.setFillColor(sf::Color(128, 128, 128));
	//r1.activateCollision(true);
	//r2.setFillColor(sf::Color(128, 128, 128));
	//r2.activateCollision(true);
	//r3.setFillColor(sf::Color(128, 128, 128));
	//r3.activateCollision(true);
	
	//engine->addRect(r1);
	//engine->addRect(r2);
	//engine->addRect(r3);

	//engine->generateBalls(100);
	
	//engine->boundaryCollisionTurn(true);
	engine->run();

}


