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

/// Score: Determines the Score using time taken and multipliers
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
	void multiply(double multi);

	/// Returns the final score or -1 if not finished.
	int Score::getFinalScore();

	/// Returns the time as a formated string
	std::string getTimeString();


private:
	long long finalScore; 
	double multiplier;

	int startTime;	/// Start time of the current score
	int finalTime;	/// Finish time of the current score

	bool started;	
	bool finished;
	bool ready;

	/// Calculates the current score
	int calcScore(int currentTime);

	/// Returns the time since start
	int getElapsed();


};

#endif