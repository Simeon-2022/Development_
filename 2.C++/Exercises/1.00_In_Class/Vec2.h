#pragma once
#ifndef VEC2_H
#define VEC2_H

struct vec2 {

private:
	float m_x;
	float m_y;
	const static float eps;

public:
	vec2();
	vec2(float m_x, float m_y);

	vec2& operator+= (const vec2& vec);
	vec2& operator*= (const float& b);

	friend bool operator!= (const vec2& a, const vec2& b);
	friend bool operator== (const vec2& a, const vec2& b);

	friend vec2 operator+ (const vec2& a, const vec2& b);
	friend vec2 operator- (const vec2& a, const vec2& b);

	friend vec2 operator- (const vec2& a, const float& b);
	friend vec2 operator+ (const vec2& a, const float& b);

	friend vec2 operator- (const float& b, const vec2& a);
	friend vec2 operator+ (const float& b, const vec2& a);

	friend vec2 operator* (const vec2& a, const float& b);
	friend vec2 operator/ (const vec2& a, const float& b);

	friend vec2 operator* (const float& b, const vec2& a);
	friend vec2 operator/ (const float& b, const vec2& a);

	//friend vec2& operator++ () { //++c (rpe)

	//	m_x += 1.0f;
	//	m_y += 1.0f;
	//	return *this;
	//};

	//friend vec2& operator++ (int) { //++c (rpe)

	//	m_x += 1.0f;
	//	m_y += 1.0f;
	//	return *this;
	//};

}



#endif // VEC2_H