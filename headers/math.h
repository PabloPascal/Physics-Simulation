#ifndef MATH_H
#define MATH_H


#include "matrix.h"
#include "vec.h"

namespace Math {

	extern float PI;

	Matrix2D Rotate(float angle);

	
	struct line {
		vec2 point1;
		vec2 point2;
	};

	/*
		 function that tell us intersect section1 with section2
	*/

	bool check_intersect_sections(line& section1, line& section2);

	/*
		calculate distance from point to the line
	*/

	float distanceFromPointToLine(vec2& Point, line& l);
	float distanceFromPointToLine(vec2&& Point, line& l);

	/*
		find neares point on the line
	*/
	vec2 nearestPoint(vec2& Point, line& l);
	vec2 nearestPoint(vec2&& Point, line& l);

}


#endif // !MATH_H
