#pragma once
#include "Function.h"

namespace cpm::function {

	template <
		class Method,
		class Input,
		class Output,
		template <class, class> class TargetFunc
	>
	class UnaryOperation : public Function<Input, Output> {
	public:
		UnaryOperation(const TargetFunc&) noexcept;

		Output operator()(const Input&) const override;

	private:
		TargetFunc function;
	};

}