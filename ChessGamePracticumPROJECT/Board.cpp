#include "stdafx.h"

#include"Figure.h"
#include"King.h"
#include"Queen.h"
#include"Bishop.h"
#include"Horse.h"
#include"Rook.h"
#include"Pawn.h"
#include"Square.h"
#include "Board.h"




//************************************
// Method:    placeFigures
// FullName:  Board::placeFigures
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void Board::placeFigures()
{

	for (int i = 0; i < 4 * GlobalVaribles::SIZE; i++)
	{
		arraysToDelete->push_back(new DynamicArray<Figure*>);
	}
	// place kings
	board[0][4].setFigure(new King(new Position(0, 4), BLACK, arraysToDelete->get_ElementAtIndex(0)));
	board[GlobalVaribles::SIZE - 1][4].setFigure(new King(new Position(GlobalVaribles::SIZE - 1, 4), WHITE, arraysToDelete->get_ElementAtIndex(1)));
	// place queens
	board[0][3].setFigure(new Queen(new Position(0, 3), BLACK, arraysToDelete->get_ElementAtIndex(2)));
	board[GlobalVaribles::SIZE - 1][3].setFigure(new Queen(new Position(GlobalVaribles::SIZE - 1, 3), WHITE, arraysToDelete->get_ElementAtIndex(3)));
	// place bishops
	board[0][2].setFigure(new Bishop(new Position(0, 2), BLACK, arraysToDelete->get_ElementAtIndex(4)));
	board[GlobalVaribles::SIZE - 1][2].setFigure(new Bishop(new Position(GlobalVaribles::SIZE - 1, 2), WHITE, arraysToDelete->get_ElementAtIndex(5)));
	board[0][5].setFigure(new Bishop(new Position(0, 5), BLACK, arraysToDelete->get_ElementAtIndex(6)));
	board[GlobalVaribles::SIZE - 1][5].setFigure(new Bishop(new Position(GlobalVaribles::SIZE - 1, 5), WHITE, arraysToDelete->get_ElementAtIndex(7)));
	// place horses 
	board[0][1].setFigure(new Horse(new Position(0, 1), BLACK, arraysToDelete->get_ElementAtIndex(8)));
	board[GlobalVaribles::SIZE - 1][1].setFigure(new Horse(new Position(GlobalVaribles::SIZE - 1, 1), WHITE, arraysToDelete->get_ElementAtIndex(9)));
	board[0][6].setFigure(new Horse(new Position(0, 6), BLACK, arraysToDelete->get_ElementAtIndex(10)));
	board[GlobalVaribles::SIZE - 1][6].setFigure(new Horse(new Position(GlobalVaribles::SIZE - 1, 6), WHITE, arraysToDelete->get_ElementAtIndex(11)));
	// place rooks
	board[0][0].setFigure(new Rook(new Position(0, 0), BLACK, arraysToDelete->get_ElementAtIndex(12)));
	board[GlobalVaribles::SIZE - 1][0].setFigure(new Rook(new Position(GlobalVaribles::SIZE - 1, 0), WHITE, arraysToDelete->get_ElementAtIndex(13)));
	board[0][7].setFigure(new Rook(new Position(0, 7), BLACK, arraysToDelete->get_ElementAtIndex(14)));
	board[GlobalVaribles::SIZE - 1][7].setFigure(new Rook(new Position(GlobalVaribles::SIZE - 1, 7), WHITE, arraysToDelete->get_ElementAtIndex(15)));

	// deguf figureboard[5][3].setFigure(new Rook(new Position(5, 3), BLACK));


	// Debugfigure for rook board[6][3].setFigure(new Rook(new Position(6, 3), WHITE));

	// place pawns
	for (int i = 0; i < GlobalVaribles::SIZE; i++)
	{
		board[1][i].setFigure(new Pawn(new Position(1, i), BLACK, arraysToDelete->get_ElementAtIndex(16 + i)));
		board[GlobalVaribles::SIZE - 2][i].setFigure(new Pawn(new Position(GlobalVaribles::SIZE - 2, i), WHITE, arraysToDelete->get_ElementAtIndex(4 * (GlobalVaribles::SIZE) - i - 1)));
	}


	for (int i = 0; i < GlobalVaribles::SIZE; i++)
	{
		figuresToDelete->push_back(board[0][i].getFigure());
		figuresToDelete->push_back(board[1][i].getFigure());
		figuresToDelete->push_back(board[GlobalVaribles::SIZE - 1][i].getFigure());
		figuresToDelete->push_back(board[GlobalVaribles::SIZE - 2][i].getFigure());
	}
	for (unsigned int i = 0; i < figuresToDelete->get_size(); i++)
	{
		figuresToDelete->get_ElementAtIndex(i)->setBoard(this);
	}
}

//void Board::initSquares()
//{
//	for (int i = 0; i < GlobalVaribles::SIZE; i++)
//	{
//		for (size_t j = 0; j < GlobalVaribles::SIZE; j++)
//		{
//			board[i][j] = new Square();
//		}
//	}
//}
//************************************
// Method:    Board
// FullName:  Board::Board
// Access:    public 
// Returns:   
// Qualifier:
//************************************
Board::Board()
{
	board = new Square*[GlobalVaribles::SIZE];
	for (int i = 0; i < GlobalVaribles::SIZE; i++)
	{

		board[i] = new Square[GlobalVaribles::SIZE];
	}
	//	initSquares();
	arraysToDelete = new DynamicArray< DynamicArray<Figure*>* >();
	figuresToDelete = new DynamicArray<Figure*>();
	placeFigures();
}

//************************************
// Method:    isEmpty
// FullName:  Board::isEmpty
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: int row
// Parameter: int col
//************************************
bool Board::isEmpty(int row, int col) {
	return board[row][col].isEmpty();
}
Figure * Board::getFigure(int row, int col)
{
	return board[row][col].getFigure();
}
//************************************
// Method:    setFigure
// FullName:  Board::setFigure
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: int row
// Parameter: int col
// Parameter: Figure * fig
//************************************
bool Board::setFigure(int row, int col, Figure * fig)
{
	if (row > -1 && row < GlobalVaribles::SIZE && col >-1 && col < GlobalVaribles::SIZE && fig != nullptr)
	{
		this->board[row][col].setFigure(fig);
		return true;

	}
	return false;
}
//************************************
// Method:    makeTileEmpty
// FullName:  Board::makeTileEmpty
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: int row
// Parameter: int col
//************************************
bool Board::makeTileEmpty(int row, int col)
{
	if (row > -1 && row < GlobalVaribles::SIZE && col >-1 && col < GlobalVaribles::SIZE)
	{

		this->board[row][col].removeFigure();
		return true;
	}
	return false;
}
Board::~Board()
{
	Figure* temp;
	/*for (int i = 0; i < 4* GlobalVaribles::SIZE; i++)
	{

		delete this->arraysToDelete->get_ElementAtIndex(i);
		temp = this->figuresToDelete->get_ElementAtIndex(i);
		delete temp;
	}*/
	delete arraysToDelete;
	delete figuresToDelete;
	/*for (int i  = 0; i < GlobalVaribles::SIZE; i++)
	{
			delete board[i];




	}*/
	delete[] board;

}
