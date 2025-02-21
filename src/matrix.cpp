#include "../headers/matrix.h"


Matrix2D::Matrix2D(float a11, float a12, float a21, float a22) 
{
	m_matrix.resize(2);

	m_matrix[0].push_back(a11);
	m_matrix[0].push_back(a12);
	m_matrix[1].push_back(a21);
	m_matrix[1].push_back(a22);
}


Matrix2D::Matrix2D(vec2 v1, vec2 v2)
{
	m_matrix.resize(2);

	m_matrix[0].push_back(v1.getX());
	m_matrix[0].push_back(v1.getY());
	m_matrix[1].push_back(v2.getX());
	m_matrix[1].push_back(v2.getY());
}


matrix Matrix2D::getMatrix() {
	return m_matrix;
}


float& Matrix2D::operator()(int i, int j) {
	return m_matrix[i][j];
}

Matrix2D Matrix2D::operator+(Matrix2D& other) 
{
	return Matrix2D(m_matrix[0][0] + other(0, 0), m_matrix[0][1] + other(0, 1),
		m_matrix[1][0] + other(1, 0), m_matrix[1][1] + other(1, 1));
}

Matrix2D Matrix2D::operator-(Matrix2D& other)
{
	return Matrix2D(m_matrix[0][0] - other(0, 0), m_matrix[0][1] - other(0, 1),
					 m_matrix[1][0] - other(1, 0), m_matrix[1][1] - other(1, 1));
}

Matrix2D Matrix2D::operator*(float scalar)
{
	return Matrix2D(scalar * m_matrix[0][0], scalar * m_matrix[0][1], 
					 scalar * m_matrix[1][0], scalar * m_matrix[1][1]);
}

Matrix2D& Matrix2D::operator=(const Matrix2D& other)
{
	m_matrix[0][0] = other.m_matrix[0][0];
	m_matrix[0][1] = other.m_matrix[0][1];
	m_matrix[1][0] = other.m_matrix[1][0];
	m_matrix[1][1] = other.m_matrix[1][1];
	
	return *this;
}

vec2 Matrix2D::operator*(const vec2& v)
{
	return vec2(m_matrix[0][0] * v.getX() + m_matrix[0][1] * v.getY(),
				m_matrix[1][0] * v.getX() + m_matrix[1][1] * v.getY());
}


Matrix2D Matrix2D::operator*(Matrix2D& other) {
	return Matrix2D(
		m_matrix[0][0] * other.m_matrix[0][0],
		m_matrix[0][1] * other.m_matrix[1][0],
		m_matrix[1][0] * other.m_matrix[0][1],
		m_matrix[1][1] * other.m_matrix[1][1]);

}