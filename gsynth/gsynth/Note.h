#pragma once
#include "PitchClass.h"
#include "Octave.h"
#include "constexpr_math.h"


namespace gsynth
{
	class Note
	{
	public:
		explicit constexpr Note(PitchClass pitchClass, Octave octave) noexcept
			: mPitchClass(pitchClass)
			, mOctave(octave)
			, mFrequency(ComputeFrequency())
		{}

		constexpr PitchClass GetPitchClass() const noexcept
		{
			return mPitchClass;
		}

		constexpr Octave GetOctave() const noexcept
		{
			return mOctave;
		}

		constexpr double GetFrequency() const noexcept
		{
			return mFrequency;
		}

		void Increment(int numSemitones) noexcept
		{
			const auto x = mPitchClass + numSemitones;
			mPitchClass = PitchClass(x % 12);
			mOctave = Octave(x / 12);
			mFrequency = ComputeFrequency();
		}

	private:
		static constexpr double TWELFTH_ROOT_OF_TWO = 1.0594630943592952646; // https://en.wikipedia.org/wiki/Twelfth_root_of_two

		constexpr double ComputeFrequency() const noexcept
		{
			// 440hz is baseline, so distance is calculated from A in fourth octave
			const auto semitonalDistanceToA4 = mPitchClass - PitchClass::A() + (mOctave - 4) * 12;

			// F_n = F0 * 2^(n/12) is the frequency definition
			// Since b^(n/m) = mth_root(b)^n we can do the following
			// Sources: 
			//	https://pages.mtu.edu/~suits/NoteFreqCalcs.html
			//	https://www.rapidtables.com/math/number/exponent/fractional-exponents.html#simplify

			return 440.0 * ipow(TWELFTH_ROOT_OF_TWO, semitonalDistanceToA4);
		}

		PitchClass mPitchClass;
		Octave mOctave;
		double mFrequency;
	};


	// Return value can be negative if b has a lower frequency than a
	constexpr int SemitonalDistance(const Note& a, const Note& b) noexcept
	{
		const auto pitchClassDifference = a.GetPitchClass() - b.GetPitchClass();
		const auto octaveDifference = a.GetOctave() - b.GetOctave();

		return pitchClassDifference + octaveDifference * 12;
	}

}