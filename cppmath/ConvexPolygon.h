#pragma once
#include "Polygon.h"

namespace math {
	
	template <class Type, Dimension Dim>
	class ConvexPolygon {
	public:
		using Polygon::Polygon;
		
		bool operator &(const _Point&) const noexcept;
	};

}