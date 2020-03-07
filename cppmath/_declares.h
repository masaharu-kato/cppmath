#pragma once
#include "_types.h"

namespace math {

	struct _not_constructable {
		_not_constructable() = delete;
	};

	template <Dimension I_DIM>
	struct SingleDim;

	template <Dimension N_DIM>
	struct SingleDimSet;

	template <Dimension I_ROW, Dimension I_COL>
	struct DoubleDim;

	template <Dimension N_ROW, Dimension N_COL>
	struct DoubleDimSet;

	template <class NumType, class Kind>
	class ValueType;

	template <template <Dimension> class ValType, Dimension N_DIM>
	class VectorType;


//	Types for ValueType's `Kind` template argument
	template <Dimension I_DIM>
	struct ValueKind_Normal;

	template <Dimension I_DIM>
	struct ValueKind_Col;

	template <Dimension I_DIM>
	struct ValueKind_Row;

	template <Dimension I_ROW, Dimension I_COL>
	struct ValueKind_RowCol;

//	ValueType aliases
	template <class NumType, Dimension I_DIM>
	using Value = ValueType<NumType, ValueKind_Normal<I_DIM>>;

	template <class NumType, Dimension I_DIM>
	using ColValue = ValueType<NumType, ValueKind_Col<I_DIM>>;

	template <class NumType, Dimension I_DIM>
	using RowValue = ValueType<NumType, ValueKind_Row<I_DIM>>;

	template <class NumType, Dimension I_ROW, Dimension I_COL>
	using RowColValue = ValueType<NumType, ValueKind_RowCol<I_ROW, I_COL>>;

//	ValueType aliases with `NumType` prespecified
	template <class NumType>
	struct _with_NumType {
		template <Dimension I_DIM>
		using Value = ValueType<NumType, ValueKind_Normal<I_DIM>>;

		template <Dimension I_DIM>
		using ColValue = ValueType<NumType, ValueKind_Col<I_DIM>>;

		template <Dimension I_DIM>
		using RowValue = ValueType<NumType, ValueKind_Row<I_DIM>>;

		template <Dimension I_ROW, Dimension I_COL>
		using RowColValue = ValueType<NumType, ValueKind_RowCol<I_ROW, I_COL>>;
	};

//	Vector aliases with `NumType`
	template <class NumType, Dimension N_DIM>
	using Vector = VectorType<typename _with_NumType<NumType>::Value, N_DIM>;

	template <class NumType, Dimension N_DIM>
	using ColVector = VectorType<typename _with_NumType<NumType>::ColValue, N_DIM>;

	template <class NumType, Dimension N_DIM>
	using RowVector = VectorType<typename _with_NumType<NumType>::RowValue, N_DIM>;



	template <class NumType, Dimension Dim>
	class Point;

	template <class NumType, Dimension Dim>
	class Line;

	template <class NumType, Dimension Dim>
	class LineSegment;

	template <class NumType, Dimension Dim>
	class Range;

	template <class NumType, Dimension N_ROW, Dimension N_COL>
	class Matrix;

	template <class NumType, Dimension Dim, size_t Size>
	class StaticPolygon;
	
	template <class NumType, Dimension Dim, size_t Size>
	class StaticConvexPolygon;

	template <class NumType, Dimension Dim>
	class Polygon;
	
	template <class NumType, Dimension Dim>
	class ConvexPolygon;

}