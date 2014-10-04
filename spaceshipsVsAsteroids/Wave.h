#pragma once
#include <vector>
#include "Enemy.h"
#include "Asteroid.h"
#include "AsteroidFragment.h"

class Wave
{
private:
	int waveDifficulty_;	// plus grande est la valeur plus �lev�e est la difficult�
	bool isLaunched_;			// true si la vague est lanc�e
	int generatedEnemies_;
	int nbEnemiesWanted_;
public:
	Wave() :
		waveDifficulty_(1),
		isLaunched_(true),
		generatedEnemies_(0),
		nbEnemiesWanted_(10)
	{}

	int getCurrentWaveDifficulty();
	void setIsLaunched(bool);
	bool getIsLaunched();
	void nextWave();
	void run(const int&, std::vector<Enemy * > *);
};