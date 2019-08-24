#include <iostream>
#include "_aliases.h"
#include "Vector.h"

using namespace cpm;
using namespace cpm::alias;

int main(void)
{
	RowVector3D vec(1.5, 3.6, 7.3);

	std::cout << vec << "\n";

	return 0;
}