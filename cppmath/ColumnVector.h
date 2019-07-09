#pragma once
#include "Vector.h"

namespace math {

	template <class Type, Dimension Dim>
	class ColumnVector : public Vector<Type, Dim> {
	public:
		using Vector::Vector;

	};

}