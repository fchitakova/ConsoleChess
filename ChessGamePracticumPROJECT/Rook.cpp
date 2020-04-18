#include "stdafx.h"
#include "Rook.h"
#include"Board.h"






Rook::Rook(Position * position, Color color, vector<Figure*>* takenFigures) :Figure(position, color, takenFigures)
{
	this->setName("Rook");
	// row col
	// 
	// up
	this->rules.push_back(new Position(-1, 0));
	// down 
	this->rules.push_back(new Position(1, 0));

	// left
	this->rules.push_back(new Position(0, -1));
	// right
	this->rules.push_back(new Position(0, 1));
}


void Rook::getPossibleMoves( vector<Move*>* result)
{
	bool flag = true;
	int row, col, tempRow, tempCol;
	Color curentColor;
	row = this->position->getRow();
	col = this->position->getCol();
	curentColor = board->getFigure(row, col)->getColor();

	for (unsigned int i = 0; i < 1; i++)
	{

		if (!board->isSpotEmpty(row, col))
		{
			for (unsigned int p = 0; p < rules.size(); p++)
			{
				flag = true;
				int add = 1;
				while (flag)
				{
					tempRow = row + add * (rules.at(p)->getRow());
					tempCol = col + add * (rules.at(p)->getCol());

					if (position->isValid(tempRow, tempCol))
					{

						if (board->isSpotEmpty(tempRow, tempCol))
						{
							// if board is empty and attacking move is false
							result->push_back(new Move(row, col, tempRow, tempCol));
						}
						// if there is enemy figure and attacking move is true

						else if (board->getFigure(tempRow, tempCol)->getColor() != curentColor)
						{
							// if there is figure of somekind the rook could not jump over it 
							result->push_back(new Move(row, col, tempRow, tempCol, true));
							flag = false;
						}
						else {
							flag = false;
						}
					}
					else {
						flag = false;
					}
					++add;
				}
				// close foreach rules here
			}
		}
		// close foreach rule
		

	}
}

Rook::~Rook()
{
}
