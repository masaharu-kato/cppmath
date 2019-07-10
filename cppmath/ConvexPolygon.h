#pragma once
#include "Polygon.h"

namespace math {
	
	template <class Type, Dimension Dim>
	class ConvexPolygon : public Polygon<Type, Dim> {
	public:
		using Polygon<Type, Dim>::Polygon;
		
		bool operator &(const _Point&) const noexcept;
	};

}