#pragma once
namespace math::function {

	template <class Input, class Output>
	class Function {
	public:
		virtual Output operator()(const Input&) const = 0;
	};

}