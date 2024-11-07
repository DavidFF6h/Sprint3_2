#include "pch.h"
#include "CppUnitTest.h"
#include "../Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SOSTests
{
    TEST_CLASS(TestBoardSize) {
public:
    TEST_METHOD(NewBoardSize_AffectsNextGame_NotCurrent) {
        // Given
        //Game game(3);  // Start with default 3x3 board size

        // When
        //game.resetGame(5);  // Set new size for next game

        // Then
        //auto currentBoard = game.getGameBoard();
        //Assert::AreEqual(5, static_cast<int>(currentBoard.size())); // Verify new size is applied to the new game
    }

    TEST_METHOD(DefaultBoardSize_AfterNoChange) {
        // Given
        //Game game(3);

        // When
        //game.resetGame(3);  // Same board size, no change

        // Then
       // auto currentBoard = game.getGameBoard();
       // Assert::AreEqual(3, static_cast<int>(currentBoard.size())); // Ensure default size remains if no change
    }
    };
}

