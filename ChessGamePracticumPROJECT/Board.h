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
	Spot** board;
	DynamicArray< DynamicArray<Figure*>*>* arraysToDelete;
	DynamicArray<Figure*>*  figuresToDelete;

public:
	Board();
	~Board();
	bool isSpotEmpty(int row, int col);
	Figure* getFigure(int row, int col);
	bool placeFigure(Figure* ,int row, int col);
	bool removeFigureFromSpot(int row, int col);
private:
	void placeFigures();

};

