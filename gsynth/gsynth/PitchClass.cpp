#include "stdafx.h"
#include "PitchClass.h"


namespace gsynth
{
	PitchClass PitchClassFromLabel(const std::string& label)
	{
		const auto compare = [&label](const PitchClassLabel& pcl) { return pcl.GetContent() == label; };
		const auto result = std::find_if(PITCHCLASS_LABELS.begin(), PITCHCLASS_LABELS.end(), compare);

		if (result == PITCHCLASS_LABELS.end())
		{
			// cannot find label
			throw std::invalid_argument("no PitchClass exists for the specified label");
		}

		const auto distance = std::distance(PITCHCLASS_LABELS.begin(), result);
		return PitchClass(distance);
	}
}