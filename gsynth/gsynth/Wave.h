#pragma once
#include <ostream>
#include <vector>


namespace gsynth
{
	struct Wave
	{
#pragma warning(suppress: 26495) // analysis doesn't seem to recognize that all member variables are in fact initialized
		explicit Wave(unsigned int sampleRate, unsigned int duration)
			: chunkId{ 'R', 'I', 'F', 'F' }
			, chunkSize(sizeof(float) * sampleRate * duration + 36)
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
			, subchunk2Size(sizeof(float) * sampleRate * duration)
			, data(sampleRate * duration)
		{}

#pragma warning( push )
#pragma warning( disable : 26490) // reinterpret cast
#pragma warning( disable : 26499) // some lifetime tracking bs
		void WriteToStream(std::ostream& os)
		{
			// write first 44 bytes (all members except data) directly
			os.write(reinterpret_cast<const char*>(this), 44);

			// we have to write data separately since std::vector has some internals we don't want to write
			os.write(reinterpret_cast<const char*>(&data[0]), sizeof(float) * data.size());
		}
#pragma warning( pop ) 

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
		std::vector<float> data;
	};
}