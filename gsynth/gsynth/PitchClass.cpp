#include "stdafx.h"
#include "PitchClass.h"


namespace gsynth
{
	int PitchClass::GetValue() const
	{
		return mValue;
	}


	std::string GetPitchClassLabel(PitchClass pitchClass)
	{
		const auto it = PITCH_CLASS_TO_LABEL_MAP.find(pitchClass.GetValue());
		assert(it != PITCH_CLASS_TO_LABEL_MAP.end());
		return it->second; 
	}


	PitchClass GetPitchClassFromLabel(const std::string& label)
	{
		const auto it = LABEL_TO_PITCH_CLASS_MAP.find(label);
		assert(it != LABEL_TO_PITCH_CLASS_MAP.end());
		return PitchClass(it->second);	
	}
}