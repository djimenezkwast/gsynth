#pragma once
#include <memory>

#include "Wave.h"
#include "Note.h"


namespace gsynth
{
	std::unique_ptr<Wave> GenerateWaveFromNote(const Note& note, unsigned int sampleRate, unsigned int duration);	
}