#include "stdafx.h"
#include "PitchClass.h"

#include <cassert>
#include <algorithm>


namespace PitchClassUtils
{
	std::string GetPitchClassLabel(PitchClass pitchClass)
	{
		assert(pitchClass != PitchClass::END && "specified pitch class has no label");
		return PITCH_CLASS_LABELS[static_cast<int>(pitchClass)];
	}


	PitchClass GetPitchClassFromLabel(const std::string & label)
	{
		auto it = std::find(PITCH_CLASS_LABELS.begin(), PITCH_CLASS_LABELS.end(), label);

		if (it == PITCH_CLASS_LABELS.end())
		{
			return PitchClass::END;
		}
		else 
		{
			auto distance = std::distance(PITCH_CLASS_LABELS.begin(), it);
			return static_cast<PitchClass>(distance);
		}
	}
}