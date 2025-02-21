#ifndef MATRIX_H
#define MATRIX_H

#include "vec.h"

#include <vector>

using matrix = std::vector<std::vector<float>>;

class Matrix2D {
public:

	Matrix2D(float a11, float a12, float a21, float a22);
	Matrix2D(vec2 v1, vec2 v2);

	matrix getMatrix();
	

public: //operator
	float& operator()(int i, int j);
	Matrix2D operator+(Matrix2D& other);
	Matrix2D operator-(Matrix2D& other);
	Matrix2D operator*(float scalar);
	Matrix2D operator*(Matrix2D& other);
	Matrix2D& operator=(const Matrix2D& other);
	vec2 operator*(const vec2& v);
private:

	matrix m_matrix;

};


#endif // !MATRIX_H
