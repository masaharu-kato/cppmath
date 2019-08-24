#pragma once
#include "Point.h"

namespace cpm {

	template <class Type, Dimension Dim>
	class Range {
	private:
		using _Point = Point<Type, Dim>;

		_Point beg;
		_Point end;

	public:
		Range(const _Point& beg, const _Point& end) noexcept
			: beg(beg), end(end) {}
		
		_Point operator ()(Type) const noexcept;
		bool operator &(const _Point&) const noexcept;
		bool contains(const _Point&) const noexcept;
		Type length() const noexcept;


	};

}