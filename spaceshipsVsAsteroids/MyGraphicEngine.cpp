
#include "MyGraphicEngine.h"
#include "utility.h"

void MyGraphicEngine::Draw(){
    
	// GameBoard
	/*for (unsigned int rows = 0; rows < square_->size(); rows++) {
		for (unsigned int columns = 0; columns < square_->size(); columns++){
			(*square_)[rows][columns].draw();
		}
	}*/

	// GameBoard
	for (int i = 1; i < 11; i++){
		GraphicPrimitives::drawLine2D(-1.0f, 1.0f - i*0.171667f, 0.71667f, 1.0f - i*0.171667f, 1.0f, 1.0f, 1.0f);
		GraphicPrimitives::drawLine2D(-1.0f + i * 0.171667f, 1.0f, -1.0f + i * 0.171667f, - 0.71667f, 1.0f, 1.0f, 1.0f);
	}

	float squareSide = (*shopShip_)[0].getSide();
	// ShopShip
	for (int i = 0; i < shopShip_->size(); i++){
		(*shopShip_)[i].draw();
		(*shopShipList_)[i]->draw();
		GraphicPrimitives::drawLine2D((*shopShip_)[i].getPosX(), (*shopShip_)[i].getPosY(), (*shopShip_)[i].getPosX() + squareSide, (*shopShip_)[i].getPosY(), 0.9f, 0.9f, 0.9f);
		GraphicPrimitives::drawLine2D((*shopShip_)[i].getPosX(), (*shopShip_)[i].getPosY() + squareSide, (*shopShip_)[i].getPosX() + squareSide, (*shopShip_)[i].getPosY() + squareSide, 0.9f, 0.9f, 0.9f);
		GraphicPrimitives::drawLine2D((*shopShip_)[i].getPosX(), (*shopShip_)[i].getPosY(), (*shopShip_)[i].getPosX(), (*shopShip_)[i].getPosY() + squareSide, 0.9f, 0.9f, 0.9f);
		GraphicPrimitives::drawLine2D((*shopShip_)[i].getPosX() + squareSide, (*shopShip_)[i].getPosY(), (*shopShip_)[i].getPosX() + squareSide, (*shopShip_)[i].getPosY() + squareSide, 0.9f, 0.9f, 0.9f);
	}

	// SpaceShips
	for (unsigned int i = 0; i < spaceShips_->size(); i++){
		(*spaceShips_)[i]->draw();
	}

	// Missiles
	for (unsigned int i = 0; i < missiles_->size(); i++){
		(*missiles_)[i]->draw();
	}

	// Enemies
	for (unsigned int i = 0; i < enemy_->size(); i++){
		(*enemy_)[i]->draw();
	}

	if (!wave_.getIsLaunched()){
		// Button Next Round
		GraphicPrimitives::drawFillRect2D(0.78f, -0.91f, 0.12f, 0.12f, 0.8f, 0.8f, 0.8f);
		// Text "GO"
		GraphicPrimitives::drawText2D("GO", 0.8f, -0.87f, 0.0f, 0.0f, 0.0f);
	}

	// Text Current Round
	char * roundTxt = new char[7]{ 'R', 'o', 'u', 'n', 'd', ' ', '\0' };
	char * roundNumber = new char[3];
	utility::itoa(wave_.getCurrentWaveDifficulty(), roundNumber);
	GraphicPrimitives::drawText2D(roundTxt, 0.75f, 0.9f, 0.9f, 0.9f, 0.9f);
	GraphicPrimitives::drawText2D(roundNumber, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f);

	// Health
	GraphicPrimitives::drawText2D("Health", 0.75f, 0.65, 0.9f, 0.9f, 0.9f);
	GraphicPrimitives::drawFillRect2D(0.75f, 0.5f, 0.1f, 0.1f, 1.f, 1.f, 1.f);
	int userHealth = player_.getHealth();
	float yValue = 0.1f * userHealth / 100.f;
	float rValue = (100 - userHealth) / 100.f;
	float gValue = userHealth / 100.f;
	GraphicPrimitives::drawFillRect2D(0.75f, 0.5f, 0.1f, yValue, rValue, gValue, 0.f);
	char * healthNumber = new char[4];
	utility::itoa(userHealth, healthNumber);
	GraphicPrimitives::drawText2D(healthNumber, 0.9f, 0.53f, rValue, gValue, 0.f);

	// Money
	int userMoney = player_.getMoney();
	char * userMoneyTxt = new char[4];
	utility::itoa(userMoney, userMoneyTxt);
	GraphicPrimitives::drawText2D("Money", 0.75f, 0.25, 0.9f, 0.9f, 0.9f);
	GraphicPrimitives::drawText2D("$", 0.75f, 0.15f, 1.f, 0.8f, 0.f);
	GraphicPrimitives::drawText2D(userMoneyTxt, 0.79f, 0.15f, 1.f, 0.8f, 0.f);

	// Shop
	/*int spaceShipSelected = player_.getSpaceShipSelected();
	switch (spaceShipSelected){
	case 0:
		// do nothing
		break;
	case 1:
		GraphicPrimitives::drawLine2D(-0.87f, -0.96f, -0.75f, -0.96f, 1.0f, 0.0f, 0.f);
		break;
	case 2:
		GraphicPrimitives::drawLine2D(-0.72f, -0.96f, -0.6f, -0.96f, 1.0f, 1.0f, 0.f);
		break;
	case 3:
		GraphicPrimitives::drawLine2D(-0.57f, -0.96f, -0.45f, -0.96f, 0.0f, 0.0f, 1.f);
		break;
	case 4:
		GraphicPrimitives::drawLine2D(-0.42f, -0.96f, -0.3f, -0.96f, 0.0f, 1.0f, 0.f);
		break;
	}
	float squarePosX = -0.92f;
	float squarePosY = -0.96f;
	float squareSide = (*square_)[0][0].getSide();
	// spaceship 1
	GraphicPrimitives::drawFillTriangle2D(
		squarePosX + squareSide,
		squarePosY + squareSide / 2,
		squarePosX + squareSide - (squareSide * 0.7f),
		squarePosY + squareSide / 2 + (squareSide / 3),
		squarePosX + squareSide - (squareSide * 0.7f),
		squarePosY + squareSide / 2 - (squareSide / 3),
		1.0f,
		0.0f,
		0.0f);
	GraphicPrimitives::drawText2D(
		"40$",
		-0.87f,
		-0.77f,
		1.f,
		0.8f,
		0.f);
	
	// spaceship 2
	GraphicPrimitives::drawFillTriangle2D(
		squarePosX + squareSide + 0.13f,
		squarePosY + squareSide / 2,
		squarePosX + squareSide - (squareSide * 0.7f) + 0.15f,
		squarePosY + squareSide / 2 + (squareSide / 3),
		squarePosX + squareSide - (squareSide * 0.7f) + 0.15f,
		squarePosY + squareSide / 2 - (squareSide / 3),
		1.0f,
		1.0f,
		0.7f);
	GraphicPrimitives::drawFillTriangle2D(
		squarePosX + squareSide + 0.15f,
		squarePosY + squareSide / 2,
		squarePosX + squareSide - (squareSide * 0.7f) + 0.17f,
		squarePosY + squareSide / 2 + (squareSide / 3),
		squarePosX + squareSide - (squareSide * 0.7f) + 0.17f,
		squarePosY + squareSide / 2 - (squareSide / 3),
		1.0f,
		1.0f,
		0.0f);
	GraphicPrimitives::drawText2D(
		"75$",
		-0.715f,
		-0.77f,
		1.f,
		0.8f,
		0.f);

	// spaceship 3
	GraphicPrimitives::drawFillTriangle2D(
		squarePosX + squareSide + 0.30f,
		squarePosY + squareSide / 2,
		squarePosX + squareSide - (squareSide * 0.7f) + 0.30f,
		squarePosY + squareSide / 2 + (squareSide / 3),
		squarePosX + squareSide - (squareSide * 0.7f) + 0.30f,
		squarePosY + squareSide / 2 - (squareSide / 3),
		0.2f,
		0.1f,
		1.0f);
	GraphicPrimitives::drawFillTriangle2D(
		squarePosX + squareSide + 0.30f - squareSide/3,
		squarePosY + squareSide / 2 + 0.09f,
		squarePosX + squareSide - (squareSide * 0.7f) + 0.30f,
		squarePosY + squareSide / 2 + (squareSide / 3),
		squarePosX + squareSide - (squareSide * 0.7f) + 0.30f,
		squarePosY + squareSide / 2 - (squareSide / 3),
		0.2f,
		0.1f,
		1.0f);
	GraphicPrimitives::drawFillTriangle2D(
		squarePosX + squareSide + 0.30f - squareSide / 3,
		squarePosY + squareSide / 2 - 0.08f,
		squarePosX + squareSide - (squareSide * 0.7f) + 0.30f,
		squarePosY + squareSide / 2 + (squareSide / 3),
		squarePosX + squareSide - (squareSide * 0.7f) + 0.30f,
		squarePosY + squareSide / 2 - (squareSide / 3),
		0.2f,
		0.1f,
		1.0f);
	GraphicPrimitives::drawText2D(
		"150$",
		-0.57f,
		-0.77f,
		1.f,
		0.8f,
		0.f);

	// spaceship 4
	GraphicPrimitives::drawFillRect2D(
		-0.45f + 0.08f,
		-0.95f,
		0.02f,
		0.171667f,
		0.0f,
		1.0f,
		0.0f);
	GraphicPrimitives::drawFillRect2D(
		-0.425f,
		-0.95f + 0.0858335f - 0.01f,
		0.13f,
		0.02f,
		0.0f,
		1.0f,
		0.0f);
	GraphicPrimitives::drawFillRect2D(
		-0.385f,
		-0.89f,
		0.05f,
		0.05f,
		0.0f,
		1.0f,
		0.0f);
	GraphicPrimitives::drawText2D(
		"400$",
		-0.4f,
		-0.77f,
		1.f,
		0.8f,
		0.f);

	// Circle
	/*std::vector<float> vecX;
	std::vector<float> vecY;
	for (int i = 0; i < 100; i++){
		vecX.push_back(cos(i / 10.f));
		vecY.push_back(sin(i / 10.f));
	}
	GraphicPrimitives::drawFillPolygone2D(
		vecX,
		vecY,
		1.0f,
		0.f,
		0.f);*/

	if (player_.getHealth() <= 0){
		GraphicPrimitives::drawFillRect2D(-0.04f, -0.026f, 0.44f, 0.1f, 0.0f, 0.0f, 0.0f);
		GraphicPrimitives::drawText2D("   GAME OVER", 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	}
}
