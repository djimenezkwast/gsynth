#pragma once
#include "PitchClass.h"


class Note
{
public:
	Note(PitchClass pitchClass, int octave);
	~Note();

	PitchClass GetPitchClass() const;
	int GetOctave() const;
	double GetFrequency() const;

private:
	double ComputeFrequency() const;
	int ComputeSemitonalDistanceFromA4() const;

	PitchClass mPitchClass;
	int mOctave;
	double mFrequency;
};

