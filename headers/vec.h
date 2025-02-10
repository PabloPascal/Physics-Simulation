#ifndef VEC_H
#define VEC_H

#include <SFML/Graphics.hpp>



class vec2 {
	sf::Vector2f vector;
public:
	vec2();

	vec2(float x, float y);

	vec2(sf::Vector2f v);

	vec2 operator+(vec2 v);
	vec2 operator-(vec2 v);
	vec2 operator/(float scalar);
	vec2 operator*(float scalar);

	vec2& operator=(vec2 v);

	const sf::Vector2f get() const;

};


float dotProd(vec2 v1, vec2 v2);

float length(const vec2& vector);




#endif // VEC_H

