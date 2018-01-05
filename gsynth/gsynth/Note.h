#pragma once
#include "PitchClass.h"
#include "Octave.h"


namespace gsynth
{
	class Note
	{
	public:
		Note(PitchClass pitchClass, Octave octave);

		PitchClass GetPitchClass() const;
		Octave GetOctave() const;
		double GetFrequency() const;

	private:
		double ComputeFrequency() const;
		int ComputeSemitonalDistanceFromA4() const;

		PitchClass mPitchClass;
		Octave mOctave;
		double mFrequency;
	};
}