#ifndef VEC_H
#define VEC_H

#include <SFML/Graphics.hpp>



class vec {
	sf::Vector2f vector;
public:
	vec(float x, float y);

	vec(sf::Vector2f v);

	vec operator+(vec v);
	vec operator-(vec v);
	vec operator/(float scalar);
	vec operator*(float scalar);

	vec& operator=(vec v);

	const sf::Vector2f get() const;

};


float dotProd(vec v1, vec v2);

float length(const vec& vector);




#endif // VEC_H

