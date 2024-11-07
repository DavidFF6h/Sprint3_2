#ifndef GAME_H
#define GAME_H

#include <vector>
#include "CellState.h"
#include <set>
#include <tuple>


class Game {
public:
    Game(int size);

    void initGameBoard(int size);
    void resetGame(int size);
    bool setCellState(int row, int col, int currentPlayer, int selected_radio1, int selected_radio2);
    bool checkForSOS(int size);
    CellState getCurrentPlayerSymbol(int currentPlayer, int selected_radio1, int selected_radio2);
    const std::vector<std::vector<CellState>>& getGameBoard() const;

    int GetBlueScore() { return blueScore; }
    void SetBlueScore(int newScore) { blueScore = newScore; }

    int GetRedScore() { return redScore; }
    void SetRedScore(int newScore) { redScore = newScore; }

    virtual void UpdateScore(int currentPlayer) = 0;

protected:
    int boardSize;
    std::vector<std::vector<CellState>> gameBoard;
    int blueScore = 0;
    int redScore = 0;
    int numSOS = 0;


private:
    std::set<std::tuple<int, int, int, int, int, int>> sosPatterns;
};

#endif


