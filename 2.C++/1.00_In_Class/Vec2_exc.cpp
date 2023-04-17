#include <iostream>
#include "Vec2.h"
using namespace std;




int main() {

	vec2 a;
	vec2 b(1.0f, 2.0f);
	a = b;
	vec2 c(b);


	return 0;
}