#include "vec.h"



vec::vec(float x, float y) {
	vector.x = x;
	vector.y = y;
}


vec::vec(sf::Vector2f v) {
	vector = v;
}


vec vec::operator+(vec v) { return vec(vector + v.vector); }
vec vec::operator-(vec v) { return vec(vector - v.vector); }
vec vec::operator/(float scalar) { return vec(vector.x / scalar, vector.y / scalar); }
vec vec::operator*(float scalar) { return vec(scalar * vector.x, scalar * vector.y); }


vec& vec::operator=(vec v) {
	vector = v.vector;
	return *this;
}


const sf::Vector2f vec::get() const
{
	return vector;
}



float dotProd(vec v1, vec v2) {
	return v1.get().x * v2.get().x + v1.get().y * v2.get().y;
}


float length(const vec& vector) { return sqrt(vector.get().x * vector.get().x + vector.get().y * vector.get().y); }