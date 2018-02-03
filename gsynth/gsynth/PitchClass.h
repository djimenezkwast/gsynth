#pragma once
#include <array>
#include <string>
#include <string_view>


namespace gsynth
{
	class PitchClass
	{
	public:
		explicit constexpr PitchClass(int value)
			: mValue(value)
		{
			if (value < 0 || value > 11)
			{
				throw std::invalid_argument("invalid PitchClass value passed to ctor");
			}
		}

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

		constexpr int GetValue() const noexcept
		{
			return mValue;
		}

	private:
		int mValue;
	};


	class PitchClassLabel
	{
	public:
		template<std::size_t N>
		constexpr PitchClassLabel(const char(&content)[N]) noexcept
			: mContent(content)
			, mSize(N - 1)
		{}

		constexpr const char* const GetContent() const noexcept
		{
			return mContent;
		}

		constexpr std::size_t GetSize() const noexcept
		{
			return mSize;
		}

	private:
		const char* mContent;
		const std::size_t mSize;
	};

	
	constexpr std::array<PitchClassLabel, 12> PITCHCLASS_LABELS = {
		PitchClassLabel("C"),
		PitchClassLabel("C#"),
		PitchClassLabel("D"),
		PitchClassLabel("D#"),
		PitchClassLabel("E"),
		PitchClassLabel("F"),
		PitchClassLabel("F#"),
		PitchClassLabel("G"),
		PitchClassLabel("G#"),
		PitchClassLabel("A"),
		PitchClassLabel("A#"),
		PitchClassLabel("B"),
	};

	
	constexpr std::string_view GetPitchClassLabel(const PitchClass& pitchClass)
	{
		const auto& label = PITCHCLASS_LABELS.at(pitchClass.GetValue());
		return std::string_view(label.GetContent(), label.GetSize());
	}


	constexpr PitchClass PitchClassFromLabel(const char* label)
	{
		// no constexpr std::find variation as of yet, so using manual search
		int index = -1;
		for (auto& pitchClassLabel : PITCHCLASS_LABELS)
		{
			++index;
			if (pitchClassLabel.GetContent() == label)
			{
				break;
			}
		}

		if (index < 0)
		{
			// cannot find label
			throw std::invalid_argument("no PitchClass exists for the specified label");
		}

		return PitchClass(index);
	}


	PitchClass PitchClassFromLabel(const std::string& label);
}