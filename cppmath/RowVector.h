#pragma once
#include "ColumnVector.h"

namespace math {

	template <class Type, Dimension Dim>
	class RowVector : public Vector<Type, Dim> {
	public:
		using Vector::Vector;
		
		Type operator *(const ColumnVector<Type, Dim>& v) const noexcept {
			return parent() * v.parent() + value() * v.value();
		};

		template <Dimension N_COL>
		RowVector<Type, N_COL> operator *(const RowVector<ColumnVector<Type, Dim>, N_COL>& m) const noexcept;

	};

}