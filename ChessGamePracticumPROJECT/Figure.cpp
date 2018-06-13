#include "stdafx.h"
#include "Figure.h"
#include"Position.h"
#include"IBoard.h"
#include<iostream>



#pragma warning(disable : 4996)

//************************************
// Method:    Figure
// FullName:  Figure::Figure
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: Position * position
// Parameter: Color color
// Parameter: DynamicArray<Figure * > * din
//************************************
Figure::Figure(Position* position, Color color, DynamicArray<Figure*>*din)
{
	this->position = position;
	this->color = color;
	this->isTaken_m = false;
	this->takenFigures = din;
	this->turnTaken = -1;

}

//************************************
// Method:    getName
// FullName:  Figure::getName
// Access:    public 
// Returns:   char *
// Qualifier: const
//************************************
char *  Figure::getName() const
{
	char* result = new char[strlen(this->name) + 1];
	strcpy(result, this->name);
	return result;
}

//************************************
// Method:    setName
// FullName:  Figure::setName
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: const char * name
//************************************
void Figure::setName(const char * name)
{
	if (this->name != nullptr)
	{
		delete this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

//************************************
// Method:    getColor
// FullName:  Figure::getColor
// Access:    public 
// Returns:   Color
// Qualifier: const
//************************************
Color Figure::getColor() const
{
	return this->color;
}

//************************************
// Method:    getRow
// FullName:  Figure::getRow
// Access:    public 
// Returns:   int
// Qualifier: const
//************************************
int Figure::getRow() const
{
	return this->position->getRow();
}

//************************************
// Method:    getCol
// FullName:  Figure::getCol
// Access:    public 
// Returns:   int
// Qualifier: const
//************************************
int Figure::getCol() const
{
	return this->position->getCol();
}

//************************************
// Method:    setRow
// FullName:  Figure::setRow
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int row
//************************************
void Figure::setRow(int row)
{
	if (this->isTaken_m == false)
	{
		if (position->areValid(row, this->getCol()))
		{
			this->position->setRow(row);
		}
	}
}
//************************************
// Method:    setCol
// FullName:  Figure::setCol
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int col
//************************************
void Figure::setCol(int col)
{
	if (this->isTaken_m == false)
	{
		if (position->areValid(this->getRow(), col))
		{
			this->position->setCol(col);
		}
	}
	else {
		// TODO throw exception
	}
}

//************************************
// Method:    getTurnTaken
// FullName:  Figure::getTurnTaken
// Access:    public 
// Returns:   int
// Qualifier: const
//************************************
int Figure::getTurnTaken() const
{
	/// if figure is not taken return -1
	return this->turnTaken;
}

//************************************
// Method:    setTurnTaken
// FullName:  Figure::setTurnTaken
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int turn
//************************************
void Figure::setTurnTaken(int turn)
{
	if (turn > 0)
	{
		this->isTaken_m = true;
		this->turnTaken = turn;
	}
	else {
		// throw exception
	}

}

//************************************
// Method:    setBoard
// FullName:  Figure::setBoard
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: IBoard * board
//************************************
bool Figure::setBoard(IBoard * board)
{
	if (board != nullptr)
	{
		this->board = board;
		return true;
	}
	return false;

}

//************************************
// Method:    isTaken
// FullName:  Figure::isTaken
// Access:    public 
// Returns:   bool
// Qualifier: const
//************************************
bool Figure::isTaken() const
{
	return this->isTaken_m;
}

//************************************
// Method:    makeNonTaken
// FullName:  Figure::makeNonTaken
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void Figure::makeNonTaken()
{
	this->isTaken_m = false;
}



//************************************
// Method:    getTakenFiguresList
// FullName:  Figure::getTakenFiguresList
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: DynamicArray<Figure * > * res
//************************************
void Figure::getTakenFiguresList(DynamicArray<Figure*>* res)
{
	/// results of this function may be result call non constant members unsafe
	/// might lead to program crash 
	*res = *(this->takenFigures);
}

//************************************
// Method:    pushTakenFigureList
// FullName:  Figure::pushTakenFigureList
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: Figure * fig
//************************************
void Figure::pushTakenFigureList(Figure * fig)
{
	this->takenFigures->push_back(fig);
}
//************************************
// Method:    deleteLastTakenFigure
// FullName:  Figure::deleteLastTakenFigure
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void Figure::deleteLastTakenFigure()
{
	this->takenFigures->remove_by_index(takenFigures->get_size() - 1);
}
//************************************
// Method:    getLastTakenFigure
// FullName:  Figure::getLastTakenFigure
// Access:    public 
// Returns:   Figure::Figure*
// Qualifier:
//************************************
Figure* Figure::getLastTakenFigure()
{
	return this->takenFigures->get_ElementAtIndex(takenFigures->get_size() - 1);
}

//************************************
// Method:    move
// FullName:  Figure::move
// Access:    virtual public 
// Returns:   bool
// Qualifier:
// Parameter: int row
// Parameter: int col
//************************************
bool Figure::move(int row, int col)
{
	DynamicArray<Move*> moves;
	this->getPossibleMoves(&moves);
	for (unsigned int i = 0; i < moves.get_size(); i++)
	{
		if (moves.get_ElementAtIndex(i)->getToRow() == row &&
			moves.get_ElementAtIndex(i)->getToCol() == col)
		{
			if ((board->isEmpty(row, col)) == true && (moves.get_ElementAtIndex(i)->getIsAttacking() == false))
			{
				return true;
			}
			else if (!(board->isEmpty(row, col)) && moves.get_ElementAtIndex(i)->getIsAttacking()) {
				return true;
			}
		}
	}
	return false;

}

//************************************
// Method:    printStats
// FullName:  Figure::printStats
// Access:    public 
// Returns:   std::ostream&
// Qualifier:
// Parameter: std::ostream & os
//************************************
std::ostream& Figure::printStats(std::ostream & os)
{
	Figure* el;
	os << "Figure" << " Color:" << this->getColor() << " Name:" << this->getName() << " Capture figures:" << std::endl;
	for (unsigned int i = 0; i < this->takenFigures->get_size(); i++)
	{
		os << ". --------------------------" << std::endl;
		el = this->takenFigures->get_ElementAtIndex(i);
		os << i << std::endl
			<< "Name: " << el->getName() << std::endl
			<< "Color:" << el->getColor() << std::endl
			<< "Turn taken:" << el->getTurnTaken() << std::endl;

	}
	os << std::endl << "--------------------------" << std::endl;
	return os;
}

//************************************
// Method:    getPossibleMoves
// FullName:  Figure::getPossibleMoves
// Access:    virtual public 
// Returns:   void
// Qualifier:
// Parameter: DynamicArray<Move * > * result
//************************************
void Figure::getPossibleMoves(DynamicArray<Move*>* result)
{
	int row, col, tempRow, tempCol;
	Color curentColor;
	row = position->getRow();
	col = position->getCol();
	curentColor = board->getFigure(row, col)->getColor();


	if (!board->isEmpty(row, col))
	{
		for (unsigned int p = 0; p < rules.get_size(); p++)
		{
			tempRow = row + rules.get_ElementAtIndex(p)->getRow();
			tempCol = col + rules.get_ElementAtIndex(p)->getCol();

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
					result->push_back(new Move(row, col, tempRow, tempCol, true));
				}
			}

			// close foreach rules here
		}
	}
	// close foreach rule
}


Figure::~Figure()
{
	std::cout << "hit delete figure";
	delete position;
	delete[] name;
}


