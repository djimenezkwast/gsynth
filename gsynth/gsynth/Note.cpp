#include "stdafx.h"
#include "Note.h"

#include <cmath>


namespace gsynth
{
	Note::Note(PitchClass pitchClass, Octave octave)
		: mPitchClass(pitchClass)
		, mOctave(octave)
		, mFrequency(0.0)
	{
		mFrequency = ComputeFrequency();
	}


	PitchClass Note::GetPitchClass() const
	{
		return mPitchClass;
	}


	Octave Note::GetOctave() const
	{
		return mOctave;
	}


	double Note::GetFrequency() const
	{
		return mFrequency;
	}


	double Note::ComputeFrequency() const
	{
		const double semitonalDistance = ComputeSemitonalDistanceFromA4();

		//F_n = F0 * 2^(n/12)
		return 440.0 * pow(2, semitonalDistance / 12);
	}


	int Note::ComputeSemitonalDistanceFromA4() const
	{
		// 440hz is baseline, so distance is calculated from A in fourth octave
		const auto pitchClassDistance = mPitchClass.GetValue() - PitchClass::A().GetValue();
		const auto octaveDistance = mOctave.GetValue() - 4;

		return pitchClassDistance + octaveDistance * 12;
	}
}