#include "SimpleGame.h"

void SimpleGame::UpdateScore(int currrentPlayer)
{
    if (checkForSOS(boardSize)) {
		switch (currrentPlayer)
		{
		case 0:
			printf("Blue wins!");
			break;
		case 1:
			printf("Red wins!");
			break;
		default:
			printf("Error in player switching");
			break;
		}
    }
}
