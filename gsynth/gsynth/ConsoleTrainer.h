#pragma once

#include "Note.h"


namespace gsynth
{
	class ConsoleTrainer
	{
	public:
		void Run();

	private:
		Note GenerateRandomNote() const;
	};
}