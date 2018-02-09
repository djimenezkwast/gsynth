#pragma once
#include <array>


namespace gsynth
{
	template<std::size_t BUFFER_SIZE>
	struct Wave
	{
#pragma warning(suppress: 26495) // analysis doesn't seem to recognize that all member variables are in fact initialized
		explicit Wave(unsigned int sampleRate, const std::array<float, BUFFER_SIZE> dataBuffer) noexcept
			: chunkId{ 'R', 'I', 'F', 'F' }
			, chunkSize(sizeof(float) * BUFFER_SIZE + 36)
			, format{ 'W', 'A', 'V', 'E' }
			, subchunk1Id{ 'f', 'm', 't', ' ' }
			, subchunk1Size(16)
			, audioFormat(3)
			, numChannels(1)
			, sampleRate(sampleRate)
			, byteRate(sampleRate * numChannels * sizeof(float))
			, blockAlign(numChannels * sizeof(float))
			, bitsPerSample(sizeof(float) * 8)
			, subchunk2Id{ 'd', 'a', 't', 'a' }
			, subchunk2Size(sizeof(float) * BUFFER_SIZE)
			, data(dataBuffer) // copy data
		{}

		// As per http://soundfile.sapp.org/doc/WaveFormat/
		// "RIFF" chunk descriptor

		const char chunkId[4];
		const unsigned int chunkSize;
		const char format[4]; 

		// "fmt" subchunk

		const char subchunk1Id[4];
		const unsigned int subchunk1Size;
		const unsigned short audioFormat;
		const unsigned short numChannels;
		const unsigned int sampleRate;
		const unsigned int byteRate;
		const unsigned short blockAlign;
		const unsigned short bitsPerSample;

		// "data" subchunk

		const char subchunk2Id[4];
		const unsigned int subchunk2Size;
		const std::array<float, BUFFER_SIZE> data;
	};
}