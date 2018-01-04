#pragma once

#include "Note.h"


namespace gsynth
{
	class ConsoleTrainer
	{
	public:
		ConsoleTrainer();

		void Run();

	private:
		Note GenerateRandomNote() const;
	};
}