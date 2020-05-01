#include "stdafx.h"
#include "Position.h"
#include<iostream>

Position::Position()
{
	this->setPosition(0, 0);
}

Position::Position(int row, int col)
{
	this->setPosition(row, col);
}


void Position::setPosition(int row, int col) {
	this->row = row;
	this->col = col;
}

int Position::getRow() const
{
	return this->row;
}

int Position::getCol() const
{
	return this->col;
}
