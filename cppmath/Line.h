#pragma once
#include "Vector.h"
#include "Point.h"
#include <optional>

namespace math {

	template <class Type, Dimension Dim>
	class Line {
	private:
		using _Point = Point<Type, Dim>;
		using _Vector = Vector<Type, Dim>;

		_Point point;
		_Vector vec;

	public:
		Line(const _Point& point, const _Vector& vec) noexcept
			: point(point), vec(vec) {}
		
		Line operator +(const _Point&) const noexcept;
		Line operator -(const _Point&) const noexcept;

		Line& operator +=(const _Point&) noexcept;
		Line& operator -=(const _Point&) noexcept;
		
		bool operator ==(const Line& l) const noexcept { return point == l.point && vec == l.vec; }
		bool operator !=(const Line& l) const noexcept { return point != l.point && vec != l.vec; }
		
		Point operator ()(Type) const noexcept;
		template <Dimension D>
		Point operator ()(Value<Type, D>) const noexcept;

		bool operator &(const _Point&) const noexcept;

		Type squared_length() const noexcept {
			return vec.squared_length();
		}

		Type length() const noexcept {
			return vec.length();
		}
	};

}