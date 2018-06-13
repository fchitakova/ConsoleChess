#pragma once

#include"Square.h"
#include"GlobalVariables.h"
class Figure;
class IBoard
{

public:
	virtual void placeFigures() =0;
	virtual bool isEmpty(int row, int col)=0;
	virtual Figure* getFigure(int row, int col)=0;
	virtual bool setFigure(int row, int col, Figure*) = 0;
	virtual bool makeTileEmpty(int row, int col)=0;
};

