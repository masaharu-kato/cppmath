#pragma once
#include "_types.h"

namespace math {

	struct _not_constructable {
		_not_constructable() = delete;
	};


	template <class Type, Dimension ROW, Dimension COL>
	class Value;

	template <template <Dimension> class ValueType, Dimension N_DIM>
	class Vector;

	template <class Type, Dimension COL>
	struct ColValue : _not_constructable {
		template <Dimension ROW>
		using Type = Value<Type, ROW, COL>;
	};

	template <class Type, Dimension N_ROW, Dimension COL>
	using ColVectorInRow = Vector<ColValue<Type, COL>::Type, N_ROW>;

	template <class Type, Dimension N_ROW>
	struct ColVectorInRowVector : _not_constructable {
		template <Dimension COL>
		using Type = ColVectorInRow<Type, N_ROW, COL>;
	};


	template <class Type, Dimension ROW>
	struct RowValue : _not_constructable {
		template <Dimension COL>
		using Type = Value<Type, ROW, COL>;
	};

	template <class Type, Dimension ROW, Dimension N_COL>
	using RowVectorInCol = Vector<RowValue<Type, ROW>::Type, N_COL>;

	template <class Type, Dimension N_COL>
	struct RowVectorInColVector : _not_constructable {
		template <Dimension ROW>
		using Type = RowVectorInCol<Type, ROW, N_COL>;
	};


	template <class Type, Dimension Dim>
	class Point;

	template <class Type, Dimension Dim>
	class Line;

	template <class Type, Dimension Dim>
	class LineSegment;

	template <class Type, Dimension Dim>
	class Range;

	template <class Type, Dimension N_ROW, Dimension N_COL>
	class Matrix;

	template <class Type, Dimension N_COL>
	using ColVector = Matrix<Type, 1, N_COL>;

	template <class Type, Dimension N_ROW>
	using RowVector = Matrix<Type, N_ROW, 1>;

	template <class Type, Dimension Dim, size_t Size>
	class StaticPolygon;
	
	template <class Type, Dimension Dim, size_t Size>
	class StaticConvexPolygon;

	template <class Type, Dimension Dim>
	class Polygon;
	
	template <class Type, Dimension Dim>
	class ConvexPolygon;

}