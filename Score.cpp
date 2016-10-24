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
	multiplier = 1.0;
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
	multiplier += 0.15;
}

void Score::multiply(double multi)
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
	int time = 0;
	if (finished)
		time = finalTime;
	else if (started)
		time = getElapsed();

	int cs = (time % 1000) / 10;
	int seconds = time / 1000;
	int minutes = seconds / 60;
		
	seconds %= 60;

	str = std::to_string(minutes) + ":";

	if (seconds < 10)
		str += "0";
	str += std::to_string(seconds) + ".";

	if (cs < 10)
		str += "0";
	str += std::to_string(cs);

	return str;
}

int Score::calcScore(int currentTime)
{
	int tenths = currentTime;
	return (100000 * (fmax(0, 300000 - currentTime)/4000) * multiplier);
}

int Score::getElapsed()
{
	return glutGet(GLUT_ELAPSED_TIME) - startTime;
}