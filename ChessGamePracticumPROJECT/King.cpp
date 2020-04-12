#include "stdafx.h"
#include "King.h"
#include "Board.h"


King::King(Position * position, Color color, DynamicArray<Figure*>* takenFigures) :Figure(position, color, takenFigures)
{
	this->setName("King");
	// row col
	// up left (diagonal)
	this->rules.push_back(new Position(-1, -1));
	// up
	this->rules.push_back(new Position(-1, 0));
	// up right(diagonal)
	this->rules.push_back(new Position(-1, 1));
	// right
	this->rules.push_back(new Position(0, 1));
	// down right (diagonal)
	this->rules.push_back(new Position(1, 1));
	// down 
	this->rules.push_back(new Position(1, 0));
	// down left (diagonal)
	this->rules.push_back(new Position(1, -1));
	// left 
	this->rules.push_back(new Position(0, -1));
}

//************************************
// Method:    getPossibleMoves
// FullName:  King::getPossibleMoves
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: DynamicArray<Move * > * result
//************************************
void King::getPossibleMoves( DynamicArray<Move*>* result)
{
	DynamicArray<Position*> freePosition;
	DynamicArray<Move*> attackedPosition;

	// row = i , col = j
	for (int i = 0; i < max_position_size; i++)
	{
		for (int j = 0; j < max_position_size; j++)
		{
			if (board->isSpotEmpty(i, j))
			{
				freePosition.push_back(new Position(i, j));
			}
			else if (!board->isSpotEmpty(i, j)) {
				if (this->position->getCol() != j && this->position->getRow() != i)
				{
					this->board->getFigure(i, j)->getPossibleMoves(&attackedPosition);
				}

			}
		}
	}
	int tempRow, tempCol;
	bool isAttacked = false;
	for (unsigned int i = 0; i < rules.get_size(); i++)
	{
		tempRow = position->getRow() + this->rules.get_ElementAtIndex(i)->getRow();
		tempCol = position->getCol() + this->rules.get_ElementAtIndex(i)->getCol();
		// if the position is empty and not attacked
		// if the position is enemy and not attacked 
		isAttacked = false;
		if (this->position->isValid(tempRow,tempCol))
		{

			for (unsigned int i = 0; i < attackedPosition.get_size(); i++)
			{

				if (attackedPosition.get_ElementAtIndex(i)->getDestinationRow() == tempRow
					&& attackedPosition.get_ElementAtIndex(i)->getDestinationCol() == tempCol)
				{
					isAttacked = true;
				}
			}
			// if the position is empty and not attacked
			if (!isAttacked && board->isSpotEmpty(tempRow, tempCol))
			{
				result->push_back(new Move(this->position->getRow(), this->position->getCol(), tempRow, tempCol, false));
			}
			// if the position is enemy and not attacked 
			if (!this->board->isSpotEmpty(tempRow, tempCol) && !isAttacked)
			{
				if (this->board->getFigure(tempRow, tempCol)->getColor() != this->getColor())
				{
					result->push_back(new Move(this->position->getRow(), this->position->getCol(), tempRow, tempCol, true));
				}
			}

		}
	}
}

King::~King()
{
}
