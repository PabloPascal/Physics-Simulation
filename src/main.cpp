/*
	programm's simulating physics
	
	1) balls collision
	2) free fall (gravity)
	3) rectangle and balls-rect collision
	
*/


#include <iostream>
#include "../headers/calculate_collisions.h"

#include "../headers/PhysicsEngine.h"


void control(Circle& c, float t);

int main() {
	
	
	Physics* engine = Physics::getInstance(1000);

	Circle c1({ 100,100 }, 40, 50, 0.9);
	Circle c2({ 200,200 }, 20, 10, 0.9);
	Circle c3({ 500,300 }, 30, 40, 0.9);
	
	engine->boundaryCollisionTurn(true);
	
	c1.setVelocity({ 100, 40 });
	c2.setVelocity({ 200,300 });
	c3.setVelocity({ 150,0 });

	c1.activateCollision(true);
	c2.activateCollision(true);
	c3.activateCollision(true);

	//engine->generateBalls(10);
	Rectangle r1({ 700,300 }, { 200,200 }, 100);
	Rectangle r2({ 200,300 }, { 200,100 }, 100);
	r1.rotate(3.1415 / 3);

	r1.activateCollision(true);
	r2.activateCollision(true);
	
	engine->addRect(r1);
	engine->addRect(r2);

	engine->addCircle(c1);
	engine->addCircle(c2);
	engine->addCircle(c3);

	engine->run();
	

	/*
	Rectangle r1({ 700,300 }, { 200,200 }, 100);
	//r1.rotate(3.1415 / 3);

	Circle c({ 200, 200 }, 20, 200);
	c.setVelocity({ 150, 150 });


	sf::RenderWindow window(sf::VideoMode(1080, 720), "test");

	std::cout << r1.getLocalCoordsX().getX() << ", ";
	std::cout << r1.getLocalCoordsX().getY() << std::endl;

	sf::Clock clock;
	float t = 0;

	vec2 n;

	while (window.isOpen()) {

		sf::Time time = clock.restart();
		float dt = time.asSeconds();
		t += dt;

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}


		}
		//r1.rotate(3.1415 / 3 * t);

		control(c, dt);
		
		if (checkRectBallCollision2(c, r1, n)) {
			std::cout << "n_x = " << n.getX() << ", n_y = " << n.getY() << std::endl;
		}
		



		window.clear();
		c.draw(window);
		r1.draw(window);
		window.display();
	}
	*/
	
}


void control(Circle& c, float t) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		c.setPosition(c.getPosition() + vec2(0, -c.getVelocity().getY()* t));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		c.setPosition(c.getPosition() + vec2(0, c.getVelocity().getY() * t));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		c.setPosition(c.getPosition() + vec2(-c.getVelocity().getX() * t, 0));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		c.setPosition(c.getPosition() + vec2(c.getVelocity().getX() * t, 0));
	}


}

