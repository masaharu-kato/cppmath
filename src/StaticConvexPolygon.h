#pragma once
#include "StaticPolygon.h"

namespace cpm {

	template <class Type, Dimension Dim, size_t Size>
	class StaticConvexPolygon : public StaticPolygon<Type, Dim, Size> {
	public:
		using StaticPolygon<Type, Dim, Size>::StaticPolygon;
		
		bool operator &(const _Point&) const noexcept;
	};

}