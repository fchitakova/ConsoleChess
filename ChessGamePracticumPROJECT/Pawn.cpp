#include "stdafx.h"
#include "Pawn.h"
#include"IBoard.h"
#include"Queen.h"

//************************************
// Method:    Pawn
// FullName:  Pawn::Pawn
// Access:    public 
// Returns:   
// Qualifier: :Figure(position, color, takenFigures)
// Parameter: Position * position
// Parameter: Color color
// Parameter: DynamicArray<Figure * > * takenFigures
//************************************
Pawn::Pawn(Position * position, Color color, DynamicArray<Figure*>* takenFigures) :Figure(position, color, takenFigures)
{
	this->setName("Pawn");
	// the first move is the non attacking
	this->rules.push_back(new Position(1, 0));
	// 2nd and 3rd moves are the attacking moves
	this->rules.push_back(new Position(1, -1));
	this->rules.push_back(new Position(1, 1));


}


//************************************
// Method:    getPossibleMoves
// FullName:  Pawn::getPossibleMoves
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: DynamicArray<Move * > * result
//************************************
void Pawn::getPossibleMoves(DynamicArray<Move*>* result)
{

	bool flag = true;
	int row, col, tempRow, tempCol;
	Color curentColor;
	row = this->getRow();
	col = this->getCol();
	curentColor = board->getFigure(row, col)->getColor();
	int add = 1;
	if (curentColor == WHITE) { add = -1; };
	if (!board->isEmpty(row, col))
	{
		for (unsigned int p = 0; p < 1; p++)
		{
			flag = true;


			tempRow = row + add * (rules.get_ElementAtIndex(p)->getRow());
			tempCol = col + add * (rules.get_ElementAtIndex(p)->getCol());

			if (position->areValid(tempRow, tempCol))
			{

				if (board->isEmpty(tempRow, tempCol))
				{
					// if board is empty and attacking move is false
					result->push_back(new Move(row, col, tempRow, tempCol));

					if (board->isEmpty(tempRow + add, tempCol)) {
						if (curentColor == WHITE && row == 6)
						{
							result->push_back(new Move(row, col, tempRow + add, tempCol));
						}
					}
					if (board->isEmpty(tempRow + add, tempCol)) {
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


				tempRow = row + add * (rules.get_ElementAtIndex(p)->getRow());
				tempCol = col + add * (rules.get_ElementAtIndex(p)->getCol());
				if (!board->isEmpty(tempRow, tempCol))
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
