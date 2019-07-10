#pragma once
#include "Vector.h"

namespace math {

	template <class Type, Dimension Dim>
	class Point : public Vector<Type, Dim> {
	public:
		using Vector<Type, Dim>::Vector;

	};

}