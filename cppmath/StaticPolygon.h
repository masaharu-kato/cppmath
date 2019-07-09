#pragma once
#include "Point.h"

namespace math {

	template <class Type, Dimension Dim, size_t Size>
	class StaticPolygon : public Vector<Point<Type, Dim>, Size> {
	public:
		using _Point = Point<Type, Dim>;

		template <class... Args>
		StaticPolygon(Args&&...) noexcept;

		template <size_t N>
		_Point get() const noexcept;

		bool operator &(const _Point&) const noexcept;
	};

}