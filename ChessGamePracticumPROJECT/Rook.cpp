#include "stdafx.h"
#include "Rook.h"
#include"IBoard.h"





//************************************
// Method:    Rook
// FullName:  Rook::Rook
// Access:    public 
// Returns:   
// Qualifier: :Figure(position, color, takenFigures)
// Parameter: Position * position
// Parameter: Color color
// Parameter: DynamicArray<Figure * > * takenFigures
//************************************
Rook::Rook(Position * position, Color color, DynamicArray<Figure*>* takenFigures) :Figure(position, color, takenFigures)
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

//************************************
// Method:    getPossibleMoves
// FullName:  Rook::getPossibleMoves
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: DynamicArray<Move * > * result
//************************************
void Rook::getPossibleMoves( DynamicArray<Move*>* result)
{
	bool flag = true;
	int row, col, tempRow, tempCol;
	Color curentColor;
	row = this->position->getRow();
	col = this->position->getCol();
	curentColor = board->getFigure(row, col)->getColor();

	for (unsigned int i = 0; i < 1; i++)
	{

		if (!board->isEmpty(row, col))
		{
			for (unsigned int p = 0; p < rules.get_size(); p++)
			{
				flag = true;
				int add = 1;
				while (flag)
				{
					tempRow = row + add * (rules.get_ElementAtIndex(p)->getRow());
					tempCol = col + add * (rules.get_ElementAtIndex(p)->getCol());

					if (position->areValid(tempRow, tempCol))
					{

						if (board->isEmpty(tempRow, tempCol))
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
