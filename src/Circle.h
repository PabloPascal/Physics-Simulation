#ifndef CIRCLE_H
#define	CIRCLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

const int ScreenWidth = 1240;
const int ScreenHeight = 720;


class Circle {

	friend void ObjCollision(Circle& circle1, Circle& circle2);
	friend void gravityCollision(Circle& circle, float dt);
	sf::Vector2f m_speed = { 0, 0 };
	sf::Vector2f m_Center;
	sf::CircleShape m_circle;
	float m_mass;
	float m_radius;

public:
	Circle(float x, float y, float radius, float mass);

	sf::CircleShape getSprite();

	void setVelocity(sf::Vector2f vel);

	void setPosition(float x, float y);

	void setPosition(sf::Vector2f pos);

	float getRadius();

	sf::Vector2f getSpeed();

	sf::Vector2f getCenter();
};


#endif // !CIRCLE_H
