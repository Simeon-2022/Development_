#include "Vec2.h"
#include <cmath>

const float vec2::eps(0.0001f);

vec2::vec2() : m_x(0.0), m_y(0.0) {};

vec2::vec2(float m_x, float m_y) : m_x(m_x), m_y(m_y) {};

bool operator!= (const vec2& a, const vec2& b) {
	
	return (!(fabs(a.m_x - b.m_x) <= vec2::eps) && !(fabs(a.m_y - b.m_y) <= vec2::eps));
}

bool operator== (const vec2& a, const vec2& b) {

	return !(a != b);

}

vec2& vec2::operator+= (const vec2 & vec) {
	this->m_x += vec.m_x; // can be just m_x - nothing to hide m_x same for the rest
	this->m_y += vec.m_y;

	return *this;
};

vec2& vec2::operator*= (const float& b) {

	this->m_x *= b;
	this->m_y *= b;

	return *this;
};

vec2 operator+ (const vec2& a, const vec2& b) {

	//return vec2(a.m_x + b.m_x, a.m_y + b.m_y);
	/*vec2 res;
	res.m_x += a.m_x;
	res.m_x += b.m_x;

	res.m_y += a.m_y;
	res.m_y += b.m_y;

	return res;*/

	vec2 res(a);
	return res += b;
};

vec2 operator- (const vec2& a, const vec2& b) {

	return vec2(a.m_x - b.m_x, b.m_y - b.m_y);
};

vec2 operator+ (const vec2& a, const float& b) {

	return vec2(a.m_x + b, a.m_y + b);
};

vec2 operator- (const vec2& a, const float& b) {

	return vec2(a.m_x - b, a.m_y - b);
};

vec2 operator+ (const float& b, const vec2& a) {
	return a + b;
};

vec2 operator- (const float& b, const vec2& a) {

	return vec2(b - a.m_x, b - a.m_y);
};

vec2 operator* (const float& b, const vec2& a) {
	return vec2(b * a.m_x, b * a.m_y);
};
vec2 operator/ (const float& b, const vec2& a) {
	return vec2(b / a.m_x, b / a.m_y);
};

vec2 operator* (const vec2& a, const float& b) {

	vec2 res(a);
	return res *= b;

	return b * a;
};

vec2 operator/ (const vec2& a, const float& b) {
	return vec2 (a.m_x /b, a.m_y / b);
};