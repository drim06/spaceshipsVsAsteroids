
#include "MyGraphicEngine.h"
#include "utility.h"

void MyGraphicEngine::Draw(){

	// GameBoard
	for (int i = 1; i < 11; i++){
		GraphicPrimitives::drawLine2D(-1.0f, 1.0f - i*0.171667f, 0.71667f, 1.0f - i*0.171667f, 1.0f, 1.0f, 1.0f);
		GraphicPrimitives::drawLine2D(-1.0f + i * 0.171667f, 1.0f, -1.0f + i * 0.171667f, - 0.71667f, 1.0f, 1.0f, 1.0f);
	}

	float squareSide = (*shopShip_)[0].getSide();
	// ShopShip
	for (int i = 0; i < (int) shopShip_->size(); i++){
		(*shopShip_)[i].draw();
		(*shopShipList_)[i]->draw();
		(*shopShipList_)[i]->drawCost();
		GraphicPrimitives::drawLine2D((*shopShip_)[i].getPosX(), (*shopShip_)[i].getPosY(), (*shopShip_)[i].getPosX() + squareSide, (*shopShip_)[i].getPosY(), 0.9f, 0.9f, 0.9f);
		GraphicPrimitives::drawLine2D((*shopShip_)[i].getPosX(), (*shopShip_)[i].getPosY() + squareSide, (*shopShip_)[i].getPosX() + squareSide, (*shopShip_)[i].getPosY() + squareSide, 0.9f, 0.9f, 0.9f);
		GraphicPrimitives::drawLine2D((*shopShip_)[i].getPosX(), (*shopShip_)[i].getPosY(), (*shopShip_)[i].getPosX(), (*shopShip_)[i].getPosY() + squareSide, 0.9f, 0.9f, 0.9f);
		GraphicPrimitives::drawLine2D((*shopShip_)[i].getPosX() + squareSide, (*shopShip_)[i].getPosY(), (*shopShip_)[i].getPosX() + squareSide, (*shopShip_)[i].getPosY() + squareSide, 0.9f, 0.9f, 0.9f);
	}

	// SpaceShips
	for (int i = 0; i < (int) spaceShips_->size(); i++){
		(*spaceShips_)[i]->draw();
	}

	// Missiles
	for (int i = 0; i < (int) missiles_->size(); i++){
		(*missiles_)[i]->draw();
	}

	// Enemies
	for (int i = 0; i < (int) enemy_->size(); i++){
		(*enemy_)[i]->draw();
	}

	if (!wave_.getIsLaunched()){
		// Button Next Round
		GraphicPrimitives::drawFillRect2D(0.78f, -0.91f, 0.12f, 0.12f, 0.8f, 0.8f, 0.8f);
		// Text "GO"
		GraphicPrimitives::drawText2D("GO", 0.8f, -0.87f, 0.0f, 0.0f, 0.0f);
	}

	// Text Current Round	
	utility::itoa(wave_.getCurrentWaveDifficulty(), player_.getRoundTxt());
	GraphicPrimitives::drawText2D("Round", 0.75f, 0.9f, 0.9f, 0.9f, 0.9f);
	GraphicPrimitives::drawText2D(player_.getRoundTxt(), 0.9f, 0.9f, 0.9f, 0.9f, 0.9f);

	// Health
	GraphicPrimitives::drawText2D("Health", 0.75f, 0.65, 0.9f, 0.9f, 0.9f);
	GraphicPrimitives::drawFillRect2D(0.75f, 0.5f, 0.1f, 0.1f, 1.f, 1.f, 1.f);
	int userHealth = player_.getHealth();
	float yValue = 0.1f * userHealth / 100.f;
	float rValue = (100 - userHealth) / 100.f;
	float gValue = userHealth / 100.f;
	GraphicPrimitives::drawFillRect2D(0.75f, 0.5f, 0.1f, yValue, rValue, gValue, 0.f);
	utility::itoa(userHealth, player_.getHealthTxt());
	GraphicPrimitives::drawText2D(player_.getHealthTxt(), 0.9f, 0.53f, rValue, gValue, 0.f);

	// Money
	int userMoney = player_.getMoney();
	utility::itoa(userMoney, player_.getMoneyTxt());
	GraphicPrimitives::drawText2D("Money", 0.75f, 0.25, 0.9f, 0.9f, 0.9f);
	GraphicPrimitives::drawText2D("$", 0.75f, 0.15f, 1.f, 0.8f, 0.f);
	GraphicPrimitives::drawText2D(player_.getMoneyTxt(), 0.79f, 0.15f, 1.f, 0.8f, 0.f);

	if (player_.getHealth() <= 0){
		GraphicPrimitives::drawFillRect2D(-0.04f, -0.026f, 0.44f, 0.1f, 0.0f, 0.0f, 0.0f);
		GraphicPrimitives::drawText2D("   GAME OVER", 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	}
}
