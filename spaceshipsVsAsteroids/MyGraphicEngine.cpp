
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

	// Text Current Round	
	wave_.drawCurrentRound(player_);

	// Health
	player_.drawCurrentHealth();

	// Money
	player_.drawCurrentMoney();

	if (!wave_.getIsLaunched() && !(wave_.getCurrentWaveDifficulty() == 16)){
		// Button Next Round
		GraphicPrimitives::drawFillRect2D(0.78f, -0.91f, 0.12f, 0.12f, 0.8f, 0.8f, 0.8f);
		// Text "GO"
		GraphicPrimitives::drawText2D("GO", 0.8f, -0.87f, 0.0f, 0.0f, 0.0f);
	}
}
