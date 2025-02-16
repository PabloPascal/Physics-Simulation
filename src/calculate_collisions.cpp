#include "../headers/calculate_collisions.h"


bool checkRectCollision(Rectangle& rect1, Rectangle& rect2) {

	return rect1.getBounds().intersects(rect2.getBounds());

}



void CircleHitRect(Circle& c, Rectangle& rect)
{

	float r = c.getRadius();
	float h = rect.getSize().getY();
	float w = rect.getSize().getX();


	if (checkRectBallCollision(c, rect))
	{
		if (c.getPosition().getX() > rect.getPosition().getX() - w / 2
			&& c.getPosition().getX() < rect.getPosition().getX() + w / 2)
		{
			if (rect.getPosition().getY() > c.getPosition().getY()) {

				vec2 normal = { 0, -1 };

				c.setVelocity({ c.getVelocity().getX(), -c.getVelocity().getY() });

				float diff = abs(abs(c.getPosition().getY() - rect.getPosition().getY()) - h / 2);

				separateWalls(c, normal, diff);
			}
			else {
				vec2 normal = { 0, 1 };

				c.setVelocity({ c.getVelocity().getX(), -c.getVelocity().getY() });

				float diff = abs(abs(c.getPosition().getY() - rect.getPosition().getY()) - h / 2);

				separateWalls(c, normal, diff);
			}


		}//if x_c in diaposon (x_r - w/2, x_r + w/2)

		else if (c.getPosition().getY() > rect.getPosition().getY() - h / 2
			&& c.getPosition().getY() < rect.getPosition().getY() + h / 2)
		{
			if (rect.getPosition().getX() > c.getPosition().getX()) {

				vec2 normal = { -1, 0 };

				c.setVelocity({ -c.getVelocity().getX(), c.getVelocity().getY() });

				float diff = abs(abs(c.getPosition().getX() - rect.getPosition().getX()) - w / 2);

				separateWalls(c, normal, 0.1 * diff);
			}
			else {
				vec2 normal = { 1, 0 };

				c.setVelocity({ -c.getVelocity().getX(), c.getVelocity().getY() });

				float diff = abs(abs(c.getPosition().getX() - rect.getPosition().getX()) - w / 2);

				separateWalls(c, normal, 0.1 * diff);
			}


		}//if y_c in diaposon (y_r - h/2, y_r + h/2)

		else {
			//left top
			if (c.getPosition().getX() < rect.getPosition().getX() &&
				c.getPosition().getY() < rect.getPosition().getY())
			{
				vec2 P = { rect.getPosition().getX() - w / 2, rect.getPosition().getY() - h / 2 };
				vec2 normal = c.getPosition() - P;
				normal = normal / length(normal);

				c.setVelocity(c.getVelocity() * c.getElastic() * (-1));
				float diff = abs(length(c.getPosition() - P) - r);

				separateWalls(c, normal, diff);

			}
			//right top
			else if (c.getPosition().getX() > rect.getPosition().getX() &&
				c.getPosition().getY() < rect.getPosition().getY())
			{
				vec2 P = { rect.getPosition().getX() + w / 2, rect.getPosition().getY() - h / 2 };
				vec2 normal = c.getPosition() - P;
				normal = normal / length(normal);

				c.setVelocity(c.getVelocity() * c.getElastic() * (-1));
				float diff = abs(length(c.getPosition() - P) - r);

				separateWalls(c, normal, diff);

			}
			//left bottom
			else if (c.getPosition().getX() < rect.getPosition().getX() &&
				c.getPosition().getY() > rect.getPosition().getY())
			{
				vec2 P = { rect.getPosition().getX() - w / 2, rect.getPosition().getY() + h / 2 };
				vec2 normal = c.getPosition() - P;
				normal = normal / length(normal);

				c.setVelocity(c.getVelocity() * c.getElastic() * (-1));
				float diff = abs(length(c.getPosition() - P) - r);

				separateWalls(c, normal, diff);

			}
			//right bottom
			else if (c.getPosition().getX() > rect.getPosition().getX() &&
				c.getPosition().getY() > rect.getPosition().getY())
			{
				vec2 P = { rect.getPosition().getX() + w / 2, rect.getPosition().getY() + h / 2 };
				vec2 normal = c.getPosition() - P;
				normal = normal / length(normal);

				c.setVelocity(c.getVelocity() * c.getElastic() * (-1));
				float diff = abs(length(c.getPosition() - P) - r);

				separateWalls(c, normal, diff);

			}

		}

	}//check ball collision with rect

}




bool checkRectBallCollision(Circle& c, Rectangle& rect)
{
	float r = c.getRadius();
	float h = rect.getSize().getY();
	float w = rect.getSize().getX();

	if (abs(c.getPosition().getY() - rect.getPosition().getY()) < r + h / 2
		&& c.getPosition().getX() > rect.getPosition().getX() - w / 2 &&
		c.getPosition().getX() < rect.getPosition().getX() + w / 2)
	{
		return true;
	}
	else if (abs(c.getPosition().getX() - rect.getPosition().getX()) < r + w / 2
		&& c.getPosition().getY() > rect.getPosition().getY() - h / 2 &&
		c.getPosition().getY() < rect.getPosition().getY() + h / 2)
	{
		return true;
	}
	else {
		vec2 leftTop = { rect.getPosition().getX() - w / 2, rect.getPosition().getY() - h / 2 };
		vec2 rightTop = { rect.getPosition().getX() + w / 2, rect.getPosition().getY() - h / 2 };
		vec2 leftBottom = { rect.getPosition().getX() - w / 2, rect.getPosition().getY() + h / 2 };
		vec2 rightBottom = { rect.getPosition().getX() + w / 2, rect.getPosition().getY() + h / 2 };

		float len1 = length(c.getPosition() - leftTop);
		float len2 = length(c.getPosition() - rightTop);
		float len3 = length(c.getPosition() - leftBottom);
		float len4 = length(c.getPosition() - rightBottom);

		float min_dist = std::min({ len1, len2, len3, len4 });

		if (min_dist < r) {
			return true;
		}

	}



	return false;
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




void crashBalls(Circle& circle1, Circle& circle2) {
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
