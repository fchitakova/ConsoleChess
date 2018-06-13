
#pragma once

#include"GlobalVariables.h"

class IGame
{

public:
	virtual bool move(int x1,int y1,int x2, int y2) = 0;
	virtual void print() = 0;
	virtual void stats(int x1, int x2) = 0;
	virtual void undo() = 0;
	virtual void startGame() = 0;
};

