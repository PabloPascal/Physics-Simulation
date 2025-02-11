#ifndef CIRCLE_H
#define	CIRCLE_H

#include "../headers/Object.h"



class Circle: public Object
{

	sf::CircleShape m_circle;

//physical parameters
	float m_radius;
	vec2 m_position;
	vec2 m_speed = { 0, 0 };
	float m_mass;
	float elastic;

	bool isGravityActive = false; 
	bool isCollisionActive = false;

public:
	
	Circle(vec2 start_pos, float radius, float mass, float elastic = 0);

//getters
	void draw(sf::RenderTarget& target);

	vec2 getVelocity() const override;

	vec2 getPosition() const override;

	float getRadius() const;

	sf::FloatRect getBounds() const override;

	bool getGravityIndicate() const override;
	bool getCollisionIndicate() const override;

	float getMass();
	float getElastic();
//setters

	void setVelocity(vec2) override;

	void setPosition(vec2 coords) override;

	void setElastic(float elastic_coefficient);

	void setFillColor(sf::Color color) override;

//physics

	void activateGravity(bool handler) override;

	void activateCollision(bool handler) override;

	void update(float dt) override;

};


#endif // !CIRCLE_H
