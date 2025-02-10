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
	
	Circle c1({ 100,100 }, 50, 150);
	Circle c2({ 300,200 }, 30, 150);

	c1.setVelocity({ 100, 40 });
	c2.setVelocity({ -100, 10 });

	c1.activateCollision(true);
	c2.activateCollision(true);

	//c1.activateGravity(true);

	engine->addCircle(c1);
	engine->addCircle(c2);

	engine->run();

}


