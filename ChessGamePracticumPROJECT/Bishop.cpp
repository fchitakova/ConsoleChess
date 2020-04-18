#include "stdafx.h"
#include "Bishop.h"
#include "Board.h"





//************************************
// Method:    Bishop
// FullName:  Bishop::Bishop
// Access:    public 
// Returns:   
// Qualifier: :Figure(position, color, takenFigures)
// Parameter: Position * position
// Parameter: Color color
// Parameter: DynamicArray<Figure * > * takenFigures
//************************************
Bishop::Bishop(Position * position, Color color, vector<Figure*>* takenFigures) :Figure(position, color, takenFigures)
{

	this->setName("Bishop");
	// row col
		// 1,1
		// down 1, right 1
	this->rules.push_back(new Position(1, 1));
	// down 1, left 1
	this->rules.push_back(new Position(1, -1));

	// up 1, right 1
	this->rules.push_back(new Position(-1, 1));
	// up 1, left 1
	this->rules.push_back(new Position(-1, -1));
}


void Bishop::getPossibleMoves(vector<Move*>* result)
{
	bool flag = true;
	int row, col, tempRow, tempCol, colorCorrection;
	colorCorrection = 1;
	Color curentColor;
	row = position->getRow();
	col = position->getCol();
	curentColor = board->getFigure(row, col)->getColor();
	if (curentColor == BLACK)
	{
		colorCorrection = -1;
	}

	for (int i = 0; i < max_position_size ; i++)
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

Bishop::~Bishop()
{
}
