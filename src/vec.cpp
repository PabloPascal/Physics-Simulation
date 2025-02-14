#include "../headers/vec.h"

vec2::vec2() {
	vector.x = 0;
	vector.y = 0;
}

vec2::vec2(float x, float y) {
	vector.x = x;
	vector.y = y;
}


vec2::vec2(sf::Vector2f v) {
	vector = v;
}


vec2 vec2::operator+(vec2 v) { return vec2(vector + v.vector); }
vec2 vec2::operator-(vec2 v) { return vec2(vector - v.vector); }
vec2 vec2::operator/(float scalar) { return vec2(vector.x / scalar, vector.y / scalar); }
vec2 vec2::operator*(float scalar) { return vec2(scalar * vector.x, scalar * vector.y); }
vec2 vec2::operator*(vec2 v) { return vec2(vector.x * v.getX(), vector.y * v.getY()); }

vec2& vec2::operator=(vec2 v) {
	vector = v.vector;
	return *this;
}


const sf::Vector2f vec2::get() const
{
	return vector;
}

float vec2::getX() const {
	return vector.x;
}

float vec2::getY() const{
	return vector.y;
}


float dotProd(vec2 v1, vec2 v2) {
	return v1.get().x * v2.get().x + v1.get().y * v2.get().y;
}


float length(const vec2& vector) { return sqrt(vector.get().x * vector.get().x + vector.get().y * vector.get().y); }