#include "stdafx.h"
#include "King.h"
#include "Board.h"


King::King(Position * position, Color color, vector<Figure*>* takenFigures) :Figure(position, color, takenFigures)
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

void King::getPossibleMoves( vector<Move*>* result)
{
	vector<Position*> freePosition;
	vector<Move*> attackedPosition;

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
	for (unsigned int i = 0; i < rules.size(); i++)
	{
		tempRow = position->getRow() + this->rules.at(i)->getRow();
		tempCol = position->getCol() + this->rules.at(i)->getCol();
		// if the position is empty and not attacked
		// if the position is enemy and not attacked 
		isAttacked = false;
		if (this->position->isValid(tempRow,tempCol))
		{

			for (unsigned int i = 0; i < attackedPosition.size(); i++)
			{

				if (attackedPosition.at(i)->getDestinationRow() == tempRow
					&& attackedPosition.at(i)->getDestinationCol() == tempCol)
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
