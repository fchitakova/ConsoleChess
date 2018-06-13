#pragma once
#include"IGame.h"
#include"ConsoleView.h"
#include"IBoard.h"
#include"IView.h"

class Game : public IGame
{
	IView* view;
	IBoard* board;
	Move* lastMove;
	int turnCounter;
	
	
public:

	Game(IView* view);
	bool move(int x1, int y1, int x2, int y2) override;
	void print() override;
	void startGame();
	void stats(int x1, int x2) override;
	void undo() override;
	virtual ~Game();
};

