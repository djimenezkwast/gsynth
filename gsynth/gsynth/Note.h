#pragma once
enum class PitchClass
{
	C, Cs, D, Ds, E, F, Fs, G, Gs, A, As, B
};


class Note
{
public:
	Note(PitchClass pitchClass, int octave);
	~Note();

	PitchClass GetPitchClass() const;
	int GetOctave() const;
	double GetFrequency() const;

private:
	double ComputeFrequencyFromA4() const;
	int SemitonalDistanceFromA4() const;

	PitchClass mPitchClass;
	int mOctave;
	double mFrequency;
};

