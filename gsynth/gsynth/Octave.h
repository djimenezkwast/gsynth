#pragma once
#include <cassert>


namespace gsynth
{
	class Octave
	{
	public:
		explicit constexpr Octave(int value)
			: mValue(value)
		{
			assert(value > 0); // No upper bound for now
		};

		int GetValue() const;
	private:
		int mValue;
	};
}