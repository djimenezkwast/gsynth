#include "stdafx.h"
#include "ConsoleTrainer.h"

#include <random>
#include <ctime>


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
		//Generate random note 
		//Print (for now)

		//Read User input
		//Provide feedback

		//Loop or terminate
	}
}

Note ConsoleTrainer::GenerateRandomNote() const
{
	auto randomNum = rand() % static_cast<int>(PitchClass::END);
	return Note(static_cast<PitchClass>(randomNum), 4);
}
