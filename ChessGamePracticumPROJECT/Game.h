#pragma once
#include"ConsoleView.h"
#include "Board.h"
#include"IView.h"

class Game 
{
private:

	IView* view;
	Board* board;
	Move* lastMove;
	int turnCounter;

public:
	Game(IView* view);
	~Game();

	bool move(int startRow, int startCol, int destinationRow, int destinationCol);
	void startGame();
	void printInfoForSpot(int x1, int x2);
	void undo();

private:
	void changeFigurePositionInBoard(Figure* figure, int destinationRow, int destinationCol);
};

