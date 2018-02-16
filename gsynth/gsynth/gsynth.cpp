// gsynth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <sstream>
#include <Windows.h>

#include "karplus_strong.h"


int main()
{
	using namespace gsynth;

	constexpr unsigned int SAMPLE_RATE = 44100;
	constexpr unsigned int DURATION = 5;

	// open guitar notes: E2 A2 D3 G3 B3 E4

	const auto note = Note(PitchClass::E(), Octave(2));
	const auto wave = GenerateWaveFromNote(note, SAMPLE_RATE, DURATION);

	std::stringstream stream;
	wave->WriteToStream(stream);

	PlaySound(stream.str().c_str(), NULL, SND_MEMORY);
}