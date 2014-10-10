#pragma once
#include <vector>
#include "Enemy.h"
#include "Asteroid.h"
#include "AsteroidFragment.h"
#include "AsteroidNyobe.h"
#include "AsteroidKnuckle.h"
#include "AsteroidShyro.h"
#include "AsteroidFinal.h"

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

	inline void drawCurrentRound(Player& p) const{
		utility::itoa(getCurrentWaveDifficulty(), p.getRoundTxt());
		GraphicPrimitives::drawText2D("Round", 0.75f, 0.9f, 0.9f, 0.9f, 0.9f);
		GraphicPrimitives::drawText2D(p.getRoundTxt(), 0.9f, 0.9f, 0.9f, 0.9f, 0.9f);
	}

	int getCurrentWaveDifficulty() const;
	void setIsLaunched(bool);
	bool getIsLaunched() const;
	void nextWave();
	void run(const int&, std::vector<Enemy * > *);
	void init();
};