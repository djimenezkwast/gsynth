#pragma once

#include "Note.h"


class ConsoleTrainer
{
public:
	ConsoleTrainer();

	void Run();

private:
	Note GenerateRandomNote() const;
};

