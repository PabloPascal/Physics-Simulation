#include "../headers/Rectangle.h"


Rectangle::Rectangle(vec2 start_pos, vec2 size, float mass)
{
	m_position = start_pos;
	m_size = size;
	m_mass = mass;

	m_rect.setPosition(m_position.get());
	m_rect.setSize(m_size.get());
	m_rect.setOrigin((m_size * 0.5).get());
	
}


void Rectangle::draw(sf::RenderTarget& target) {
	target.draw(m_rect);
}


/*
				GETTERS
*/


vec2 Rectangle::getPosition() const{
	return m_position;
}

vec2 Rectangle::getVelocity() const {
	return m_velosity;
}

sf::FloatRect Rectangle::getBounds() const {
	return m_rect.getGlobalBounds();
}

bool Rectangle::getGravityIndicate() const {
	return m_gravityHandle;
}

bool Rectangle::getCollisionIndicate() const {
	return m_collisionHandle;
}

vec2 Rectangle::getSize() const {
	return m_size;
}

/*
				SETTERS
*/



void Rectangle::setVelocity(vec2 velocity) {
	m_velosity = velocity;
}

void Rectangle::setPosition(vec2 coords) {
	m_position = coords;
	m_rect.setPosition(coords.get());
}

void Rectangle::setFillColor(sf::Color color) {
	m_rect.setFillColor(color);
}


/*
			PHYSICS
*/



void Rectangle::activateGravity(bool handler) {
	m_gravityHandle = handler;
}

void Rectangle::activateCollision(bool handler){
	m_collisionHandle = handler;
}


void Rectangle::update(float dt) {
	m_rect.move(m_velosity.get() * dt);
}
