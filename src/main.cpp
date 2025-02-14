/*
программа моделирует столкновения шаров в вакууме, имитация свободного падения и удары об стенки
используется закон сохранения энергии и импульса 
E1 + E2 = E1' + E2'
p1 + p2 = p1' + p2'
p = m*v
E = m*v^2 / 2
*/


#include <iostream>


#include "../headers/PhysicsEngine.h"




int main() {

	Physics* engine = Physics::getInstance(1000);

	
	Circle c1({ 650,100 }, 50, 250);
	Circle c2({ 100,200 }, 30, 30);


	c1.setFillColor(sf::Color(250, 0, 0));
	c2.setFillColor(sf::Color::Blue);

	c1.setElastic(0.9);
	c2.setElastic(0.9);

	c1.setVelocity({ -150, 40 });
	c2.setVelocity({ 150, 10 });

	c1.activateCollision(true);
	c2.activateCollision(true);

	c1.activateGravity(true);
	c2.activateGravity(true);

	engine->addCircle(c1);
	engine->addCircle(c2);
	

	Rectangle r1({ 500, 600 }, { 100, 500 }, 200);
	Rectangle r2({ 300, 400 }, { 100, 200 }, 200);
	Rectangle r3({ 1000, 500 }, { 100, 100 }, 200);
	r1.setFillColor(sf::Color(128, 128, 128));
	r1.activateCollision(true);
	r2.setFillColor(sf::Color(128, 128, 128));
	r2.activateCollision(true);
	r3.setFillColor(sf::Color(128, 128, 128));
	r3.activateCollision(true);
	
	engine->addRect(r1);
	//engine->addRect(r2);
	//engine->addRect(r3);


	//engine->generateBalls(100);
	
	engine->boundaryCollisionOn(true);
	engine->run();

}


