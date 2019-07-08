#pragma once
#include "Value.h"

namespace math {

	template <class Type, Dimension Dim>
	class Vector {
	public:
		Vector() noexcept;

		template <class... Args>
		Vector(Args&&...) noexcept;
		
		Vector operator +() const noexcept;
		Vector operator -() const noexcept;

		Vector operator +(const Vector&) const noexcept;
		Vector operator -(const Vector&) const noexcept;
		Vector operator *(Type) const noexcept;
		Vector operator /(Type) const noexcept;
		Vector operator %(Type) const noexcept;

		Vector& operator +=(const Vector&) noexcept;
		Vector& operator -=(const Vector&) noexcept;
		Vector& operator *=(Type) noexcept;
		Vector& operator /=(Type) noexcept;
		Vector& operator %=(Type) noexcept;
		
		bool operator ==(const Vector&) const noexcept;
		bool operator !=(const Vector&) const noexcept;

		Type squared_length() const noexcept;
		Type length() const noexcept;

		Vector unit() const noexcept;
		Vector& toUnit() noexcept;

	private:
		Vector<Type, Dim-1> parent;
		Value<Type, Dim> value;
	};

}