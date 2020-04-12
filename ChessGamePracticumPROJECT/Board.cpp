#include "stdafx.h"

#include "Board.h"



void Board::placeFigures()
{

	for (int i = 0; i < 4 * max_position_size; i++)
	{
		arraysToDelete->push_back(new DynamicArray<Figure*>());
	}
	// place kings
	board[0][4].setFigure(new King(new Position(0, 4), BLACK, arraysToDelete->get_ElementAtIndex(0)));
	board[max_position_size - 1][4].setFigure(new King(new Position(max_position_size - 1, 4),WHITE, arraysToDelete->get_ElementAtIndex(1)));
	// place queens
	board[0][3].setFigure(new Queen(new Position(0, 3), BLACK, arraysToDelete->get_ElementAtIndex(2)));
	board[max_position_size - 1][3].setFigure(new Queen(new Position(max_position_size - 1, 3), WHITE, arraysToDelete->get_ElementAtIndex(3)));
	// place bishops
	board[0][2].setFigure(new Bishop(new Position(0, 2), BLACK, arraysToDelete->get_ElementAtIndex(4)));
	board[max_position_size - 1][2].setFigure(new Bishop(new Position(max_position_size - 1, 2), WHITE, arraysToDelete->get_ElementAtIndex(5)));
	board[0][5].setFigure(new Bishop(new Position(0, 5), BLACK, arraysToDelete->get_ElementAtIndex(6)));
	board[max_position_size - 1][5].setFigure(new Bishop(new Position(max_position_size - 1, 5), WHITE, arraysToDelete->get_ElementAtIndex(7)));
	// place horses 
	board[0][1].setFigure(new Horse(new Position(0, 1), BLACK, arraysToDelete->get_ElementAtIndex(8)));
	board[max_position_size - 1][1].setFigure(new Horse(new Position(max_position_size - 1, 1), WHITE, arraysToDelete->get_ElementAtIndex(9)));
	board[0][6].setFigure(new Horse(new Position(0, 6), BLACK, arraysToDelete->get_ElementAtIndex(10)));
	board[max_position_size - 1][6].setFigure(new Horse(new Position(max_position_size - 1, 6), WHITE, arraysToDelete->get_ElementAtIndex(11)));
	// place rooks
	board[0][0].setFigure(new Rook(new Position(0, 0), BLACK, arraysToDelete->get_ElementAtIndex(12)));
	board[max_position_size - 1][0].setFigure(new Rook(new Position(max_position_size - 1, 0), WHITE, arraysToDelete->get_ElementAtIndex(13)));
	board[0][7].setFigure(new Rook(new Position(0, 7), BLACK, arraysToDelete->get_ElementAtIndex(14)));
	board[max_position_size - 1][7].setFigure(new Rook(new Position(max_position_size - 1, 7), WHITE, arraysToDelete->get_ElementAtIndex(15)));

	// deguf figureboard[5][3].setFigure(new Rook(new Position(5, 3), BLACK));


	// Debugfigure for rook board[6][3].setFigure(new Rook(new Position(6, 3), WHITE));

	// place pawns
	for (int i = 0; i < max_position_size; i++)
	{
		board[1][i].setFigure(new Pawn(new Position(1, i), BLACK, arraysToDelete->get_ElementAtIndex(16 + i)));
		board[max_position_size - 2][i].setFigure(new Pawn(new Position(max_position_size - 2, i), WHITE, arraysToDelete->get_ElementAtIndex(4 * (max_position_size) - i - 1)));
	}


	for (int i = 0; i < max_position_size; i++)
	{
		figuresToDelete->push_back(board[0][i].getFigure());
		figuresToDelete->push_back(board[1][i].getFigure());
		figuresToDelete->push_back(board[max_position_size - 1][i].getFigure());
		figuresToDelete->push_back(board[max_position_size - 2][i].getFigure());
	}
	for (unsigned int i = 0; i < figuresToDelete->get_size(); i++)
	{
		figuresToDelete->get_ElementAtIndex(i)->setBoard(this);
	}
}

//void Board::initSquares()
//{
//	for (int i = 0; i < max_position_size; i++)
//	{
//		for (size_t j = 0; j < max_position_size; j++)
//		{
//			board[i][j] = new Square();
//		}
//	}
//}
//************************************
// Method:    Board

Board::Board()
{
	board = new Spot*[max_position_size];
	for (int i = 0; i < max_position_size; i++)
	{

		board[i] = new Spot[max_position_size];
	}
	//	initSquares();
	arraysToDelete = new DynamicArray< DynamicArray<Figure*>*>();
	figuresToDelete = new DynamicArray<Figure*>();
	placeFigures();
}


bool Board::isSpotEmpty(int row, int col) {
	return board[row][col].isSpotEmpty();
}

Figure * Board::getFigure(int row, int col)
{
	return board[row][col].getFigure();
}


bool Board::placeFigure(Figure* fig,int row, int col)
{
	if (row > -1 && row < max_position_size && col >-1 && col < max_position_size && fig != nullptr)
	{
		this->board[row][col].setFigure(fig);
		return true;

	}
	return false;
}

bool Board::removeFigureFromSpot(int row, int col)
{
	if (row > -1 && row < max_position_size && col >-1 && col < max_position_size)
	{

		this->board[row][col].removeFigure();
		return true;
	}
	return false;
}
Board::~Board()
{
	Figure* temp;
	/*for (int i = 0; i < 4* board_size; i++)
	{

		delete this->arraysToDelete->get_ElementAtIndex(i);
		temp = this->figuresToDelete->get_ElementAtIndex(i);
		delete temp;
	}*/
	delete arraysToDelete;
	delete figuresToDelete;
	/*for (int i  = 0; i < board_size; i++)
	{
			delete board[i];




	}*/
	delete[] board;

}
