#pragma once
#include "Point.h"

namespace cpm {

	template <class Type, Dimension Dim, size_t Size>
	class StaticPolygon : public Vector<Point<Type, Dim>, Size> {
	public:
		using _Point = Point<Type, Dim>;

		template <class... Args>
		StaticPolygon(Args&&...) noexcept;

		bool operator &(const _Point&) const noexcept;
	};

}