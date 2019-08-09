#pragma once
#include "_declares.h"

namespace math {

	template <class _NumType, Dimension I_ROW, Dimension I_COL>
	class Value {
	public:
		using NumType = _NumType;

	private:
		NumType value;

	public:
		Value() noexcept = default;
		Value(NumType value) noexcept : value(value) {}

		explicit operator NumType&() noexcept { return value; }
		explicit operator NumType() const noexcept { return value; }
		
		Value operator +() const noexcept { return +(NumType)value; }
		Value operator -() const noexcept { return -(NumType)value; }

		Value operator +(Value v) const noexcept { return value + (NumType)v; }
		Value operator -(Value v) const noexcept { return value - (NumType)v; }
		Value operator *(Value v) const noexcept { return value * (NumType)v; }
		Value operator /(Value v) const noexcept { return value / (NumType)v; }
		Value operator %(Value v) const noexcept { return value % (NumType)v; }

		Value& operator +=(Value v) noexcept { value += (NumType)v; return *this; }
		Value& operator -=(Value v) noexcept { value -= (NumType)v; return *this; }
		Value& operator *=(Value v) noexcept { value *= (NumType)v; return *this; }
		Value& operator /=(Value v) noexcept { value /= (NumType)v; return *this; }
		Value& operator %=(Value v) noexcept { value %= (NumType)v; return *this; }

		Value& operator ++() noexcept { ++value; return *this; }
		Value& operator --() noexcept { --value; return *this; }
		Value operator ++(int) noexcept { Value current = value++; return current; }
		Value operator --(int) noexcept { Value current = value--; return current; }
		
		bool operator ==(Value v) const noexcept { return value == (NumType)v; }
		bool operator !=(Value v) const noexcept { return value != (NumType)v; }
		bool operator < (Value v) const noexcept { return value <  (NumType)v; }
		bool operator > (Value v) const noexcept { return value >  (NumType)v; }
		bool operator <=(Value v) const noexcept { return value <= (NumType)v; }
		bool operator >=(Value v) const noexcept { return value >= (NumType)v; }


		template <class OS>
		void output(OS& os) const {
			os << value;
		}

		template <class IS>
		void input(IS& is) {
			is >> value;
		}

	};

	template <class NumType, Dimension ROW, Dimension COL, class OS>
	OS& operator >>(OS& os, const Value<NumType, ROW, COL>& value) {
		value.output(os);
		return os;
	}


	template <class NumType, Dimension ROW, Dimension COL, class IS>
	IS& operator <<(IS& is, Value<NumType, ROW, COL>& value) {
		value.input(is);
		return is;
	}


}