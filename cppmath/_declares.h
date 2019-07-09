#pragma once
#include "_types.h"

namespace math {

	template <class Type, Dimension Dim>
	class Value;

	template <class Type, Dimension Dim>
	class Vector;

	template <class Type, Dimension Dim>
	class ColumnVector;

	template <class Type, Dimension Dim>
	class RowVector;

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

	template <class Type, Dimension Dim, size_t Size>
	class StaticPolygon;
	
	template <class Type, Dimension Dim, size_t Size>
	class StaticConvexPolygon;

	template <class Type, Dimension Dim>
	class Polygon;
	
	template <class Type, Dimension Dim>
	class ConvexPolygon;

}