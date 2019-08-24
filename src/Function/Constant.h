#pragma once
#include "Function.h"

namespace cpm::function {

	template <class Input, class Output>
	class Constant : public Function<Input, Output> {
	public:
		Constant(const Output&) noexcept;

		Output operator()(const Input&) const override noexcept;

	private:
		Output constant;
	};

}