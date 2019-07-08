#pragma once
#include "Vector.h"

namespace math {

	template <class Type, Dimension Dim>
	class Point : public Vector {
	public:
		using Vector::Vector;

	};

}