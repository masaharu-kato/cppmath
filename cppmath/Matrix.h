#pragma once
#include "Value.h"
#include "Vector.h"

namespace math {
	
	template <class NumType, Dimension N_ROW, Dimension N_COL>
	class Matrix : public Vector<typename NumTypeOf<NumType>::RowNumOf<N_ROW>::ColVectorType, N_COL> {
	public:
	//	matrix type
		template <Dimension R, Dimension C>
		using MatrixType = Matrix<NumType, R, C>;
		
	//	base type
		using BaseType = Vector<typename NumTypeOf<NumType>::RowNumOf<N_ROW>::ColVectorType, N_COL>;

	//	value type
		template <Dimension R, Dimension C>
		using ValueType = Value<NumType, R, C>;
		
	//	constructor
		using BaseType::BaseType;

	////	get specific column vector
	//	template <Dimension C>
	//	auto getColumn() const noexcept {
	//		return BaseType::get<C>();
	//	}

	//	get specific value
		template <Dimension R, Dimension C>
		ValueType<R, C> get() const noexcept {
			return (ValueType<R, C>)*this;
		}

	//	set specific value
		template <Dimension R, Dimension C>
		Matrix& set(const ValueType<R, C>& v) noexcept {
			(ValueType<R, C>&)*this = v;
			return *this;
		}

	//	set specific value (alias of set())
		template <Dimension R, Dimension C>
		Matrix& operator =(const ValueType<R, C>& v) noexcept {
			return set(v);
		}

	//	multiply with matrix
		template <Dimension C>
		MatrixType<N_ROW, C> operator *(const MatrixType<N_COL, C>& m) const noexcept;

	//	calculate determinant
		NumType det() const noexcept;

	//	calculate inverse matrix
		Matrix inverse() const;

	};

}