#pragma once
#include "Point.h"
#include <vector>

namespace math {

	template <class Type, Dimension Dim>
	class Polygon {
	public:
		using _Point = Point<Type, Dim>;

		Polygon() noexcept;
		Polygon(const std::vector<_Point>&) noexcept;

		_Point operator [](size_t) const noexcept;

		bool operator &(const _Point&) const noexcept;
		
		bool operator ==(const StaticPolygon&) const noexcept;
		bool operator !=(const StaticPolygon&) const noexcept;

	private:
		std::vector<_Point> points;
	};

}