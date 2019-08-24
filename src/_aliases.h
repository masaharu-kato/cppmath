#pragma once
#include "_declares.h"

namespace cpm::alias {
	
	template <Dimension Dim> using       VectorD =       Vector<double, Dim>;
	template <Dimension Dim> using    ColVectorD =    ColVector<double, Dim>;
	template <Dimension Dim> using    RowVectorD =    RowVector<double, Dim>;
	template <Dimension Dim> using        PointD =        Point<double, Dim>;
	template <Dimension Dim> using         LineD =         Line<double, Dim>;
	template <Dimension Dim> using  LineSegmentD =  LineSegment<double, Dim>;
	template <Dimension Dim> using        RangeD =        Range<double, Dim>;
	
	template <Dimension Dim> using       VectorF =       Vector<float, Dim>;
	template <Dimension Dim> using    ColVectorF =    ColVector<float, Dim>;
	template <Dimension Dim> using    RowVectorF =    RowVector<float, Dim>;
	template <Dimension Dim> using        PointF =        Point<float, Dim>;
	template <Dimension Dim> using         LineF =         Line<float, Dim>;
	template <Dimension Dim> using  LineSegmentF =  LineSegment<float, Dim>;
	template <Dimension Dim> using        RangeF =        Range<float, Dim>;
	


	using       Vector1D =       VectorD<1>;
	using    ColVector1D =    ColVectorD<1>;
	using    RowVector1D =    RowVectorD<1>;
	using        Point1D =        PointD<1>;
	using         Line1D =         LineD<1>;
	using  LineSegment1D =  LineSegmentD<1>;
	using        Range1D =        RangeD<1>;
	using       Vector2D =       VectorD<2>;
	using    ColVector2D =    ColVectorD<2>;
	using    RowVector2D =    RowVectorD<2>;
	using        Point2D =        PointD<2>;
	using         Line2D =         LineD<2>;
	using  LineSegment2D =  LineSegmentD<2>;
	using        Range2D =        RangeD<2>;
	using       Vector3D =       VectorD<3>;
	using    ColVector3D =    ColVectorD<3>;
	using    RowVector3D =    RowVectorD<3>;
	using        Point3D =        PointD<3>;
	using         Line3D =         LineD<3>;
	using  LineSegment3D =  LineSegmentD<3>;
	using        Range3D =        RangeD<3>;
	using       Vector4D =       VectorD<4>;
	using    ColVector4D =    ColVectorD<4>;
	using    RowVector4D =    RowVectorD<4>;
	using        Point4D =        PointD<4>;
	using         Line4D =         LineD<4>;
	using  LineSegment4D =  LineSegmentD<4>;
	using        Range4D =        RangeD<4>;

	using       Vector1F =       VectorF<1>;
	using    ColVector1F =    ColVectorF<1>;
	using    RowVector1F =    RowVectorF<1>;
	using        Point1F =        PointF<1>;
	using         Line1F =         LineF<1>;
	using  LineSegment1F =  LineSegmentF<1>;
	using        Range1F =        RangeF<1>;
	using       Vector2F =       VectorF<2>;
	using    ColVector2F =    ColVectorF<2>;
	using    RowVector2F =    RowVectorF<2>;
	using        Point2F =        PointF<2>;
	using         Line2F =         LineF<2>;
	using  LineSegment2F =  LineSegmentF<2>;
	using        Range2F =        RangeF<2>;
	using       Vector3F =       VectorF<3>;
	using    ColVector3F =    ColVectorF<3>;
	using    RowVector3F =    RowVectorF<3>;
	using        Point3F =        PointF<3>;
	using         Line3F =         LineF<3>;
	using  LineSegment3F =  LineSegmentF<3>;
	using        Range3F =        RangeF<3>;
	using       Vector4F =       VectorF<4>;
	using    ColVector4F =    ColVectorF<4>;
	using    RowVector4F =    RowVectorF<4>;
	using        Point4F =        PointF<4>;
	using         Line4F =         LineF<4>;
	using  LineSegment4F =  LineSegmentF<4>;
	using        Range4F =        RangeF<4>;


	template <Dimension R, Dimension C> using MatrixD = Matrix<double, R, C>;
	template <Dimension R, Dimension C> using MatrixF = Matrix<float , R, C>;

	using Matrix11D = MatrixD<1, 1>;
	using Matrix12D = MatrixD<1, 2>;
	using Matrix13D = MatrixD<1, 3>;
	using Matrix14D = MatrixD<1, 4>;
	using Matrix21D = MatrixD<2, 1>;
	using Matrix22D = MatrixD<2, 2>;
	using Matrix23D = MatrixD<2, 3>;
	using Matrix24D = MatrixD<2, 4>;
	using Matrix31D = MatrixD<3, 1>;
	using Matrix32D = MatrixD<3, 2>;
	using Matrix33D = MatrixD<3, 3>;
	using Matrix34D = MatrixD<3, 4>;
	using Matrix41D = MatrixD<4, 1>;
	using Matrix42D = MatrixD<4, 2>;
	using Matrix43D = MatrixD<4, 3>;
	using Matrix44D = MatrixD<4, 4>;
	
	using Matrix11F = MatrixF<1, 1>;
	using Matrix12F = MatrixF<1, 2>;
	using Matrix13F = MatrixF<1, 3>;
	using Matrix14F = MatrixF<1, 4>;
	using Matrix21F = MatrixF<2, 1>;
	using Matrix22F = MatrixF<2, 2>;
	using Matrix23F = MatrixF<2, 3>;
	using Matrix24F = MatrixF<2, 4>;
	using Matrix31F = MatrixF<3, 1>;
	using Matrix32F = MatrixF<3, 2>;
	using Matrix33F = MatrixF<3, 3>;
	using Matrix34F = MatrixF<3, 4>;
	using Matrix41F = MatrixF<4, 1>;
	using Matrix42F = MatrixF<4, 2>;
	using Matrix43F = MatrixF<4, 3>;
	using Matrix44F = MatrixF<4, 4>;

}