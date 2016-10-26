// SaveScore.cpp
//
//
// Jayden Grant - 2016

#include "SaveScore.h"

SaveScore::SaveScore(std::string fileName)
{
	loadScores(fileName);
}

void SaveScore::addScore(int score)
{
	scores.push_back(score);
	sort();
}

std::vector<int> SaveScore::getScores()
{
	return scores;
}

void SaveScore::addScores(std::string fileName)
{
	std::ifstream file(fileName.c_str());

	char line[13];

	if (file.good())
	{
		while (!file.eof())
		{
			file.getline(line, 12);
			scores.push_back(atoi(line));
		}
	}

	file.close();

	sort();
}

void SaveScore::loadScores(std::string fileName)
{
	scores.clear();
	addScores(fileName);
}

void SaveScore::saveScores(std::string fileName)
{
	std::ofstream file(fileName.c_str());
	int n = 0;

	if (file.is_open())
	{
		for (std::vector<int>::size_type i = 0; i != scores.size(); i++)
		{
			file << scores.at(i) << std::endl;
			n++;
			if (n == 20)
				break;
		}
	}
	file.close();
}

void SaveScore::sort()
{
	std::sort(scores.rbegin(), scores.rend());
}