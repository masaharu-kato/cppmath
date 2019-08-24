#pragma once
#include "_declares.h"

namespace math {

	template <class NumType, class Kind>
	class ValueType {
	public:

	private:
		NumType value;

	public:
		ValueType() noexcept = default;
		ValueType(NumType value) noexcept : value(value) {}

		template <class _NumType>
		ValueType(ValueType<_NumType, Kind> v) : value(v.value) {}

		explicit operator NumType&() noexcept { return value; }
		explicit operator NumType() const noexcept { return value; }
		
		ValueType operator +() const noexcept { return +(NumType)value; }
		ValueType operator -() const noexcept { return -(NumType)value; }

		ValueType operator +(ValueType v) const noexcept { return value + (NumType)v; }
		ValueType operator -(ValueType v) const noexcept { return value - (NumType)v; }
		ValueType operator *(ValueType v) const noexcept { return value * (NumType)v; }
		ValueType operator /(ValueType v) const noexcept { return value / (NumType)v; }
		
		template <class _Kind> void operator +(ValueType<NumType, _Kind>) const = delete;
		template <class _Kind> void operator -(ValueType<NumType, _Kind>) const = delete;
		template <class _Kind> void operator *(ValueType<NumType, _Kind>) const = delete;
		template <class _Kind> void operator /(ValueType<NumType, _Kind>) const = delete;

		ValueType& operator +=(ValueType v) noexcept { value += (NumType)v; return *this; }
		ValueType& operator -=(ValueType v) noexcept { value -= (NumType)v; return *this; }
		ValueType& operator *=(ValueType v) noexcept { value *= (NumType)v; return *this; }
		ValueType& operator /=(ValueType v) noexcept { value /= (NumType)v; return *this; }

		template <class _Kind> void operator +=(ValueType<NumType, _Kind>) = delete;
		template <class _Kind> void operator -=(ValueType<NumType, _Kind>) = delete;
		template <class _Kind> void operator *=(ValueType<NumType, _Kind>) = delete;
		template <class _Kind> void operator /=(ValueType<NumType, _Kind>) = delete;

		ValueType& operator ++() noexcept { ++value; return *this; }
		ValueType& operator --() noexcept { --value; return *this; }
		ValueType operator ++(int) noexcept { ValueType current = value++; return current; }
		ValueType operator --(int) noexcept { ValueType current = value--; return current; }
		
		bool operator ==(ValueType v) const noexcept { return value == (NumType)v; }
		bool operator !=(ValueType v) const noexcept { return value != (NumType)v; }
		bool operator < (ValueType v) const noexcept { return value <  (NumType)v; }
		bool operator > (ValueType v) const noexcept { return value >  (NumType)v; }
		bool operator <=(ValueType v) const noexcept { return value <= (NumType)v; }
		bool operator >=(ValueType v) const noexcept { return value >= (NumType)v; }
		
		template <class _Kind> bool operator ==(ValueType<NumType, _Kind>) const = delete;
		template <class _Kind> bool operator !=(ValueType<NumType, _Kind>) const = delete;
		template <class _Kind> bool operator < (ValueType<NumType, _Kind>) const = delete;
		template <class _Kind> bool operator > (ValueType<NumType, _Kind>) const = delete;
		template <class _Kind> bool operator <=(ValueType<NumType, _Kind>) const = delete;
		template <class _Kind> bool operator >=(ValueType<NumType, _Kind>) const = delete;


		template <class OS>
		void output(OS& os) const {
			os << value;
		}

		template <class IS>
		void input(IS& is) {
			is >> value;
		}

	};

	template <class NumType, class Kind, class OS>
	OS& operator >>(OS& os, const ValueType<NumType, Kind>& value) {
		value.output(os);
		return os;
	}


	template <class NumType, class Kind, class IS>
	IS& operator <<(IS& is, ValueType<NumType, Kind>& value) {
		value.input(is);
		return is;
	}


}