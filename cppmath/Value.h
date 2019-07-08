#pragma once
#include "types.h"

namespace math {

	template <class Type, Dimension Dim>
	class Value {
	public:
		Value() noexcept;
		Value(Type) noexcept;

		explicit operator Type&() noexcept;
		explicit operator Type() const noexcept;
		
		Value operator +() const noexcept;
		Value operator -() const noexcept;

		Value operator +(Value) const noexcept;
		Value operator -(Value) const noexcept;
		Value operator *(Value) const noexcept;
		Value operator /(Value) const noexcept;
		Value operator %(Value) const noexcept;

		Value& operator +=(Value) noexcept;
		Value& operator -=(Value) noexcept;
		Value& operator *=(Value) noexcept;
		Value& operator /=(Value) noexcept;
		Value& operator %=(Value) noexcept;

		Value& operator ++() noexcept;
		Value& operator --() noexcept;
		Value& operator ++(int) noexcept;
		Value& operator --(int) noexcept;
		
		bool operator ==(Value) const noexcept;
		bool operator !=(Value) const noexcept;
		bool operator <(Value) const noexcept;
		bool operator >(Value) const noexcept;
		bool operator <=(Value) const noexcept;
		bool operator >=(Value) const noexcept;

	private:
		Type value;
	};

}