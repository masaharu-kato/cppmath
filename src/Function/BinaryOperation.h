#pragma once
#include "Function.h"

namespace cpm::function {

	template <
		class Method,
		class Input,
		class Output,
		template <class, class> class FirstFunc,
		template <class, class> class SecondFunc,
		template <class, class> class... RestFuncs
	>
	class BinaryOperation : public Function<Input, Output> {
	public:
		BinaryOperation(const FirstFunc&, const SecondFunc&, RestFuncs&&...);

		Output operator()(const Input&) const override;

	private:
		template <class _Input, class _Output>
		using FirstSecondFunc = BinaryOperation<Method, _Input, _Output, FirstFunc, SecondFunc>;

		BinaryOperation<Method, Input, Output, FirstSecondFunc, RestFuncs...> summation;
	};

	template <
		class Method,
		class Input,
		class Output,
		template <class, class> class FirstFunc,
		template <class, class> class SecondFunc
	>
	class BinaryOperation : public Function<Input, Output> {
	public:
		BinaryOperation(const FirstFunc&, const SecondFunc&);

		Output operator()(const Input&) const override;

	private:
		Function<Input, Output> first;
		Function<Input, Output> second;
	};

}