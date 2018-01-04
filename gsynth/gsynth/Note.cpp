#include "stdafx.h"
#include "Note.h"

#include <cassert>
#include <cmath>


Note::Note(PitchClass pitchClass, int octave)
	: mPitchClass(pitchClass)
	, mOctave(octave)
	, mFrequency(0.0)
{
	assert(octave > -1 && "octave is negative");
	mFrequency = ComputeFrequency();
}


PitchClass Note::GetPitchClass() const
{
	return mPitchClass;
}


int Note::GetOctave() const
{
	return mOctave;
}


double Note::GetFrequency() const
{
	return mFrequency;
}


double Note::ComputeFrequency() const
{
	//F_n = F0 * 2^(n/12)
	const double semitonalDistance = ComputeSemitonalDistanceFromA4();
	return 440.0 * pow(2, semitonalDistance / 12);
}


int Note::ComputeSemitonalDistanceFromA4() const
{
	// 440hz is baseline, so distance is calculated from A in fourth octave
	const auto pitchClassDistance = static_cast<int>(mPitchClass) - static_cast<int>(PitchClass::A);
	const auto octaveDistance = mOctave - 4;

	return pitchClassDistance + octaveDistance * 12;
}
