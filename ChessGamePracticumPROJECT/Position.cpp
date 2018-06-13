#include "stdafx.h"
#include "Position.h"
#include<assert.h>
#include"GlobalVariables.h"
#include<iostream>

//************************************
// Method:    getRow
// FullName:  Position::getRow
// Access:    public 
// Returns:   int
// Qualifier: const
//************************************
int Position::getRow() const
{
	return this->row;
}

//************************************
// Method:    getCol
// FullName:  Position::getCol
// Access:    public 
// Returns:   int
// Qualifier: const
//************************************
int Position::getCol() const
{
	return this->col;
}

//************************************
// Method:    setRow
// FullName:  Position::setRow
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int Row
//************************************
void Position::setRow(int Row)
{
	// valid only for figure coordinates
	//assert(Row >= 0 && Row <= GlobalVaribles::SIZE);
	this->row = Row;
}

//************************************
// Method:    setCol
// FullName:  Position::setCol
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int col
//************************************
void Position::setCol(int col)
{
	// vaid only for figure coordinates
	//assert(col >= 0 && col <= GlobalVaribles::SIZE);
	this->col = col;
}

//************************************
// Method:    Position
// FullName:  Position::Position
// Access:    public 
// Returns:   
// Qualifier:
//************************************
Position::Position()
{
	setRow(0);
	setCol(0);
}

//************************************
// Method:    Position
// FullName:  Position::Position
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: int row
// Parameter: int col
//************************************
Position::Position(int row, int col)
{
	setCol(col);
	setRow(row);
}

//************************************
// Method:    areValid
// FullName:  Position::areValid
// Access:    public static 
// Returns:   bool
// Qualifier:
// Parameter: int row
// Parameter: int col
//************************************
bool Position::areValid(int row, int col)
{
	if (row < 0 || row >= GlobalVaribles::SIZE || col < 0 || col >= GlobalVaribles::SIZE) {
		return false;
	}
	return true;
}
//************************************
// Method:    areValid
// FullName:  Position::areValid
// Access:    public static 
// Returns:   bool
// Qualifier:
// Parameter: const Position * position
//************************************
bool Position::areValid(const Position* position)
{
	if (position->row < 0 || position->row>GlobalVaribles::SIZE || position->col <0 || position->col > GlobalVaribles::SIZE) {
		return false;
	}
	return true;
}


Position::~Position()
{
	//std::cout << "hit delete posiition";
}
