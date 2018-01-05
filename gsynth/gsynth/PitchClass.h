#pragma once
#include <cassert>
#include <map>


namespace gsynth
{
	class PitchClass
	{
	public:
		explicit constexpr PitchClass(int value) noexcept
			: mValue(value) 
		{
			assert(value >= 0 && value <= 11);
		};

		// Set of valid pitch classes
		static constexpr PitchClass C()		noexcept { return PitchClass(0); }
		static constexpr PitchClass Cs()	noexcept { return PitchClass(1); }
		static constexpr PitchClass D()		noexcept { return PitchClass(2); }
		static constexpr PitchClass Ds()	noexcept { return PitchClass(3); }
		static constexpr PitchClass E()		noexcept { return PitchClass(4); }
		static constexpr PitchClass F()		noexcept { return PitchClass(5); }
		static constexpr PitchClass Fs()	noexcept { return PitchClass(6); }
		static constexpr PitchClass G()		noexcept { return PitchClass(7); }
		static constexpr PitchClass Gs()	noexcept { return PitchClass(8); }
		static constexpr PitchClass A()		noexcept { return PitchClass(9); }
		static constexpr PitchClass As()	noexcept { return PitchClass(10); }
		static constexpr PitchClass B()		noexcept { return PitchClass(11); }

		int GetValue() const noexcept;
	private:
		int mValue;
	};


	static const std::map<int, std::string> PITCH_CLASS_TO_LABEL_MAP =
	{ { 0, "C" },{ 1, "C#" },{ 2, "D" },{ 3, "D#" },{ 4, "E" },{ 5, "F" },{ 6, "F#" },{ 7, "G" },{ 8, "G#" },{ 9, "A" },{ 10, "A#" },{ 11, "B" } };

	static const std::map<std::string, int> LABEL_TO_PITCH_CLASS_MAP =
	{ { "C", 0 },{ "C#", 1 },{ "D", 2 },{ "D#", 3 },{ "E", 4 },{ "F", 5 },{ "F#", 6 },{ "G", 7 },{ "G#", 8 },{ "A", 9 },{ "A#", 10 },{ "B", 11 } };


	// Does not perform error handling; assumes a valid conversion is available (see PitchClass.cpp)
	std::string GetPitchClassLabel(PitchClass pitchClass);
	// Does not perform error handling; assumes a valid conversion is available (see PitchClass.cpp)
	PitchClass GetPitchClassFromLabel(const std::string& label);
}