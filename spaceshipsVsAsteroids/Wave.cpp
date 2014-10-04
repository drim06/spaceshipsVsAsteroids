#include "Wave.h"

int Wave::getCurrentWaveDifficulty(){
	return waveDifficulty_;
}

void Wave::setIsLaunched(bool b){
	isLaunched_ = b;
}

bool Wave::getIsLaunched(){
	return isLaunched_;
}

void Wave::nextWave(){
	waveDifficulty_++;
	generatedEnemies_ = 0;
	nbEnemiesWanted_ = waveDifficulty_ * 4 + 5;
}

void Wave::run(const int &tick, std::vector<Enemy * > *enemy){
	if (isLaunched_){
		switch (waveDifficulty_){

		case 1:
			if ((tick % 100) == 0){
				enemy->push_back(new Asteroid(rand() % 10));
				generatedEnemies_++;
			}
			break;

		case 2:
			if ((rand() % 3 + 1) * (tick % 50) == 0){
				switch (rand() % 2){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
				case 1:
					enemy->push_back(new AsteroidFragment(rand() % 10));
					generatedEnemies_++;
				}
			}
			break;

		//case 3: .....
		}
		
		if (generatedEnemies_ >= nbEnemiesWanted_){
			isLaunched_ = false;
		}
	}
}