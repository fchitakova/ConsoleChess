#pragma once
#include"Position.h"
class Move
{
	Position* from;
	Position* to;
	bool isAttacking;
public:
	int getFromRow()const;
	int getToRow()const;
	int getFromCol()const;
	int getToCol()const;
	bool getIsAttacking()const;

	void setFromRow(int row);
	void setToRow(int row);
	void setFromCol(int col);
	void setToCol(int col);
	void setIsAttacking(bool isAttacking);

	void logToConsole();

	Move();
	Move(int rowFrom, int colFrom, int rowTo, int colTo, bool isAttacking = false);
	 ~Move();
};

