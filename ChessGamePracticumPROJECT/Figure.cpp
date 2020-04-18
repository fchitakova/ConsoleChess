#include "stdafx.h"
#include "Figure.h"
#include "Position.h"
#include "Board.h"

#include<iostream>



#pragma warning(disable : 4996)

Figure::Figure(Position* position, Color color, vector<Figure*>*din)
{
	this->position = position;
	this->color = color;
	this->isTaken_m = false;
	this->takenFigures = *din;
	this->turnTaken = -1;
}


char *  Figure::getName() const
{
	char* result = new char[strlen(this->name) + 1];
	strcpy(result, this->name);
	return result;
}

void Figure::setName(const char * name)
{
	if (this->name != nullptr)
	{
		delete this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}


Color Figure::getColor() const
{
	return this->color;
}


int Figure::getRow() const
{
	return this->position->getRow();
}


int Figure::getCol() const
{
	return this->position->getCol();
}


void Figure::setRow(int row)
{
	if (this->isTaken_m == false)
	{
		if (position->isValid(row, this->getCol()))
		{
			this->position->setRow(row);
		}
	}
}

void Figure::setCol(int col)
{
	if (this->isTaken_m == false)
	{
		if (position->isValid(this->getRow(), col))
		{
			this->position->setCol(col);
		}
	}
	else {
		// TODO throw exception
	}
}

//************************************
// Method:    getTurnNumber
// FullName:  Figure::getTurnNumber
// Access:    public 
// Returns:   int
// Qualifier: const
//************************************
int Figure::getTurnNumber() const
{
	/// if figure is not taken return -1
	return this->turnTaken;
}

//************************************
// Method:    setTurnNumber
// FullName:  Figure::setTurnNumber
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int turn
//************************************
void Figure::setTurnNumber(int turn)
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


bool Figure::setBoard(Board * board)
{
	if (board != nullptr)
	{
		this->board = board;
		return true;
	}
	return false;

}


bool Figure::isTaken() const
{
	return this->isTaken_m;
}

void Figure::makeNonTaken()
{
	this->isTaken_m = false;
}

void Figure::getTakenFiguresList(vector<Figure*>* res)
{
	/// results of this function may be result call non constant members unsafe
	/// might lead to program crash 
	res = &takenFigures;
}


void Figure::addToTakenList(Figure * fig)
{
	takenFigures.push_back(fig);
}

void Figure::deleteLastTakenFigure()
{
	takenFigures.erase(takenFigures.end() - 1);
}

Figure* Figure::getLastTakenFigure()
{
	return takenFigures.at(takenFigures.size() - 1);
}


bool Figure::move(int row, int col)
{
	vector<Move*> moves;
	this->getPossibleMoves(&moves);
	for (unsigned int i = 0; i < moves.size(); i++)
	{
		if (moves.at(i)->getDestinationRow() == row &&
			moves.at(i)->getDestinationCol() == col)
		{
			if ((board->isSpotEmpty(row, col)) == true && (moves.at(i)->getAttackingStatus() == false))
			{
				return true;
			}
			else if (!(board->isSpotEmpty(row, col)) && moves.at(i)->getAttackingStatus()) {
				return true;
			}
		}
	}
	return false;

}


std::ostream& Figure::printInfo(std::ostream & os)
{
	Figure* el;
	os << "Figure" << " Color:" << this->getColor() << " Name:" << this->getName() << " Capture figures:" << std::endl;
	for (unsigned int i = 0; i < takenFigures.size(); i++)
	{
		os << ". --------------------------" << std::endl;
		el = takenFigures.at(i);
		os << i << std::endl
			<< "Name: " << el->getName() << std::endl
			<< "Color:" << el->getColor() << std::endl
			<< "Turn taken:" << el->getTurnNumber() << std::endl;

	}
	os << std::endl << "--------------------------" << std::endl;
	return os;
}


void Figure::getPossibleMoves(vector<Move*>* result)
{
	int row, col, tempRow, tempCol;
	Color curentColor;
	row = position->getRow();
	col = position->getCol();
	curentColor = board->getFigure(row, col)->getColor();


	if (!board->isSpotEmpty(row, col))
	{
		for (unsigned int p = 0; p < rules.size(); p++)
		{
			tempRow = row + rules.at(p)->getRow();
			tempCol = col + rules.at(p)->getCol();

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


