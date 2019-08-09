#pragma once
#include "Value.h"
#include "_type_utils.h"
#include <cmath>
#include <iostream>

namespace math {

//	N-dimensional Vector Class
	template <template <Dimension> class ValType, Dimension N_DIM>
	class Vector : public Vector<ValType, N_DIM-1>, public ValType<N_DIM> {
	public:
		using Front = Vector<ValType, N_DIM-1>;
		using Last = ValType<N_DIM>;
		using NumType = typename ValType<N_DIM>::NumType;

		Vector() noexcept = default;
		Vector(const Front& parent, const Last& value) noexcept
			: Front(parent), Last(value) {}

		
		template <class... Args>
		Vector(Args&&... args) noexcept {
			static_assert(sizeof...(args) == N_DIM, "Too many or too few arguments.");
			set<1>(args...);
		}


		inline const Front& front() const noexcept { return (const Front&)*this; }
		inline const Last& last() const noexcept { return (const Last&)*this; }

		inline Front& front() noexcept { return (Front&)*this; }
		inline Last& last() noexcept { return (Last&)*this; }

		//	get specific value
		template <Dimension D>
		ValType<D> get() const noexcept {
			return (ValType<D>)*this;
		}

		//	set specific value
		template <Dimension D>
		Vector& set(const ValType<D>& v) noexcept {
			(ValType<D>&)*this = v;
			return *this;
		}

		//	set specific value (alias of set())
		template <Dimension D>
		Vector& operator =(const ValType<D>& v) noexcept {
			return set(v);
		}

		//	set all values
		template <Dimension D, class... Rests>
		Vector& set(const ValType<D>& first, Rests&&... rests) noexcept {
			set<D>(first);
			return set<D+1>(rests...);
		}

		template <class _NT>
		operator Vector<_NT, N_ROW, I_COL>() const noexcept {
			return {(Vector<_NT, N_ROW-1, I_COL>)front(), (Value<_NT, N_ROW, I_COL>)last() };
		}

		
		Vector operator +() const noexcept { return {+front(), +last()}; }
		Vector operator -() const noexcept { return {-front(), -last()}; }

		Vector operator + (const Vector& v) const noexcept { return {front() + v.front(), last() + v.last()}; }
		Vector operator - (const Vector& v) const noexcept { return {front() - v.front(), last() - v.last()}; }
		Vector operator * (NumType v) const noexcept { return {front() * v, last() * v}; }
		Vector operator / (NumType v) const noexcept { return {front() / v, last() / v}; }

		Vector& operator += (const Vector& v) noexcept { front() += v.front(); last() += v.last(); return *this; }
		Vector& operator -= (const Vector& v) noexcept { front() -= v.front(); last() -= v.last(); return *this; }
		Vector& operator *= (NumType v) noexcept { front() *= v; last() *= v; return *this; }
		Vector& operator /= (NumType v) noexcept { front() /= v; last() /= v; return *this; }
		
		bool operator ==(const Vector& v) const noexcept { return last() == v.last() && front() == v.front(); }
		bool operator !=(const Vector& v) const noexcept { return last() != v.last() && front() != v.front(); }

		template <class... Args>
		Vector operator ()(Args&&... args) const noexcept { return {front()(args...), last()(args...)}; }

		template <class... Args>
		Vector operator ()(Args&&... args) noexcept { return {front()(args...), last()(args...)}; }



		NumType squared_length() const noexcept {
			return Front::squared_length() + NumType(last() * last());
		}

		NumType length() const noexcept {
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


	//	Specialization when 1x Dimension
	template <template <Dimension> class ValType>
	class Vector<ValType, 1> : public ValType<1> {
	public:
		using Last = ValType<1>;
		using NumType = typename ValType<0>::NumType;

		Last& last() noexcept {
			return (Last&)(*this); 
		}

		const Last& last() const noexcept {
			return (const Last&)(*this);
		}


		Vector() noexcept = default;
		Vector(const Last& value) noexcept
			: Last(value) {}


		template <Dimension D>
		ValType<D> get() const noexcept {
			return (ValType<D>)(*this);
		}

		template <Dimension D>
		ValType<D>& get() noexcept {
			return (ValType<D>&)(*this);
		}
		
		NumType squared_length() const noexcept {
			return ValType(last() * last());
		}

		NumType length() const noexcept {
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


	//	output function for Vector
	template <template <Dimension> class ValType, Dimension N_DIM, class OS>
	OS& operator <<(OS& os, const Vector<ValType, N_DIM>& vec) {
		vec.output(os, ", ", "(", ")");
		return os;
	}
	
	//	input function for Vector
	template <template <Dimension> class ValType, Dimension N_DIM, class IS>
	IS& operator >>(IS& is, Vector<ValType, N_DIM>& vec) {
		vec.input(is);
		return is;
	}


}