#include <array>
#include <tuple>
#include <utility>
#include <iostream>

template <size_t I>
struct Value {
public:
	double value;

	Value(double value)
		: value(value) {}

	void show() const {
		std::cout << "[" << I << "] " << value << std::endl;
	};

	Value operator +() const { return +value; }
	Value operator -() const { return -value; }

	Value operator +(Value v) const { return value + v.value; }
	Value operator -(Value v) const { return value - v.value; }

};

template <class T>
struct _void {
	_void(std::initializer_list<T>) {}
};


template <size_t... I>
struct Vector : public Value<I>... {

	Vector(Value<I>... vals)
		: Value<I>(vals)... {}

	void show() const {
		_void{(Value<I>::show(), 0)...};
	}

	template <class _UnaryOperator>
	Vector unary_operate() const {
		return {_UnaryOperator::call(Value<I>(*this))...};
	}

	Vector operator +() const {
		return unary_operate<_OpPlus>();
	}

	Vector operator -() const {
		return unary_operate<_OpMinus>();
	}


	template <class _BinaryOperator>
	Vector binary_operate(const Vector& vec) const {
		return {_BinaryOperator::call(Value<I>(*this), Value<I>(vec))...};
	}

	Vector operator +(const Vector& vec) const {
		return binary_operate<_OpAdd>(vec);
	}

	Vector operator -(const Vector& vec) const {
		return binary_operate<_OpSub>(vec);
	}


private:

	struct _OpPlus  { template <class _T> static _T call(_T v) { return +v; } };
	struct _OpMinus { template <class _T> static _T call(_T v) { return -v; } };

	struct _OpAdd { template <class _T> static _T call(_T v1, _T v2) { return v1 + v2; } };
	struct _OpSub { template <class _T> static _T call(_T v1, _T v2) { return v1 - v2; } };

};



template <size_t... I>
struct _ISeqHelper {
	template <template <size_t...> class _Target> using apply_to = _Target<I...>;
	template <size_t _I> using push_back = _ISeqHelper<I..., _I>;
};

template <size_t FIRST, size_t LAST>
struct _ISeq {
	using Type = typename _ISeq<FIRST, LAST-1>::Type::template push_back<LAST>;
};

template <size_t FIRST>
struct _ISeq<FIRST, FIRST> {
	using Type = _ISeqHelper<FIRST>;
};


template <template <size_t...> class _Target, size_t FIRST, size_t LAST>
using ApplyISeq = typename _ISeq<FIRST, LAST>::Type::template apply_to<_Target>;


template <size_t N>
using VectorND = ApplyISeq<Vector, 1, N>;


template <size_t... I>
void test(std::index_sequence<I...>) {
	(void)std::initializer_list<int>{
		(void(std::cout << I << std::endl), 0)...
	};
}


//
//int main(){
//
//	VectorND<4> vec1( 12.5, -21.3, 35.7, 42.6);
//	VectorND<4> vec2(  6.4,   8.5,- 2.5, 10.3);
// 
//	auto vec3 = - vec1 + vec2;
//
//	vec3.show();
//
//	return 0;
//}
