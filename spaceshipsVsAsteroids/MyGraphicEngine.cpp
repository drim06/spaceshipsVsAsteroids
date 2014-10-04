
#include "MyGraphicEngine.h"
#include "utility.h"

void MyGraphicEngine::Draw(){
    
	// GameBoard
	for (int rows = 0; rows < square_->size(); rows++) {
		for (int columns = 0; columns < square_->size(); columns++){
			(*square_)[rows][columns].draw();
		}
	}

	// SpaceShips
	for (int i = 0; i < spaceShips_->size(); i++){
		(*spaceShips_)[i]->draw();
	}

	// Missiles
	for (int i = 0; i < missiles_->size(); i++){
		(*missiles_)[i]->draw();
	}

	// Enemies
	for (int i = 0; i < enemy_->size(); i++){
		(*enemy_)[i]->draw();
	}

	if (!wave_.getIsLaunched()){
		// Button Next Round
		GraphicPrimitives::drawFillTriangle2D(0.9f, -0.85f, 0.8f, -0.8f, 0.8f, -0.9f, 0.f, 0.97f, 0.f);
		// Text "GO"
		GraphicPrimitives::drawText2D("Go", 0.8f, -0.87f, 1.f, 1.f, 1.f);
	}

	// Text Current Round
	char * roundTxt = new char[7]{ 'R', 'o', 'u', 'n', 'd', ' ', '\0' };
	char * roundNumber = new char[3];
	utility::itoa(wave_.getCurrentWaveDifficulty(), roundNumber);
	GraphicPrimitives::drawText2D(roundTxt, 0.75f, 0.9f, 1.f, 1.f, 1.f);
	GraphicPrimitives::drawText2D(roundNumber, 0.9f, 0.9f, 1.f, 1.f, 1.f);

	// Health
	GraphicPrimitives::drawText2D("Health", 0.75f, 0.65, 1.f, 1.f, 1.f);
	GraphicPrimitives::drawFillRect2D(0.75f, 0.5f, 0.1f, 0.1f, 1.f, 1.f, 1.f);
	int userHealth = player_.getHealth();
	float yValue = 0.1f * userHealth / 100.f;
	float rValue = (100 - userHealth) / 100.f;
	float gValue = userHealth / 100.f;
	GraphicPrimitives::drawFillRect2D(0.75f, 0.5f, 0.1f, yValue, rValue, gValue, 0.f);
	char * healthNumber = new char[4];
	utility::itoa(userHealth, healthNumber);
	GraphicPrimitives::drawText2D(healthNumber, 0.9f, 0.53f, 1.f, 1.f, 1.f);

	// Money
	int userMoney = player_.getMoney();
	char * userMoneyTxt = new char[4];
	utility::itoa(userMoney, userMoneyTxt);
	GraphicPrimitives::drawText2D("Money", 0.75f, 0.25, 1.f, 1.f, 1.f);
	GraphicPrimitives::drawText2D("$", 0.75f, 0.15f, 1.f, 0.8f, 0.f);
	GraphicPrimitives::drawText2D(userMoneyTxt, 0.79f, 0.15f, 1.f, 0.8f, 0.f);
}