#include "Circle.h"


Circle::Circle(float x, float y, float radius, float mass) {
	m_Center.x = x;
	m_Center.y = y;
	m_circle.setRadius(radius);
	m_circle.setOrigin(radius, radius);
	m_circle.setPosition(m_Center);
	m_circle.setFillColor(sf::Color::White);
	m_mass = mass;
	m_radius = radius;
}

sf::CircleShape Circle::getSprite() {
	return m_circle;
}

void Circle::setVelocity(sf::Vector2f vel) {
	m_speed = vel;
}


void Circle::setPosition(float x, float y) {
	m_circle.setPosition({ x, y });
}


void Circle::setPosition(sf::Vector2f pos) {
	m_Center = pos;
	m_circle.setPosition(pos);
}


sf::Vector2f Circle::getCenter() { 
	return m_Center; 
}


float Circle::getRadius() {
	return m_radius;
}


sf::Vector2f Circle::getSpeed() {
	return m_speed;
}
