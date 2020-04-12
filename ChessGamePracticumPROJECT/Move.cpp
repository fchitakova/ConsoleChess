#include "stdafx.h"
#include "Move.h"
#include"Position.h"
#include<iostream>



Move::Move()
{
	this->to = new Position(0, 0);
	this->from = new Position(0, 0);
}


Move::Move(int rowFrom, int colFrom, int rowTo, int colTo, bool isAttacking)
{
	this->to = new Position(0, 0);

	this->from = new Position(0, 0);
	setDestinationRow(rowTo);
	setDestionationCol(colTo);
	setStartingCol(colFrom);
	setStartingRow(rowFrom);
	this->isAttacking = isAttacking;
}




int Move::getStartingRow()const
{
	return from->getRow();
}

int Move::getDestinationRow()const
{
	return to->getRow();
}


int Move::getStartingCol()const
{
	return from->getCol();
}


int Move::getDestinationCol()const
{
	return to->getCol();
}


bool Move::getAttackingStatus() const
{
	return this->isAttacking;
}


void Move::setStartingRow(int row)
{
	from->setRow(row);
}


void Move::setDestinationRow(int row)
{
	to->setRow(row);
}


void Move::setStartingCol(int col)
{
	from->setCol(col);
}


void Move::setDestionationCol(int col)
{
	to->setCol(col);
}

void Move::setAttackStatus(bool isAttacking)
{
	this->isAttacking = isAttacking;
}

void Move::printLogs() {
	std::cout << " from row:" << getStartingRow() << std::endl;
	std::cout << " from col:" << getStartingCol() << std::endl;

	std::cout << " to row:" << getDestinationRow() << std::endl;
	std::cout << " to col:" << getDestinationCol() << std::endl;
	std::cout << "is Attacking move:" << getAttackingStatus() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
Move::~Move()
{
	delete to;
	delete from;
}