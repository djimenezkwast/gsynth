#pragma once
#include "PitchClass.h"
#include "Octave.h"


namespace gsynth
{
	class Note
	{
	public:
		Note(PitchClass pitchClass, Octave octave) noexcept;

		PitchClass GetPitchClass() const noexcept;
		Octave GetOctave() const noexcept;
		double GetFrequency() const noexcept;

	private:
		double ComputeFrequency() const noexcept;
		int ComputeSemitonalDistanceFromA4() const noexcept;

		PitchClass mPitchClass;
		Octave mOctave;
		double mFrequency;
	};
}