// SaveScore.h
// Header for SaveScore class
//
// Jayden Grant - 2016

#ifndef SAVESCORE_H
#define SAVESCORE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

/// SaveScore: Handles file loading and saving of Scores
class SaveScore
{
public:
	/// Loads score from given file
	SaveScore(std::string fileName);

	/// Adds provided score and sorts the scores
	void addScore(int score);

	/// Returns the scores sorted
	std::vector<int> getScores();

	/// Add scores from given file
	void addScores(std::string fileName);

	/// Clears current scores and Loads new scores from given file
	void loadScores(std::string fileName);

	/// Saves top 20 scores to given file
	void saveScores(std::string fileName);

private:

	std::vector<int> scores;	/// Holds scores		

	void sort();				/// Sorts the scores vector
};

#endif