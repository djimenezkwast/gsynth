#pragma once
#include <random>

#include "Note.h"


namespace gsynth
{
	class UniformNoteGenerator
	{
	public:
		// Range specified via low and high arguments is inclusive on both sides
		explicit UniformNoteGenerator(const Note& low, const Note& high);

		Note GenerateNote();

	private:
		std::random_device mRd;
		std::mt19937 mMt;
		std::uniform_int_distribution<int> mDist;
		Note mBaseline;
	};
}