//#pragma once
#ifndef MYMATH_H
#define MYMATH_H

extern const double g_Pi;

float				area_Circle				(float r);
void				area_Circle_Area_qna	(void);
float				area_Triangle			(float side_A, float side_B);
float				area_Rectangle			(float side_A, float side_B);
int					fceil					(float a);
int					ffloor					(float a);
int					fround					(float a);
float				fpow					(float number, int power);
int					factoriel				(int n);
int					randPositive			(int max);
int					randRange				(int min, int max);
unsigned long long	factoriel_2				(int n);
#endif