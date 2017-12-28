#pragma once
#include <array>


enum class PitchClass
{
	C, Cs, D, Ds, E, F, Fs, G, Gs, A, As, B, END
};


const std::array<std::string, static_cast<int>(PitchClass::END)> PITCH_CLASS_LABELS
{
	"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
};


namespace PitchClassUtils
{
	std::string GetPitchClassLabel(PitchClass pitchClass);
	PitchClass GetPitchClassFromLabel(const std::string& label);
}