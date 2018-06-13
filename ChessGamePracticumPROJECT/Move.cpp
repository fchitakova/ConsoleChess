#include "stdafx.h"
#include "Move.h"
#include"Position.h"
#include<iostream>


//************************************
// Method:    Move
// FullName:  Move::Move
// Access:    public 
// Returns:   
// Qualifier:
//************************************
Move::Move()
{
	this->to = new Position(0, 0);
	this->from = new Position(0, 0);
}
//************************************
// Method:    Move
// FullName:  Move::Move
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: int rowFrom
// Parameter: int colFrom
// Parameter: int rowTo
// Parameter: int colTo
// Parameter: bool isAttacking
//************************************
Move::Move(int rowFrom, int colFrom, int rowTo, int colTo, bool isAttacking)
{
	this->to = new Position(0, 0);

	this->from = new Position(0, 0);
	setToRow(rowTo);
	setToCol(colTo);
	setFromCol(colFrom);
	setFromRow(rowFrom);
	this->isAttacking = isAttacking;
}




//************************************
// Method:    getFromRow
// FullName:  Move::getFromRow
// Access:    public 
// Returns:   int
// Qualifier: const
//************************************
int Move::getFromRow()const
{
	return from->getRow();
}

//************************************
// Method:    getToRow
// FullName:  Move::getToRow
// Access:    public 
// Returns:   int
// Qualifier: const
//************************************
int Move::getToRow()const
{
	return to->getRow();
}

//************************************
// Method:    getFromCol
// FullName:  Move::getFromCol
// Access:    public 
// Returns:   int
// Qualifier: const
//************************************
int Move::getFromCol()const
{
	return from->getCol();
}

//************************************
// Method:    getToCol
// FullName:  Move::getToCol
// Access:    public 
// Returns:   int
// Qualifier: const
//************************************
int Move::getToCol()const
{
	return to->getCol();
}

//************************************
// Method:    getIsAttacking
// FullName:  Move::getIsAttacking
// Access:    public 
// Returns:   bool
// Qualifier: const
//************************************
bool Move::getIsAttacking() const
{
	return this->isAttacking;
}

//************************************
// Method:    setFromRow
// FullName:  Move::setFromRow
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int row
//************************************
void Move::setFromRow(int row)
{
	from->setRow(row);
}

//************************************
// Method:    setToRow
// FullName:  Move::setToRow
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int row
//************************************
void Move::setToRow(int row)
{
	to->setRow(row);
}

//************************************
// Method:    setFromCol
// FullName:  Move::setFromCol
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int col
//************************************
void Move::setFromCol(int col)
{
	from->setCol(col);
}

//************************************
// Method:    setToCol
// FullName:  Move::setToCol
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int col
//************************************
void Move::setToCol(int col)
{
	to->setCol(col);
}
//************************************
// Method:    setIsAttacking
// FullName:  Move::setIsAttacking
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: bool isAttacking
//************************************
void Move::setIsAttacking(bool isAttacking)
{
	this->isAttacking = isAttacking;
}
//************************************
// Method:    logToConsole
// FullName:  Move::logToConsole
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void Move::logToConsole() {
	std::cout << " from row:" << getFromRow() << std::endl;
	std::cout << " from col:" << getFromCol() << std::endl;

	std::cout << " to row:" << getToRow() << std::endl;
	std::cout << " to col:" << getToCol() << std::endl;
	std::cout << "is Attacking move:" << getIsAttacking() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
Move::~Move()
{
	delete to;
	delete from;
}