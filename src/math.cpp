#include "../headers/math.h"

#include <iostream>
#include <cmath>

namespace Math {

	float PI = 3.1415;


	Matrix2D Rotate(float angle) {
		return Matrix2D(
			std::cos(angle), -std::sin(angle),
			std::sin(angle), std::cos(angle)
		);
	}


	bool check_intersect_sections(line& section1, line& section2){

		float ax = section1.point1.getX();
		float ay = section1.point1.getY();
		float bx = section1.point2.getX();
		float by = section1.point2.getY();

		float cx = section2.point1.getX();
		float cy = section2.point1.getY();
		float dx = section2.point2.getX();
		float dy = section2.point2.getY();


		float labmda1 = (by - ay) / (bx - ax);
		float labmda2 = (dy - cy) / (dx - cx);

		float x = (ax * labmda1 - cx * labmda2 + cy - ay) / (labmda1 - labmda2);

		float t1 = (x - ax) / (bx - ax);
		float t2 = (x - cx) / (dx - cx);
	

		if (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1) {
			return true;
		}
		else
			return false;
	}

	float distanceFromPointToLine(vec2& Point, line& l) {
		
		
		float d = length(Point - nearestPoint(Point, l));

		return d;
	}

	float distanceFromPointToLine(vec2&& Point, line& l) {
		
		
		float d = length(Point - nearestPoint(Point, l));

		return d;
	}



	vec2 nearestPoint(vec2& Point, line& l) {
		float ax = l.point1.getX();
		float ay = l.point1.getY();
		float bx = l.point2.getX();
		float by = l.point2.getY();

		vec2 u = { bx - ax, by - ay };

		float lambda = u.getX() / u.getY();

		float x = (lambda * ax + lambda * Point.getX() + Point.getY() - ay) / (2 * lambda);
		float y = lambda * x - lambda * ax + ay;

		return vec2(x, y);
	}

	vec2 nearestPoint(vec2&& Point, line& l) {
		float ax = l.point1.getX();
		float ay = l.point1.getY();
		float bx = l.point2.getX();
		float by = l.point2.getY();

		vec2 u = { bx - ax, by - ay };

		float lambda = u.getX() / u.getY();

		float x = (lambda * ax + lambda * Point.getX() + Point.getY() - ay) / (2 * lambda);
		float y = lambda * x - lambda * ax + ay;

		return vec2(x, y);
	}

}