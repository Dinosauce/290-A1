// Score.cpp
//
// Used to count the time since the player started.
// Used to calculate and add the the players current mulitplier and score.
//
// Jayden Grant - 2016

#include "Score.h"

Score::Score()
{
	reset();
}

void Score::reset()
{
	finalScore = 0;
	multiplier = 0;
	startTime = -1;
	finalTime = 0;

	started = false;
	finished = false;
	ready = true;
}

void Score::start()
{
	if (!started)
	{
		startTime = glutGet(GLUT_ELAPSED_TIME);
		started = true;
	}
}

int Score::finish()
{
	if (finished)
	{
		return finalScore;
	}
	else if (started)
	{
		finalTime = getElapsed();
		finalScore = calcScore(finalTime);
		finished = true;
		return finalScore;
	}
	else
	{
		return -1;
	}
}

void Score::multiply()
{
	multiplier++;
}

void Score::multiply(int multi)
{
	multiplier += multi;
}

int Score::getFinalScore()
{
	if (finished)
	{
		return finalScore;
	}
	else
	{
		return -1;
	}
}

std::string Score::getTimeString()
{
	std::string str = "";
	if (started)
	{
		int seconds = getElapsed() / 1000;
		int minutes = seconds / 60;
		seconds %= 60;

		str = std::to_string(minutes) + ":";

		if (seconds < 10)
			str += "0";

		str += std::to_string(seconds);
		str += "." + std::to_string(getElapsed() % 1000);
	}
	else
	{
		str = "0:00.000";
	}
	return str;
}

int Score::calcScore(int currentTime)
{
	int tenths = currentTime / 100;
	return (1000000 * pow(tenths, -1)) * multiplier;
}

int Score::getElapsed()
{
	return glutGet(GLUT_ELAPSED_TIME) - startTime;
}