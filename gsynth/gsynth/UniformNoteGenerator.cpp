#include "stdafx.h"
#include "UniformNoteGenerator.h"


namespace gsynth
{
	UniformNoteGenerator::UniformNoteGenerator(const Note& low, const Note& high)
		: mRd()
		, mMt(mRd())
		, mDist(0, abs(SemitonalDistance(low, high)))
		, mBaseline(low)
	{
		if (low.GetFrequency() > high.GetFrequency())
		{
			throw std::invalid_argument("high must have a higher frequency than low");
		}
	}


	Note UniformNoteGenerator::GenerateNote()
	{
		// generate random int in specified range
		const auto randomNumber = mDist(mMt);

		// copy construct baseline and increment
		auto note = mBaseline;
		note.Increment(randomNumber);
		return note;
	}
}