// Score.h
// Header for Score class
//
// Jayden Grant - 2016

#ifndef SCORE_H
#define SCORE_H

#include <stdlib.h>
#include <GL/glut.h>
#include <cmath>
#include <string>

class Score
{

public:
	/// Default constructor
	Score();

	///Resets the score and its values.
	void reset();

	/// Starts the timer for the score
	void start();

	/// Finished the timer and sets the score
	int finish();

	/// Increments the current score multiplier
	void multiply();

	/// Adds to the current score multiplier
	void multiply(int multi);

	/// Returns the time as a formated string
	std::string getTimeString();

private:
	int finalScore;
	int multiplier;

	int startTime;
	int finalTime;

	bool started;
	bool finished;
	bool ready;

	// Calculates the current score
	int calcScore(int currentTime);

	// Returns the time since start
	int getElapsed();


};

#endif