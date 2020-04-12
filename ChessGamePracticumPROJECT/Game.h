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
	bool move(int x1, int y1, int x2, int y2);
	void startGame();
	void printInfoForSpot(int x1, int x2);
	void undo();
	virtual ~Game();
};

