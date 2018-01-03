#include "stdafx.h"
#include "ConsoleTrainer.h"

#include <random>
#include <ctime>
#include <string>
#include <iostream>



ConsoleTrainer::ConsoleTrainer()
{
}


ConsoleTrainer::~ConsoleTrainer()
{
}


void ConsoleTrainer::Run()
{
	bool running = true;
	while (running)
	{
		srand(time(NULL));

		Note note = GenerateRandomNote();
		std::cout << PitchClassUtils::GetPitchClassLabel(note.GetPitchClass());
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
	auto randomNum = rand() % static_cast<int>(PitchClass::END);
	return Note(static_cast<PitchClass>(randomNum), 4);
}
