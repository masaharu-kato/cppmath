#pragma once
#include "RowVector.h"
#include "ColumnVector.h"

namespace math {

	template <class Type, Dimension N_ROW, Dimension N_COL>
	class Matrix : public RowVector<ColumnVector<Type, N_ROW>, N_COL> {
	public:
		Matrix() noexcept = default;
		Matrix(const Matrix<Type, Dim-1>& parent, Value<Type, Dim> value) noexcept
			: Matrix<Type, Dim-1>(parent), Value<Type, Dim>(value) {}

		template <class... Args> Matrix(Args&&...) noexcept;

		template <Dimension R>
		explicit operator Value<RowVector<Type, N_COL>, R>() const noexcept {
			return (Vector<Type, N_COL>)(Vector<Value<Type, R>, N_COL>)(*this);
		}

		template <Dimension R>
		auto getRow() const noexcept {
			return (RowVector<Type, N_COL>)(Value<RowVector<Type, N_COL>, R>)(*this);
		}

		template <Dimension C>
		auto getColumn() const noexcept {
			return (ColumnVector<Type, N_ROW>)(Value<ColumnVector<Type, N_ROW>, C>)(*this);
		}

		template <Dimension R, Dimension C>
		Type get() const noexcept;

		template <Dimension R, Dimension C>
		Type& get() noexcept;

		template <Dimension C>
		Matrix<Type, Row, C> operator *(const Matrix<Type, COL, C>& m) const noexcept;

		Type det() const;

		Matrix inverse() const;

	};

}