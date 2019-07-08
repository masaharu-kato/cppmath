#pragma once
#include "Line.h"

namespace math {
	
	template <class Type, Dimension Dim>
	class LineSegment : public Line<Type, Dim> {
	public:
		using Line::Line;
		
		explicit operator Line&() noexcept;
		explicit operator const Line&() const noexcept;
		
		bool operator &(const Point&) const noexcept;
	};

}