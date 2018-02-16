#include "stdafx.h"
#include "karplus_strong.h"

#include <random>


namespace gsynth
{
	void SeedDelayLine(std::vector<float>& delayLine, int delayLineLength)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		const std::uniform_real_distribution<float> dist(0.0f, 1.0f);

		delayLine.reserve(delayLineLength);
		for (int i = 0; i < delayLineLength; ++i)
		{
			delayLine.push_back(dist(mt));
		}
	}


	std::unique_ptr<Wave> GenerateWaveFromNote(const Note& note, unsigned int sampleRate, unsigned int duration)
	{
		const double delay = 0.5f + sampleRate / note.GetFrequency(); // +0.5 because of asymmetric averaging filter
		const int delayLineLength = static_cast<int>(std::floor(delay));

		// Allocate and seed delayLine buffer with noise
		std::vector<float> delayLine;
		SeedDelayLine(delayLine, delayLineLength);

		// Allocate output buffer (part of Wave object)
		auto wave = std::make_unique<Wave>(sampleRate, duration);
		auto& dataBuffer = wave->data;

		// filter the generated random noise by repeatedly filtering until output buffer is filled
		const float delta = static_cast<float>(delay) - delayLineLength;
		const float C = (-delta + 1.0f) / (delta + 1.0f);

		unsigned int i = 0;
		float previousLowpass = 0.0f;
		const auto func = [&i, &previousLowpass, C, &delayLine, &dataBuffer](float& sample) {
			const unsigned int currentIndex = i % delayLine.size();
			const unsigned int nextindex = (i + 1) % delayLine.size();

			// Average current and next samples in delayline as a lowpass filter
			const float lowpass = (delayLine[currentIndex] + delayLine[nextindex]) / 2.0f;

			// Allpass filter to account for inaccurate frequency due to delayLineLength rounding
			const int previousI = i == 0 ? 0 : i - 1;
			const float allpass = C * lowpass + previousLowpass - C * dataBuffer[previousI];

			previousLowpass = lowpass;
			delayLine.at(currentIndex) = allpass;
			sample = allpass;
			++i;
		};

		std::for_each(dataBuffer.begin(), dataBuffer.end(), func);
		return wave;
	}

	
}