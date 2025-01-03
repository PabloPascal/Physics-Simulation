/*
программа моделирует столкновения шаров в вакууме, имитация свободного падения и удары об стенки
используется закон сохранения энергии и импульса 
E1 + E2 = E1' + E2'
p1 + p2 = p1' + p2'
p = m*v
E = m*v^2 / 2
*/


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Circle.h"
#include "vec.h"
#include "PhysicsEngine.h"



void generate(std::vector<Circle>& list, int count) {
	srand(time(0));

	for (int i = 0; i < count; i++) {

		float x = rand() % (ScreenWidth - 10) + 10;
		float y = rand() % (ScreenHeight - 10) + 10;
		float radius = rand() % 5;
		float mass = rand() % 100 / 100.f;

		float vx = (rand() % 500);
		float vy = (rand() % 500);

		Circle c(x, y, radius, mass);
		c.setVelocity({ vx, vy });
		list.push_back(c);
	}

}


void object_list_collision(std::vector<Circle>& obj_list, float dt) {

	for (int i = 0; i < obj_list.size() - 1; i++) {
		move(obj_list[i],dt);
		collisionWalls(obj_list[i]);
		move(obj_list[i + 1], dt);
		collisionWalls(obj_list[i + 1]);
		for (int j = i + 1; j < obj_list.size(); j++) {
			ObjCollision(obj_list[i], obj_list[j]);
		}
	}
}


int main() {

	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Game");

	Circle c1(200, 200, 10, 10);
	Circle c2(300, 100, 10, 10);
	c1.setVelocity({ 100 ,100.f });
	c2.setVelocity({ 90, 120 });
	//std::vector<Circle> obj_list;

	//generate(obj_list, 200);

	sf::Clock clock;
	while (window.isOpen()) {

		sf::Time time = clock.restart();

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}

		/*
		for (int i = 0; i < obj_list.size()-1; i++) {
			obj_list[i].run(time.asSeconds());
			obj_list[i].collisionWalls();
			obj_list[i+1].run(time.asSeconds());
			obj_list[i+1].collisionWalls();
			for (int j = i + 1; j < obj_list.size(); j++) {
				ObjCollision(obj_list[i], obj_list[j]);
			}
		}
		*/
		gravityCollision(c1, time.asSeconds());
		collisionWalls(c1);

		gravityCollision(c2, time.asSeconds());
		collisionWalls(c2);

		ObjCollision(c1, c2);

		window.clear();

		/*
		for (int i = 0; i < obj_list.size(); i++) {
			window.draw(obj_list[i].getSprite());
		}
		*/

		window.draw(c1.getSprite());
		window.draw(c2.getSprite());
		window.display();

	}

}