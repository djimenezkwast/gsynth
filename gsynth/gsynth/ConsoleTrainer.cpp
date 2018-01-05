#include "stdafx.h"
#include "ConsoleTrainer.h"

#include <random>
#include <ctime>
#include <string>
#include <iostream>


namespace gsynth
{
	void ConsoleTrainer::Run()
	{
		bool running = true;
		while (running)
		{
			srand(time(NULL));

			const Note note = GenerateRandomNote();
			std::cout << GetPitchClassLabel(note.GetPitchClass());
			//Generate random note 
			//Print (for now)

			std::string userInput;
			std::cin >> userInput;
			//Read User input
			//Provide feedback

			//Loop or terminate
			running = false;
		}
	}


	Note ConsoleTrainer::GenerateRandomNote() const
	{
		const auto randomNum = rand() % 12;
		return Note(PitchClass(randomNum), Octave(4));
	}
}