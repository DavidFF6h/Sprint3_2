#include "GeneralGame.h"

void GeneralGame::UpdateScore(int currrentPlayer)
{

    if (checkForSOS(boardSize)) {
        switch (currrentPlayer)
        {
        case 0:
            blueScore+=numSOS;
            break;
        case 1:
            redScore += numSOS;
            break;
        default:
            printf("Error in player switching");
            break;
        }
    }

    if (isFull()) {
        if (blueScore > redScore) {
            printf("Blue Wins");
        }
        else if (blueScore < redScore) {
            printf("Red Wins");
        }
        else {
            printf("Draw");
        }
    }
}


