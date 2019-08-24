#pragma once
#include "Polygon.h"

namespace cpm {
	
	template <class Type, Dimension Dim>
	class ConvexPolygon : public Polygon<Type, Dim> {
	public:
		using Polygon<Type, Dim>::Polygon;
		
		bool operator &(const _Point&) const noexcept;
	};

}