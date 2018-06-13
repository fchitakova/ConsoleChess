#pragma once

#include"Square.h"
#include"GlobalVariables.h"
#include"IBoard.h"
#include"Figure.h"

//class Figure;
class Board : public IBoard
{

	//void initSquares();
	Square** board;
	DynamicArray< DynamicArray<Figure*> *> * arraysToDelete;
	DynamicArray<Figure*>*  figuresToDelete;

public:

	
	void placeFigures() override;
	bool isEmpty(int row, int col)	override;
	Figure* getFigure(int row, int col)	override;
	bool setFigure(int row, int col, Figure*)	override;
	bool makeTileEmpty(int row, int col) override;
	Board();
	 ~Board();
};

