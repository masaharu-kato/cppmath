#pragma once
#include "Vector.h"
#include "Point.h"
#include <optional>

namespace math {

	template <class Type, Dimension Dim>
	class Line {
	public:
		Line(const Point&, const Vector&) noexcept;
		
		Line operator +(const Point&) const noexcept;
		Line operator -(const Point&) const noexcept;

		Line& operator +=(const Point&) noexcept;
		Line& operator -=(const Point&) noexcept;
		
		bool operator ==(const Line&) const noexcept;
		bool operator !=(const Line&) const noexcept;
		
		Point operator ()(Type) const noexcept;
		template <Dimension D>
		Point operator ()(Value<Type, D>) const noexcept;

		bool operator &(const Point&) const noexcept;

		Type length() const noexcept;

	private:
		Point point;
		Vector vector;
	};

}