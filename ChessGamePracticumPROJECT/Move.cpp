#include "stdafx.h"
#include "Move.h"
#include"Position.h"
#include<iostream>



Move::Move()
{
	this->startPosition = new Position(0, 0);
	this->destinationPosition = new Position(0, 0);
}


Move::Move(int rowFrom, int colFrom, int rowTo, int colTo, bool attackStatus)
{
	this->startPosition = new Position(rowFrom, colFrom);
	this->destinationPosition = new Position(rowTo, colTo);
	this->attackStatus = attackStatus;
}




int Move::getStartingRow()const
{
	return startPosition->getRow();
}

int Move::getDestinationRow()const
{
	return destinationPosition->getRow();
}


int Move::getStartingCol()const
{
	return startPosition->getCol();
}


int Move::getDestinationCol()const
{
	return destinationPosition->getCol();
}


bool Move::isAttacking() const
{
	return this->attackStatus;
}


void Move::setStartPosition(int row,int col)
{
	startPosition->setPosition(row, col);
}

void Move::setDestinationPosition(int row, int col) {
	destinationPosition->setPosition(row, col);
}


void Move::setAttackStatus(bool attackStatus)
{
	this->attackStatus = attackStatus;
}

void Move::printLogs() {
	std::cout << " startPosition row:" << getStartingRow() << std::endl;
	std::cout << " startPosition col:" << getStartingCol() << std::endl;

	std::cout << " destinationPosition row:" << getDestinationRow() << std::endl;
	std::cout << " destinationPosition col:" << getDestinationCol() << std::endl;
	std::cout << "is Attacking move:" << isAttacking() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
Move::~Move()
{
	delete destinationPosition;
	delete startPosition;
}