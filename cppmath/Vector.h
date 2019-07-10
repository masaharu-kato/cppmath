#pragma once
#include "Value.h"
#include <cmath>
#include <iostream>

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

	//	template <class... Args> Vector(Args&&...) noexcept;

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
			return {(Vector<T, Dim-1>)parent(), (T)value() };
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
			return Parent::squared_length() + Type(value() * value());
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
		

		template <class OS, class STR>
		void output(OS& os, STR delimiter) const {
			Parent::output(os, delimiter);
			os << delimiter;
			_Value::output(os);
		}


		template <class OS, class STR>
		void output(OS& os, STR delimiter, STR prefix, STR suffix) const {
			os << prefix;
			Parent::output(os, delimiter);
			os << delimiter;
			_Value::output(os);
			os << suffix;
		}


		template <class IS>
		void input(IS& is) {
			Parent::input(is);
			_Value::input(is);
		}

	};


	template <class Type, Dimension Dim, class OS>
	OS& operator <<(OS& os, const Vector<Type, Dim>& vec) {
		vec.output(os, ", ", "(", ")");
		return os;
	}
	

	template <class Type, Dimension Dim, class IS>
	IS& operator >>(IS& is, Vector<Type, Dim>& vec) {
		vec.input(is);
		return is;
	}



	template <class Type>
	class Vector<Type, 1> : public Value<Type, 1> {
	private:
		using _Value = Value<Type, 1>;

		auto& value() noexcept {
			return (_Value&)(*this); 
		}

		const auto& value() const noexcept {
			return (const _Value&)(*this);
		}

	public:
		Vector() noexcept = default;
		Vector(_Value value) noexcept
			: _Value(value) {}

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
			return Type(value() * value());
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


		template <class OS, class STR>
		void output(OS& os, STR delimiter) const {
			_Value::output(os);
		}


		template <class OS, class STR>
		void output(OS& os, STR delimiter, STR prefix, STR suffix) const {
			os << prefix;
			_Value::output(os);
			os << suffix;
		}


		template <class IS>
		void input(IS& is) {
			_Value::input(is);
		}


	};


}