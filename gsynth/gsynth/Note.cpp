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
	mFrequency = ComputeFrequencyFromA4();
}


Note::~Note()
{
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


double Note::ComputeFrequencyFromA4() const
{
	//F_n = F0 * 2^(n/12)
	double semitonalDistance = SemitonalDistanceFromA4();
	return 440.0 * pow(2, semitonalDistance / 12);
}


int Note::SemitonalDistanceFromA4() const
{
	// 440hz is baseline, so distance is calculated from A in fourth octave
	auto pcDistance = static_cast<int>(mPitchClass) - static_cast<int>(PitchClass::A);
	auto octaveDistance = mOctave - 4;

	return pcDistance + octaveDistance * 12;
}
