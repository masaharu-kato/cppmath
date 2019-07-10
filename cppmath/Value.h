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
		
		Value operator +() const noexcept { return +(Type)value; }
		Value operator -() const noexcept { return -(Type)value; }

		Value operator +(Value v) const noexcept { return value + (Type)v; }
		Value operator -(Value v) const noexcept { return value - (Type)v; }
		Value operator *(Value v) const noexcept { return value * (Type)v; }
		Value operator /(Value v) const noexcept { return value / (Type)v; }
		Value operator %(Value v) const noexcept { return value % (Type)v; }

		Value& operator +=(Value v) noexcept { value += (Type)v; return *this; }
		Value& operator -=(Value v) noexcept { value -= (Type)v; return *this; }
		Value& operator *=(Value v) noexcept { value *= (Type)v; return *this; }
		Value& operator /=(Value v) noexcept { value /= (Type)v; return *this; }
		Value& operator %=(Value v) noexcept { value %= (Type)v; return *this; }

		Value& operator ++() noexcept { ++value; return *this; }
		Value& operator --() noexcept { --value; return *this; }
		Value operator ++(int) noexcept { Value current = value++; return current; }
		Value operator --(int) noexcept { Value current = value--; return current; }
		
		bool operator ==(Value v) const noexcept { return value == (Type)v; }
		bool operator !=(Value v) const noexcept { return value != (Type)v; }
		bool operator < (Value v) const noexcept { return value <  (Type)v; }
		bool operator > (Value v) const noexcept { return value >  (Type)v; }
		bool operator <=(Value v) const noexcept { return value <= (Type)v; }
		bool operator >=(Value v) const noexcept { return value >= (Type)v; }


		template <class OS>
		void output(OS& os) const {
			os << value;
		}

		template <class IS>
		void input(IS& is) {
			is >> value;
		}

	};

	template <class Type, Dimension Dim, class OS>
	OS& operator >>(OS& os, const Value<Type, Dim>& value) {
		value.output(os);
		return os;
	}


	template <class Type, Dimension Dim, class IS>
	IS& operator <<(IS& is, Value<Type, Dim>& value) {
		value.input(is);
		return is;
	}


}