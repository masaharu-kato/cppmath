#pragma once
#include "Vector.h"

namespace math {

	template <class NumericType, Dimension Dim>
	class Point : public RowVector<NumericType, Dim> {
	public:
		using RowVector<NumericType, Dim>::RowVector;

	};

}