#pragma once
#include <cassert>


namespace gsynth
{
	class Octave
	{
	public:
		explicit constexpr Octave(int value) noexcept
			: mValue(value)
		{
			assert(value > 0); // No upper bound for now
		};

		int GetValue() const noexcept;
	private:
		int mValue;
	};
}