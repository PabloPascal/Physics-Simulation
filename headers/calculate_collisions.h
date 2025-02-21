#ifndef CALC_COLLISION_H
#define CALC_COLLISION_H

#include "PhysicsEngine.h"

/*
	function that calculates velocity after collision between two balls (circles)
*/
void hitBalls(Circle& circle1, Circle& circle2);

/*
	function that push out circles from each other
	(to circles dont stuck inside each other)
*/

void separateBalls(Circle& c1, Circle& c2);

/*
	function that push out cirle from walls (to circle dont stuck)
*/

void separateWalls(Circle& c1, vec2 normal, float diff);


/*
	function calculates hit between ball and rectangle after collision
*/

void CircleHitRect(Circle& c, Rectangle& rect);

/*
	function calculates hit between ball and rectangle after collision new method
*/

//void CircleHitRect2(Circle& c, Rectangle& rect);


/*
	function checks collisions between two balls
*/
bool checkBallsCollision(const Circle& c1, const Circle& c2);

/*
	function checks collision between balls and rectangle
*/
bool checkRectBallCollision(Circle& c, Rectangle& rect, vec2& normal);

/*
	function checks collision between Rectangles
*/
bool checkRectCollision(Rectangle& rect1, Rectangle& rect2);

/*
	function checks and calculate collisions with bound of screen
*/
void boundaryCollision(Circle& c);


#endif //CALC_COLLISION_H


