#pragma once
#include "_declares.h"

namespace cpm {

	template <Dimension N_DIM>
	struct SingleDimSet {
		template <size_t _I>
		using Elms = SingleDim<_I>;

		static constexpr Dimension Size = N_DIM;
	};

	template <Dimension N_ROW, Dimension N_COL>
	struct DoubleDimSet {
		template <size_t _I>
		using Elms = DoubleDim<_I / N_ROW, _I % N_ROW>;

		static constexpr Dimension Size = N_ROW * N_COL;
	};

}