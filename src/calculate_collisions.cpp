#include "../headers/calculate_collisions.h"

#include <iostream>


bool checkRectCollision(Rectangle& rect1, Rectangle& rect2) {

	return rect1.getBounds().intersects(rect2.getBounds());

}



void separateWalls(Circle& c1, vec2 normal, float diff) {

	//diff *= 0.5;

	vec2 delta = c1.getPosition() + normal * diff;

	c1.setPosition(delta);

}


void separateBalls(Circle& c1, Circle& c2) {

	float angle = atan2f(c1.getPosition().get().y - c2.getPosition().get().y,
		c1.getPosition().get().x - c2.getPosition().get().x);

	float r1 = c1.getRadius();
	float r2 = c2.getRadius();

	float diffDist = r1 + r2 - length(c1.getPosition() - c2.getPosition());

	//diffDist *= 1.01 / (pow(r1,2) + pow(r2,2));
	diffDist *= 0.5;

	vec2 dir = { cos(angle), sin(angle) };
	vec2 delta1 = c1.getPosition() + dir * diffDist;
	vec2 delta2 = c2.getPosition() + dir * diffDist * (-1);

	c1.setPosition(delta1);
	c2.setPosition(delta2);


}




void hitBalls(Circle& circle1, Circle& circle2) {
	vec2 x1 = circle1.getPosition();
	vec2 x2 = circle2.getPosition();

	vec2 v1 = circle1.getVelocity();
	vec2 v2 = circle2.getVelocity();

	float m1 = circle1.getMass();
	float m2 = circle2.getMass();

	vec2 v1_new = v1 - (x1 - x2) * (2 * m2 / (m1 + m2) * dotProd(v1 - v2, x1 - x2) / (length(x1 - x2) * length(x1 - x2)));
	vec2 v2_new = v2 - (x2 - x1) * (2 * m1 / (m1 + m2) * dotProd(v2 - v1, x2 - x1) / (length(x2 - x1) * length(x2 - x1)));

	circle1.setVelocity(circle1.getElastic() * v1_new.get());
	circle2.setVelocity(circle2.getElastic() * v2_new.get());
}




bool checkBallsCollision(const Circle& c1, const Circle& c2)
{
	float r1 = c1.getRadius();
	float r2 = c2.getRadius();


	if (length(c1.getPosition() - c2.getPosition()) < r1 + r2) {
		return true;
	}

	return false;
}



void boundaryCollision(Circle& c) {

	float r = c.getRadius();

	if (c.getPosition().get().x + r > ScreenWidth) {
		float diff = c.getPosition().get().x + r - ScreenWidth;

		separateWalls(c, { -1, 0 }, diff);
		c.setVelocity({ -c.getVelocity().get().x, c.getVelocity().get().y });
	}

	if (c.getPosition().get().x - r < 0) {
		float diff = -(c.getPosition().get().x - r);

		separateWalls(c, { 1, 0 }, diff);
		c.setVelocity({ -c.getVelocity().get().x, c.getVelocity().get().y });
	}

	if (c.getPosition().get().y + r > ScreenHeight) {
		float diff = c.getPosition().get().y + r - ScreenHeight;

		separateWalls(c, { 0, -1 }, diff);
		c.setVelocity({ c.getVelocity().get().x, -c.getVelocity().get().y * c.getElastic() });

	}
	if (c.getPosition().get().y - r < 0) {
		float diff = -(c.getPosition().get().y - r);

		separateWalls(c, { 0, 1 }, diff);
		c.setVelocity({ c.getVelocity().get().x, -c.getVelocity().get().y });

	}


}


bool checkRectBallCollision(Circle& c, Rectangle& rect, vec2& normal) {
	
	vec2 e1 = rect.getLocalCoordsX();
	vec2 e2 = rect.getLocalCoordsY();

	float w = rect.getSize().getX();
	float h = rect.getSize().getY();
	float r = c.getRadius();

	float pr_x = dotProd(c.getPosition(), e1);
	float pr_y = dotProd(c.getPosition(), e2);
	
	float pr_Rx = dotProd(rect.getPosition(), e1);
	float pr_Ry = dotProd(rect.getPosition(), e2);


	if (abs(pr_Rx - pr_x) < w/2 + r && abs(pr_Ry - pr_y) < h/2 + r) {
		
		vec2 A = rect.getPosition() + e1 * (w / 2) + e2 * (h / 2);
		vec2 B = rect.getPosition() + e1 * (w / 2) + e2 * (-h / 2);
		vec2 C = rect.getPosition() + e1 * (-w / 2) + e2 * (-h / 2);
		vec2 D = rect.getPosition() + e1 * (-w / 2) + e2 * (h / 2);


		float prAx = dotProd(A, e1);
		float prDx = dotProd(D, e1);
		float prCy = dotProd(C, e2);
		float prDy = dotProd(D, e2);

		if (prDx < pr_x && prAx > pr_x) {
			if (pr_y < prDy) {
				normal = e2 * (-1);
			}

			if (pr_y > prCy) {
				normal = e2;
			}
		
		}
		if (pr_y < prDy && pr_y > prCy) {

			if (pr_x < prDx) {
				normal = e1 * (-1);
			}

			if (pr_x > prAx) {
				normal = e1;
			}
		}
		
		return true;
	}

	return false;
}


void CircleHitRect(Circle& c, Rectangle& rect)
{
	vec2 normal;
	float diff;

	if (checkRectBallCollision(c, rect, normal)) {
		vec2 newV;

		if (length(normal)) {
			vec2 v = c.getVelocity();
			newV = v + normal * 2 * dotProd(v * (-1), normal);
		}

		else {
			newV = c.getVelocity()*(-1);
		}

		c.setVelocity(newV);
	}

	

}