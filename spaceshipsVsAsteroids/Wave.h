#pragma once
#include <vector>
#include "Enemy.h"
#include "Asteroid.h"
#include "AsteroidFragment.h"
#include "AsteroidNyobe.h"
#include "AsteroidKnuckle.h"

class Wave
{
private:
	int waveDifficulty_;		// plus grande est la valeur plus élevée est la difficulté
	bool isLaunched_;			// true si la vague est lancée
	int generatedEnemies_;		// ennemis apparues pour la vague en cours
	int nbEnemiesWanted_;		// nb d'ennemis total que contient une vague
public:
	Wave() :
		waveDifficulty_(0),
		isLaunched_(false),
		generatedEnemies_(0),
		nbEnemiesWanted_(0)
	{}

	int getCurrentWaveDifficulty();
	void setIsLaunched(bool);
	bool getIsLaunched();
	void nextWave();
	void run(const int&, std::vector<Enemy * > *);
};