#include "stdafx.h"
#include "Position.h"
#include<assert.h>
#include<iostream>


int Position::getRow() const
{
	return this->row;
}


int Position::getCol() const
{
	return this->col;
}


void Position::setRow(int Row)
{
	// valid only for figure coordinates
	//assert(Row >= 0 && Row <= 8);
	this->row = Row;
}


void Position::setCol(int col)
{
	// vaid only for figure coordinates
	//assert(col >= 0 && col <= 8);
	this->col = col;
}


Position::Position()
{
	setRow(0);
	setCol(0);
}


Position::Position(int row, int col)
{
	setCol(col);
	setRow(row);
}


bool Position::isValid(int row, int col)
{
	if (row < 0 || row >= 8 || col < 0 || col >= 8) {
		return false;
	}
	return true;
}


bool Position::isValid(const Position* position)
{
	if (position->row < 0 || position->row>8 || position->col <0 || position->col > 8) {
		return false;
	}
	return true;
}


Position::~Position()
{
	//std::cout << "hit delete posiition";
}
