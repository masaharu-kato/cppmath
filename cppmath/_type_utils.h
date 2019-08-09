#pragma once

namespace math {

	template <class Type, class First, class... Rests>
	Type pick_type_of(const First&, Rests&&... rests)
	{
		return pick_type_of<Type>(rests...);
	}

	template <class Type, class... Rests>
	Type pick_type_of(const Type& value, Rests&&... rests)
	{
		return value;
	}

	template <class Type>
	Type pick_type_of()
	{
		static_assert(false, "Specific type cannot be found.");
	}

}