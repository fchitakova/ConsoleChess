#pragma once

#include"Spot.h"
#include"King.h"
#include"Queen.h"
#include"Bishop.h"
#include"Horse.h"
#include"Rook.h"
#include"Pawn.h"

class Board
{
private:
	Spot** board;

public:
	Board();
	~Board();

	bool isSpotEmpty(int row, int col);
	bool isSpotValid(int row, int col);
	Figure* getFigure(int row, int col);

	bool placeFigure(Figure*figure, int row, int col);
	void removeFigureFromSpot(int row, int col);

private:
	void allocateBoardMemory();
	void initializeBoardPositions();
	void placeFigures();
};

