#pragma once
#include "Vector.h"

namespace cpm {

	template <class NumType, Dimension Dim>
	class Point : public RowVector<NumType, Dim> {
	public:
		using RowVector<NumType, Dim>::RowVector;

	};

}