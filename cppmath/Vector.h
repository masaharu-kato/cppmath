#pragma once
#include "Value.h"
#include <cmath>
#include <iostream>

namespace math {

	template <class Type, Dimension Dim>
	class Vector {
	private:
		using Front = Vector<Type, Dim-1>;
		using Last = Value<Type, Dim>;

		Front front;
		Last last;

	public:
		Vector() noexcept = default;
		Vector(const Front& parent, Last value) noexcept
			: Front(parent), Last(value) {}

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
			return {(Vector<T, Dim-1>)front, (T)last };
		}

		
		Vector operator +() const noexcept { return {+front, +last}; }
		Vector operator -() const noexcept { return {-front, -last}; }

		Vector operator + (const Vector& v) const noexcept { return {front + v.front, last + v.last}; }
		Vector operator - (const Vector& v) const noexcept { return {front - v.front, last - v.last}; }
		Vector operator * (const Vector& v) const noexcept { return {front * v.front, last * v.last}; }
		Vector operator / (const Vector& v) const noexcept { return {front / v.front, last / v.last}; }

		Vector operator + (Type v) const noexcept { return {front + v, last + v}; }
		Vector operator - (Type v) const noexcept { return {front - v, last - v}; }
		Vector operator * (Type v) const noexcept { return {front * v, last * v}; }
		Vector operator / (Type v) const noexcept { return {front / v, last / v}; }

		Vector& operator += (const Vector& v) noexcept { front += v.front; last += v.last; return *this; }
		Vector& operator -= (const Vector& v) noexcept { front -= v.front; last -= v.last; return *this; }
		Vector& operator *= (const Vector& v) noexcept { front *= v.front; last *= v.last; return *this; }
		Vector& operator /= (const Vector& v) noexcept { front /= v.front; last /= v.last; return *this; }

		Vector& operator += (Type v) noexcept { front += v; last += v; return *this; }
		Vector& operator -= (Type v) noexcept { front -= v; last -= v; return *this; }
		Vector& operator *= (Type v) noexcept { front *= v; last *= v; return *this; }
		Vector& operator /= (Type v) noexcept { front /= v; last /= v; return *this; }
		
		bool operator ==(const Vector& v) const noexcept { return last == v.last && front == v.front; }
		bool operator !=(const Vector& v) const noexcept { return last != v.last && front != v.front; }

		template <class... Args>
		Vector operator ()(Args&&... args) const noexcept { return {front(args...), last(args...)}; }

		template <class... Args>
		Vector operator ()(Args&&... args) noexcept { return {front(args...), last(args...)}; }



		Type squared_length() const noexcept {
			return Front::squared_length() + Type(last * last);
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
			Front::output(os, delimiter);
			os << delimiter;
			Last::output(os);
		}


		template <class OS, class STR>
		void output(OS& os, STR delimiter, STR prefix, STR suffix) const {
			os << prefix;
			Front::output(os, delimiter);
			os << delimiter;
			Last::output(os);
			os << suffix;
		}


		template <class IS>
		void input(IS& is) {
			Front::input(is);
			Last::input(is);
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
		using Last = Value<Type, 1>;

		auto& last noexcept {
			return (Last&)(*this); 
		}

		const auto& last const noexcept {
			return (const Last&)(*this);
		}

	public:
		Vector() noexcept = default;
		Vector(Last value) noexcept
			: Last(value) {}

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
			return Type(last * last);
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
			Last::output(os);
		}


		template <class OS, class STR>
		void output(OS& os, STR delimiter, STR prefix, STR suffix) const {
			os << prefix;
			Last::output(os);
			os << suffix;
		}


		template <class IS>
		void input(IS& is) {
			Last::input(is);
		}


	};


}