#pragma once
#include"Position.h"
class Move
{
private:
	Position* startPosition;
	Position* destinationPosition;
	bool attackStatus;
public:
	Move();
	Move(int rowFrom, int colFrom, int rowTo, int colTo, bool attackStatus = false);
	~Move();

	int getStartingRow()const;
	int getDestinationRow()const;
	int getStartingCol()const;
	int getDestinationCol()const;
	bool isAttacking()const;

	void setStartPosition(int row, int col);
	void setDestinationPosition(int row, int col);
	void setAttackStatus(bool attackStatus);

	void printLogs();
};

