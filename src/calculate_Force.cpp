#include "../headers/calculate_Force.h"


void calcGravityForce(Circle& c1, Circle& c2) {

	constexpr float Gravity = 1000;
	
	float m1 = c1.getMass();
	float m2 = c2.getMass();

	float d = length(c1.getPosition() - c2.getPosition());

	vec2 dir_12 = c1.getPosition() - c2.getPosition();

	vec2 F12 = dir_12 * (Gravity * m1 * m2 / (d * d)) / length(dir_12);
	
	vec2 u1_prev = c1.getVelocity();
	vec2 u2_prev = c2.getVelocity();

	vec2 u1_next = (F12 * (-1.f / 100.f) + u1_prev * m1) / m1;
	vec2 u2_next = (F12 * (1.f / 100.f) + u2_prev * m2) / m2;

	c1.setVelocity(u1_next);
	c2.setVelocity(u2_next);

}
