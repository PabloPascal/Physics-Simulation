#include "PhysicsEngine.h"



bool detectCollision(Circle& circle1, Circle& circle2) {
	float r1 = circle1.getSprite().getRadius();
	float r2 = circle2.getSprite().getRadius();

	vec vec_centr = circle1.getCenter() - circle2.getCenter();
	float length_centr = length(vec_centr);


	if (length_centr <= r1 + r2) {
		return true;
	}
	else {
		return false;
	}

}


void ObjCollision(Circle& circle1, Circle& circle2) {

	if (detectCollision(circle1, circle2)) {

		vec x1 = circle1.getCenter();
		vec x2 = circle2.getCenter();

		vec v1 = circle1.m_speed;
		vec v2 = circle2.m_speed;

		float m1 = circle1.m_mass;
		float m2 = circle2.m_mass;

		vec v1_new = v1 - (x1 - x2) * (2 * m2 / (m1 + m2) * dotProd(v1 - v2, x1 - x2) / (length(x1 - x2) * length(x1 - x2)));
		vec v2_new = v2 - (x2 - x1) * (2 * m1 / (m1 + m2) * dotProd(v2 - v1, x2 - x1) / (length(x2 - x1) * length(x2 - x1)));
		
		circle1.setVelocity(v1_new.get());
		circle2.setVelocity(v2_new.get());


	}
}


void gravityCollision(Circle& circle, float dt) {
	float gravity = 1000;
	float y = circle.getCenter().y;
	float x = circle.getCenter().x;
	float vy = circle.m_speed.y;
	vy += gravity * dt;
	circle.setVelocity({ circle.m_speed.x, vy });

	if (y >= ScreenHeight) {
		vy *= -0.9;
		circle.setVelocity({ circle.m_speed.x, vy });
		std::cout << vy << std::endl;
	}

	y += vy * dt;
	x += circle.m_speed.x * dt;

	circle.setPosition({ x, y });
}


void collisionWalls(Circle& circle) {

	float r = circle.getRadius();
	if (circle.getCenter().x + r > ScreenWidth || circle.getCenter().x - r < 0) {
		circle.setVelocity({ -circle.getSpeed().x, circle.getSpeed().y });
	}

	if (circle.getCenter().y + r > ScreenHeight || circle.getCenter().y - r < 0) {
		circle.setVelocity({ circle.getSpeed().x, -circle.getSpeed().y });
	}

}



void move(Circle& circle,float dt) {

	float x = circle.getCenter().x;
	float y = circle.getCenter().y;

	x += circle.getSpeed().x * dt;
	y += circle.getSpeed().y * dt;

	circle.setPosition({x,y});
}