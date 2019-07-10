#include <iostream>
#include "_aliases.h"
#include "Vector.h"
#include "Point.h"

using namespace math;
using namespace math::alias;

int main(void)
{
	while(std::cin) {
		Point3D p1, p2;
		
		std::cout << "p1: ";
		std::cin >> p1;
		
		std::cout << "p2: ";
		std::cin >> p2;

		auto sum = p1 + p2;

		std::cout << "Sum: " << sum << " (length:" << sum.length() << ")\n";
	}

	return 0;
}