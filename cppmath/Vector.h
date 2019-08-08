#pragma once
#include "Value.h"
#include <cmath>
#include <iostream>

namespace math {

	template <template <Dimension> class ValueType, Dimension Dim>
	class Vector {
	private:
		using Front = Vector<ValueType, Dim-1>;
		using Last = ValueType<Dim>;
		using NumericType = ValueType<0>::NumericType;
		static constexpr Dimension I_DIM = Dim;

		Front front;
		Last last;

	public:
		Vector() noexcept = default;
		Vector(const Front& parent, Last value) noexcept
			: Front(parent), Last(value) {}

	//	template <class... Args> Vector(Args&&...) noexcept;

		template <Dimension D>
		ValueType<D> get() const noexcept {
			return (ValueType<D>)(*this);
		}

		template <Dimension D>
		ValueType<D>& get() noexcept {
			return (ValueType<D>&)(*this);
		}

		template <class T>
		operator Vector<T, Dim>() const noexcept {
			return {(Vector<T, Dim-1>)front, (T)last };
		}

		
		Vector operator +() const noexcept { return {+front, +last}; }
		Vector operator -() const noexcept { return {-front, -last}; }

		Vector operator + (const Vector& v) const noexcept { return {front + v.front, last + v.last}; }
		Vector operator - (const Vector& v) const noexcept { return {front - v.front, last - v.last}; }
		//Vector operator * (const Vector& v) const noexcept { return {front * v.front, last * v.last}; }
		//Vector operator / (const Vector& v) const noexcept { return {front / v.front, last / v.last}; }

		//Vector operator + (NumericType v) const noexcept { return {front + v, last + v}; }
		//Vector operator - (NumericType v) const noexcept { return {front - v, last - v}; }
		Vector operator * (NumericType v) const noexcept { return {front * v, last * v}; }
		Vector operator / (NumericType v) const noexcept { return {front / v, last / v}; }

		Vector& operator += (const Vector& v) noexcept { front += v.front; last += v.last; return *this; }
		Vector& operator -= (const Vector& v) noexcept { front -= v.front; last -= v.last; return *this; }
		//Vector& operator *= (const Vector& v) noexcept { front *= v.front; last *= v.last; return *this; }
		//Vector& operator /= (const Vector& v) noexcept { front /= v.front; last /= v.last; return *this; }

		//Vector& operator += (NumericType v) noexcept { front += v; last += v; return *this; }
		//Vector& operator -= (NumericType v) noexcept { front -= v; last -= v; return *this; }
		Vector& operator *= (NumericType v) noexcept { front *= v; last *= v; return *this; }
		Vector& operator /= (NumericType v) noexcept { front /= v; last /= v; return *this; }
		
		bool operator ==(const Vector& v) const noexcept { return last == v.last && front == v.front; }
		bool operator !=(const Vector& v) const noexcept { return last != v.last && front != v.front; }

		template <class... Args>
		Vector operator ()(Args&&... args) const noexcept { return {front(args...), last(args...)}; }

		template <class... Args>
		Vector operator ()(Args&&... args) noexcept { return {front(args...), last(args...)}; }



		ValueType squared_length() const noexcept {
			return Front::squared_length() + ValueType(last * last);
		}

		ValueType length() const noexcept {
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


	template <template <Dimension> class ValueType, Dimension Dim, class OS>
	OS& operator <<(OS& os, const Vector<ValueType, Dim>& vec) {
		vec.output(os, ", ", "(", ")");
		return os;
	}
	

	template <template <Dimension> class ValueType, Dimension Dim, class IS>
	IS& operator >>(IS& is, Vector<ValueType, Dim>& vec) {
		vec.input(is);
		return is;
	}



	template <template <Dimension> class ValueType>
	class Vector<ValueType, 1> : public ValueType<1> {
	private:
		using Last = ValueType<1>;

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
		ValueType<D> get() const noexcept {
			return (ValueType<D>)(*this);
		}

		template <Dimension D>
		ValueType<D>& get() noexcept {
			return (ValueType<D>&)(*this);
		}
		
		ValueType squared_length() const noexcept {
			return ValueType(last * last);
		}

		ValueType length() const noexcept {
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