#pragma once
#include "Function.h"

namespace cpm::function {

	template <class Input, class Output>
	class Variable : public Function<Input, Output> {
	public:
		Variable() noexcept;

		Output operator()(const Input&) const override noexcept;
	};

}