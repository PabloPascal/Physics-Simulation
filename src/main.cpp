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
	
	Circle c1({ 100,100 }, 50, 250);
	Circle c2({ 200,200 }, 30, 30);

	c1.setFillColor(sf::Color(128,128,128));
	c2.setFillColor(sf::Color::Blue);

	c1.setVelocity({ 100, 40 });
	c2.setVelocity({ -100, 10 });

	c1.activateCollision(true);
	c2.activateCollision(true);

	c1.activateGravity(true);
	c2.activateGravity(true);

	engine->addCircle(c1);
	engine->addCircle(c2);

	engine->boundaryCollisionOn(true);

	engine->run();

}


