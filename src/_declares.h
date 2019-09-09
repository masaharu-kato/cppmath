#pragma once
#include "_types.h"

namespace cpm {

	struct _not_constructable {
		_not_constructable() = delete;
	};

	template <Dimension I_DIM>
	struct SingleDim;

	template <Dimension I_ROW, Dimension I_COL>
	struct DoubleDim;

	template <Dimension I_ROW>
	struct RowDim;

	template <Dimension I_COL>
	struct ColDim;


	template <class... Dims>
	struct DimSet;

	template <Dimension... I_DIMs>
	using SingleDims = DimSet<SingleDim<I_DIMs>...>;

	template <Dimension... I_ROWs>
	using RowDims = DimSet<RowDim<I_ROWs>...>;

	template <Dimension... I_COLs>
	using ColDims = DimSet<ColDim<I_COLs>...>;

	template <Dimension N_DIM>
	struct SingleDimSeq;

	template <Dimension N_ROW, Dimension N_COL>
	struct DoubleDimSeq;

	template <Dimension N_ROW>
	struct RowDimSeq;

	template <Dimension N_COL>
	struct ColDimSeq;


	template <class NumType, class Kind>
	class ValueType;

	template <class NumType, class DimSet>
	class VectorMold;

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

	template <class NumType, Dimension N_DIM>
	class Vector;

	template <class NumType, Dimension N_DIM>
	class RowVector;

	template <class NumType, Dimension N_DIM>
	class ColVector;


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