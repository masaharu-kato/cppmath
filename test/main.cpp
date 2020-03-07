#include <iostream>
#include "_aliases.h"
#include "Vector.h"

using namespace cpm;
using namespace cpm::alias;

int main(void)
{
	Vector<double, 3> vec1( 1.5,  3.6 ,  7.3);
	Vector<double, 3> vec2(-0.3, 10.35, -0.4);

	std::cout << vec1 << "\n";
	std::cout << vec2 << "\n";
	std::cout << (vec1 + vec2) << "\n";
	std::cout << (vec1 - vec2) << "\n";
	std::cout << (vec1 * 2.0) << "\n";
	std::cout << (vec2 * -3.0) << "\n";
	std::cout << (vec1 / 4.0) << "\n";
	std::cout << (vec2 / -10.0) << "\n";


	Vector<int, 4> ivec1(1, 3,  7, 15);
	Vector<int, 4> ivec2(2, 6, 14, 30);

	std::cout << ((ivec1 == ivec2) ? 'T' : 'F') << "\n";
	std::cout << ((ivec1 != ivec2) ? 'T' : 'F') << "\n";
	std::cout << ((ivec1 * 2 == ivec2) ? 'T' : 'F') << "\n";
	std::cout << ((ivec1 * 4 == ivec2) ? 'T' : 'F') << "\n";
	std::cout << ((ivec1 == ivec2 / 2) ? 'T' : 'F') << "\n";

	return 0;
}
