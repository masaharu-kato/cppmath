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

	template <template<Dimension> class ValType, Dimension N_DIM>
	class Vector;

	//template <class NumType>
	//struct NumTypeOf : _not_constructable {

	//	template <Dimension I_ROW>
	//	struct RowOf : _not_constructable {
	//		template <Dimension I_COL> using ValueType = Value<NumType, I_ROW, I_COL>;
	//		template <Dimension N_COL> using RowVectorType = Vector<ValueType, N_COL>;
	//	};

	//	template <Dimension I_COL>
	//	struct ColOf : _not_constructable {
	//		template <Dimension I_ROW> using ValueType = Value<NumType, I_ROW, I_COL>;
	//		template <Dimension N_ROW> using ColVectorType = Vector<ValueType, N_ROW>;
	//	};

	//	template <Dimension N_ROW>
	//	struct RowNumOf : _not_constructable {
	//		template <Dimension I_COL> using ColVectorType = Vector<typename ColOf<I_COL>::ValueType, N_ROW>;
	//	};

	//	template <Dimension N_COL>
	//	struct ColNumOf : _not_constructable {
	//		template <Dimension I_ROW> using RowVectorType = Vector<typename RowOf<I_ROW>::ValueType, N_COL>;
	//	};

	//};

	//template <class NumType, Dimension I_ROW, Dimension N_COL>
	//using RowVector = typename NumTypeOf<NumType>::template RowOf<I_ROW>::template RowVectorType<N_COL>;

	//template <class NumType, Dimension N_ROW, Dimension I_COL>
	//using ColVector = typename NumTypeOf<NumType>::template ColOf<I_COL>::template ColVectorType<N_ROW>;


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