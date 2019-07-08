#pragma once
#include "Point.h"

namespace math {

	template <class Type, Dimension Dim>
	class Range {
	public:
		Range(const Point&, const Point&) noexcept;
		
		Point operator ()(Type) const noexcept;
		bool operator &(const Point&) const noexcept;
		bool contains(const Point&) const noexcept;
		Type length() const noexcept;

	private:
		Point beg;
		Point end;
	};

}