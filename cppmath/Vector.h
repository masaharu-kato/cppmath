#pragma once
#include "Value.h"
#include <cmath>

namespace math {

	template <class Type, Dimension Dim>
	class Vector : public Vector<Type, Dim-1>, public Value<Type, Dim> {
	private:
		using Parent = Vector<Type, Dim-1>;
		using _Value = Value<Type, Dim>;

		Parent& parent() noexcept {
			return (Parent&)(*this);
		}

		const Parent& parent() const noexcept {
			return (const Parent&)(*this);
		}

		_Value& value() noexcept {
			return (_Value&)(*this); 
		}

		const _Value& value() const noexcept {
			return (const _Value&)(*this);
		}

	public:
		Vector() noexcept = default;
		Vector(const Parent& parent, _Value value) noexcept
			: Parent(parent), _Value(value) {}

		template <class... Args> Vector(Args&&...) noexcept;

		template <Dimension D>
		Value<Type, D> get() const noexcept {
			return (Value<Type, D>)(*this);
		}

		template <Dimension D>
		Value<Type, D>& get() noexcept {
			return (Value<Type, D>&)(*this);
		}

		template <class T>
		operator Vector<T, Dim>() const noexcept {
			return {Parent::castType<T>(), (T)value(); }
		}

		
		Vector operator +() const noexcept { return {+parent(), +value()}; }
		Vector operator -() const noexcept { return {-parent(), -value()}; }

		Vector operator +(const Vector& v) const noexcept { return {parent() + v.parent(), value() + v.value()}; }
		Vector operator -(const Vector& v) const noexcept { return {parent() - v.parent(), value() - v.value()}; }
		Vector operator *(Type v) const noexcept { return {parent() * v, value() * v}; }
		Vector operator /(Type v) const noexcept { return {parent() / v, value() / v}; }
		Vector operator %(Type v) const noexcept { return {parent() % v, value() % v}; }

		Vector& operator +=(const Vector& v) noexcept { parent() += v.parent(); value() += v.value(); return *this; }
		Vector& operator -=(const Vector& v) noexcept { parent() -= v.parent(); value() -= v.value(); return *this; }
		Vector& operator *=(Type v) noexcept { parent() *= v; value() *= v; return *this; }
		Vector& operator /=(Type v) noexcept { parent() /= v; value() /= v; return *this; }
		Vector& operator %=(Type v) noexcept { parent() %= v; value() %= v; return *this; }
		
		bool operator ==(const Vector& v) const noexcept { return value() == v.value() && parent() == v.parent(); }
		bool operator !=(const Vector& v) const noexcept { return value() != v.value() && parent() != v.parent(); }

		Type squared_length() const noexcept {
			return Parent::squared_length() + value() * value();
		}

		Type length() const noexcept {
			return sqrt(squared_length()); 
		}

		Vector unit() const noexcept {
			return *this / length(); 
		}

		Vector& toUnit() noexcept {
			*this /= length(); return *this;
		}

	};





	template <class Type>
	class Vector<Type, 1> : public Value<Type, 1> {
	private:

		auto& value() noexcept {
			return (Value<Type, 1>&)(*this); 
		}

		const auto& value() const noexcept {
			return (const Value<Type, 1>&)(*this);
		}

	public:
		Vector() noexcept = default;
		Vector(Value<Type, 1> value) noexcept
			: Value<Type, 1>(value) {}

		template <class... Args> Vector(Args&&...) noexcept {
			static_assert(false, "Too many initialize parameters.");
		}

		template <Dimension D>
		Value<Type, D> get() const noexcept {
			return (Value<Type, D>)(*this);
		}

		template <Dimension D>
		Value<Type, D>& get() noexcept {
			return (Value<Type, D>&)(*this);
		}
		
		Type squared_length() const noexcept {
			return value() * value();
		}

		Type length() const noexcept {
			return sqrt(squared_length()); 
		}

		Vector unit() const noexcept {
			return *this / length(); 
		}

		Vector& toUnit() noexcept {
			*this /= length(); return *this;
		}

	};


}