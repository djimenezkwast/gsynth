#pragma once
#include "PitchClass.h"
#include "Octave.h"
#include "constexpr_math.h"


namespace gsynth
{
	class Note
	{
	public:
		explicit constexpr Note::Note(PitchClass pitchClass, Octave octave) noexcept
			: mPitchClass(pitchClass)
			, mOctave(octave)
			, mFrequency(0.0)
		{
			mFrequency = ComputeFrequency();
		}

		constexpr PitchClass Note::GetPitchClass() const noexcept
		{
			return mPitchClass;
		}

		constexpr Octave Note::GetOctave() const noexcept
		{
			return mOctave;
		}

		constexpr double Note::GetFrequency() const noexcept
		{
			return mFrequency;
		}

	private:
		static constexpr double TWELFTH_ROOT_OF_TWO = 1.0594630943592952646; // https://en.wikipedia.org/wiki/Twelfth_root_of_two

		constexpr double Note::ComputeFrequency() const noexcept
		{
			const auto semitonalDistance = ComputeSemitonalDistanceFromA4();

			// Sources: 
			//	https://pages.mtu.edu/~suits/NoteFreqCalcs.html
			//	https://www.rapidtables.com/math/number/exponent/fractional-exponents.html#simplify

			// F_n = F0 * 2^(n/12) is the frequency definition
			// Since b^(n/m) = mth_root(b)^n we can do the following

			return 440.0 * ipow(TWELFTH_ROOT_OF_TWO, semitonalDistance);
		}

		constexpr int Note::ComputeSemitonalDistanceFromA4() const noexcept
		{
			// 440hz is baseline, so distance is calculated from A in fourth octave

			const auto pitchClassDistance = mPitchClass.GetValue() - PitchClass::A().GetValue();
			const auto octaveDistance = mOctave.GetValue() - 4;

			return pitchClassDistance + octaveDistance * 12;
		}

		PitchClass mPitchClass;
		Octave mOctave;
		double mFrequency;
	};


}