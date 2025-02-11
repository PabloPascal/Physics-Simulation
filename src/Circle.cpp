#include "../headers/Circle.h"


Circle::Circle(vec2 start_pos, float radius, float mass, float elastic)
{
	m_position = start_pos;
	m_mass = mass;
	m_circle.setRadius(radius);
	m_circle.setOrigin(radius, radius);
	m_circle.setPosition(start_pos.get());
	m_circle.setFillColor(sf::Color::White);
	m_radius = radius;
	
	this->elastic = elastic;
}


//getters

void Circle::draw(sf::RenderTarget& target) {
	target.draw(m_circle);
}


vec2 Circle::getPosition() const
{
	return m_position;
}


float Circle::getRadius() const
{
	return m_radius;
}


vec2 Circle::getVelocity() const
{
	return m_speed;
}

sf::FloatRect Circle::getBounds() const {
	return m_circle.getGlobalBounds();
}


bool Circle::getGravityIndicate() const
{
	return isGravityActive;
}

bool Circle::getCollisionIndicate() const
{
	return isCollisionActive;
}

float Circle::getMass() {
	return m_mass;
}

//setters

void Circle::setVelocity(vec2 velocity) {
	m_speed = velocity;
}


void Circle::setPosition(vec2 coords) {
	m_position = coords;
	m_circle.setPosition(coords.get());
}


void Circle::setElastic(float elast) {
	elastic = elast;
}

//physics

void Circle::activateGravity(bool handler) {
	isGravityActive = handler;
}

void Circle::activateCollision(bool handler){
	isCollisionActive = handler;
}

#include <iostream>
void Circle::update(float dt)
{
	//std::cout << "Vy = " << m_speed.get().y << std::endl;
	m_circle.move(m_speed.get() * dt);
	m_position = m_circle.getPosition();
}


void Circle::setFillColor(sf::Color color) {
	m_circle.setFillColor(color);
}


float Circle::getElastic() {
	return elastic;
}