#pragma once
#include <stdexcept>


namespace gsynth
{
	class Octave
	{
	public:
		explicit constexpr Octave(int value)
			: mValue(value)
		{
			if (value < 0 || value > 8)
			{
				throw std::invalid_argument("invalid Octave value passed to ctor");
			}
		}

		constexpr operator int() const noexcept
		{
			return mValue;
		}

	private:
		int mValue;
	};
}