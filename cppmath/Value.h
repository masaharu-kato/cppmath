#pragma once
#include "_declares.h"

namespace math {

	template <class Type, Dimension Dim>
	class Value {
	private:
		Type value;

	public:
		Value() noexcept = default;
		Value(Type value) noexcept : value(value) {}

		explicit operator Type&() noexcept { return value; }
		explicit operator Type() const noexcept { return value; }
		
		Value operator +() const noexcept { return +value; }
		Value operator -() const noexcept { return -value; }

		Value operator +(Value v) const noexcept { return value + v; }
		Value operator -(Value v) const noexcept { return value - v; }
		Value operator *(Value v) const noexcept { return value * v; }
		Value operator /(Value v) const noexcept { return value / v; }
		Value operator %(Value v) const noexcept { return value % v; }

		Value& operator +=(Value v) noexcept { value += v; return *this; }
		Value& operator -=(Value v) noexcept { value -= v; return *this; }
		Value& operator *=(Value v) noexcept { value *= v; return *this; }
		Value& operator /=(Value v) noexcept { value /= v; return *this; }
		Value& operator %=(Value v) noexcept { value %= v; return *this; }

		Value& operator ++() noexcept { ++value; return *this; }
		Value& operator --() noexcept { --value; return *this; }
		Value operator ++(int) noexcept { Value current = value++; return current; }
		Value operator --(int) noexcept { Value current = value--; return current; }
		
		bool operator ==(Value v) const noexcept { return value == v; }
		bool operator !=(Value v) const noexcept { return value != v; }
		bool operator < (Value v) const noexcept { return value <  v; }
		bool operator > (Value v) const noexcept { return value >  v; }
		bool operator <=(Value v) const noexcept { return value <= v; }
		bool operator >=(Value v) const noexcept { return value >= v; }
	};

}