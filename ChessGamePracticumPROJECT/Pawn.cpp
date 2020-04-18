#include "stdafx.h"
#include "Pawn.h"
#include"Board.h"
#include"Queen.h"


Pawn::Pawn(Position * position, Color color, vector<Figure*>* takenFigures) :Figure(position, color, takenFigures)
{
	this->setName("Pawn");
	// the first move is the non attacking
	this->rules.push_back(new Position(1, 0));
	// 2nd and 3rd moves are the attacking moves
	this->rules.push_back(new Position(1, -1));
	this->rules.push_back(new Position(1, 1));


}


void Pawn::getPossibleMoves(vector<Move*>* result)
{

	bool flag = true;
	int row, col, tempRow, tempCol;
	Color curentColor;
	row = this->getRow();
	col = this->getCol();
	curentColor = board->getFigure(row, col)->getColor();
	int add = 1;
	if (curentColor == WHITE) { add = -1; };
	if (!board->isSpotEmpty(row, col))
	{
		for (unsigned int p = 0; p < 1; p++)
		{
			flag = true;


			tempRow = row + add * (rules.at(p)->getRow());
			tempCol = col + add * (rules.at(p)->getCol());

			if (position->isValid(tempRow, tempCol))
			{

				if (board->isSpotEmpty(tempRow, tempCol))
				{
					// if board is empty and attacking move is false
					result->push_back(new Move(row, col, tempRow, tempCol));

					if (board->isSpotEmpty(tempRow + add, tempCol)) {
						if (curentColor == WHITE && row == 6)
						{
							result->push_back(new Move(row, col, tempRow + add, tempCol));
						}
					}
					if (board->isSpotEmpty(tempRow + add, tempCol)) {
						if (curentColor == BLACK && row == 1)
						{
							result->push_back(new Move(row, col, tempRow + add, tempCol));
						}
					}
				}
				// if there is enemy figure and attacking move is true
				else {
					flag = false;
				}
			}
			else {
				flag = false;
			}



			for (int p = 1; p < 3; p++)
			{


				tempRow = row + add * (rules.at(p)->getRow());
				tempCol = col + add * (rules.at(p)->getCol());
				if (!board->isSpotEmpty(tempRow, tempCol))
				{


					if (board->getFigure(tempRow, tempCol)->getColor() != curentColor)
					{
						// if there is figure of somekind the rook could not jump over it 
						result->push_back(new Move(row, col, tempRow, tempCol, true));
						flag = false;
					}
				}
			}

		}
	}
}



Pawn::~Pawn()
{
	//std::cout << "hit delete figure";
	//delete &rules;
}
