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
	nbEnemiesWanted_ = waveDifficulty_ * 2 + 5;
	isLaunched_ = true;
}

void Wave::run(const int &tick, std::vector<Enemy * > *enemy){
	if (isLaunched_){
		switch (waveDifficulty_){

		case 1:
			if ((tick % 300) == 0){
				switch (rand() % 4){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;

		case 2:
			if ((tick % 300) == 0){
				switch (rand() % 6){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidFragment(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;

		case 3: 
			if ((tick % 250) == 0){
				switch (rand() % 3){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidFragment(rand() % 10));
					generatedEnemies_++;
					break;
				case 2:
					enemy->push_back(new AsteroidNyobe(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;
		case 4:
			if ((tick % 220) == 0){
				switch (rand() % 3){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidFragment(rand() % 10));
					generatedEnemies_++;
					break;
				case 2:
					enemy->push_back(new AsteroidNyobe(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;
		case 5:
			if ((tick % 200) == 0){
				switch (rand() % 4){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidFragment(rand() % 10));
					generatedEnemies_++;
					break;
				case 2:
					enemy->push_back(new AsteroidNyobe(rand() % 10));
					generatedEnemies_++;
					break;
				case 3:
					enemy->push_back(new AsteroidKnuckle(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;
		case 6:
			if ((tick % 180) == 0){
				switch (rand() % 10){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidNyobe(rand() % 10));
					generatedEnemies_++;
					break;
				case 2:
					enemy->push_back(new AsteroidKnuckle(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;
		case 7:
			if ((tick % 160) == 0){
				switch (rand() % 10){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidNyobe(rand() % 10));
					generatedEnemies_++;
					break;
				case 2:
					enemy->push_back(new AsteroidKnuckle(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;
		case 8:
			if ((tick % 140) == 0){
				switch (rand() % 2){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidFragment(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;
		case 9:
			if ((tick % 120) == 0){
				switch (rand() % 2){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidFragment(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;
		case 10:
			if ((tick % 110) == 0){
				switch (rand() % 2){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidFragment(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;
		case 11:
			if ((tick % 100) == 0){
				switch (rand() % 2){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidFragment(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;
		case 12:
			if ((tick % 95) == 0){
				switch (rand() % 2){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidFragment(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;
		case 13:
			if ((tick % 90) == 0){
				switch (rand() % 2){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidFragment(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;
		case 14:
			if ((tick % 85) == 0){
				switch (rand() % 2){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidFragment(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;
		case 15:
			if ((tick % 80) == 0){
				switch (rand() % 2){
				case 0:
					enemy->push_back(new Asteroid(rand() % 10));
					generatedEnemies_++;
					break;
				case 1:
					enemy->push_back(new AsteroidFragment(rand() % 10));
					generatedEnemies_++;
					break;
				}
			}
			break;
		}
		
		if (generatedEnemies_ >= nbEnemiesWanted_){
			isLaunched_ = false;
		}
	}
}