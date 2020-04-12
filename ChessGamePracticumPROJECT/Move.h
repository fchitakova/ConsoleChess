#pragma once
#include"Position.h"
class Move
{
private:
	Position* from;
	Position* to;
	bool isAttacking;
public:
	int getStartingRow()const;
	int getDestinationRow()const;
	int getStartingCol()const;
	int getDestinationCol()const;
	bool getAttackingStatus()const;

	void setStartingRow(int row);
	void setDestinationRow(int row);
	void setStartingCol(int col);
	void setDestionationCol(int col);
	void setAttackStatus(bool isAttacking);

	void printLogs();

	Move();
	Move(int rowFrom, int colFrom, int rowTo, int colTo, bool isAttacking = false);
	 ~Move();
};

