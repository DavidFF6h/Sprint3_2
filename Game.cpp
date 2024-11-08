#include "Game.h"

Game::Game(int size) {
    boardSize = size;
    initGameBoard(boardSize);
}

void Game::initGameBoard(int size) {
    gameBoard.clear();
    sosPatterns.clear();
    redScore = 0;
    blueScore = 0;
    gameBoard.resize(boardSize, std::vector<CellState>(boardSize, EMPTY));
}

void Game::resetGame(int size) {
    boardSize = size;
    initGameBoard(size);
}

CellState Game::getCurrentPlayerSymbol(int currentPlayer, int selected_radio1, int selected_radio2) {
    if (currentPlayer == 0) { // Blue player
        return selected_radio1 == 0 ? S_BLUE : O_BLUE; // S or O
    }
    else { // Red player
        return selected_radio2 == 0 ? S_RED : O_RED; // S or O
    }
}

bool Game::setCellState(int row, int col, int currentPlayer, int selected_radio1, int selected_radio2) {
    if (gameBoard[row][col] == EMPTY) {
        gameBoard[row][col] = getCurrentPlayerSymbol(currentPlayer, selected_radio1, selected_radio2);
        UpdateScore(currentPlayer);
        return true;
    }
    else { return false; }
}

bool Game::checkForSOS(int size) {
    bool foundSOS = false;
    numSOS = 0;

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            // Check horizontal SOS
            if (col + 2 < size) {  // Ensure we have enough columns for horizontal SOS
                if ((gameBoard[row][col] == S_BLUE || gameBoard[row][col] == S_RED) &&
                    (gameBoard[row][col + 1] == O_BLUE || gameBoard[row][col + 1] == O_RED) &&
                    (gameBoard[row][col + 2] == S_BLUE || gameBoard[row][col + 2] == S_RED)) {

                    auto pattern = std::make_tuple(row, col, row, col + 1, row, col + 2);
                    if (sosPatterns.find(pattern) == sosPatterns.end()) {
                        numSOS++;
                        sosPatterns.insert(pattern);
                        foundSOS = true;
                    }
                }
            }

            // Check vertical SOS
            if (row + 2 < size) {  // Ensure we have enough rows for vertical SOS
                if ((gameBoard[row][col] == S_BLUE || gameBoard[row][col] == S_RED) &&
                    (gameBoard[row + 1][col] == O_BLUE || gameBoard[row + 1][col] == O_RED) &&
                    (gameBoard[row + 2][col] == S_BLUE || gameBoard[row + 2][col] == S_RED)) {

                    auto pattern = std::make_tuple(row, col, row + 1, col, row + 2, col);
                    if (sosPatterns.find(pattern) == sosPatterns.end()) {
                        numSOS++;
                        sosPatterns.insert(pattern);
                        foundSOS = true;
                    }
                }
            }

            // Check diagonal SOS (top-left to bottom-right)
            if (row + 2 < size && col + 2 < size) {  // Ensure space for diagonal from top-left to bottom-right
                if ((gameBoard[row][col] == S_BLUE || gameBoard[row][col] == S_RED) &&
                    (gameBoard[row + 1][col + 1] == O_BLUE || gameBoard[row + 1][col + 1] == O_RED) &&
                    (gameBoard[row + 2][col + 2] == S_BLUE || gameBoard[row + 2][col + 2] == S_RED)) {

                    auto pattern = std::make_tuple(row, col, row + 1, col + 1, row + 2, col + 2);
                    if (sosPatterns.find(pattern) == sosPatterns.end()) {
                        sosPatterns.insert(pattern);
                        numSOS++;
                        foundSOS = true;
                    }
                }
            }

            // Check diagonal SOS (bottom-left to top-right)
            if (row - 2 >= 0 && col + 2 < size) {  // Ensure space for diagonal from bottom-left to top-right
                if ((gameBoard[row][col] == S_BLUE || gameBoard[row][col] == S_RED) &&
                    (gameBoard[row - 1][col + 1] == O_BLUE || gameBoard[row - 1][col + 1] == O_RED) &&
                    (gameBoard[row - 2][col + 2] == S_BLUE || gameBoard[row - 2][col + 2] == S_RED)) {

                    auto pattern = std::make_tuple(row, col, row - 1, col + 1, row - 2, col + 2);
                    if (sosPatterns.find(pattern) == sosPatterns.end()) {
                        sosPatterns.insert(pattern);
                        numSOS++;
                        foundSOS = true;
                    }
                }
            }
        }
    }

    return foundSOS;
}

bool Game::isFull() {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (gameBoard[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

const std::vector<std::vector<CellState>>& Game::getGameBoard() const {
    return gameBoard;
}

