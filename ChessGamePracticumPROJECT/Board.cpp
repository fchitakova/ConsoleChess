#include "stdafx.h"

#include "Board.h"


Board::Board()
{
	allocateBoardMemory();
	initializeBoardPositions();
	placeFigures();
}

void Board::allocateBoardMemory() {
	this->board = new Spot * [max_position_size];
	for (int i = 0; i < max_position_size; i++)
	{
		this->board[i] = new Spot[max_position_size];
	}
}

void Board::initializeBoardPositions() {
	for (int i = 0; i < max_position_size; i++) {
		for (int j = 0; j < max_position_size; j++) {
			board[i][j].setPosition(new Position(i, j));
		}
	}
}

void Board::placeFigures()
{
	board[0][4].setFigure(new King(this, BLACK, new Position(0,4)));
	board[max_position_size - 1][4].setFigure(new King(this, WHITE, new Position(max_position_size - 1, 4)));
	 
	board[0][3].setFigure(new Queen(this, BLACK, new Position(0, 3)));
	board[max_position_size - 1][3].setFigure(new Queen(this, WHITE, new Position(max_position_size - 1, 3)));
	
	board[0][2].setFigure(new Bishop(this, BLACK, new Position(0, 2)));
	board[0][5].setFigure(new Bishop(this, BLACK, new Position(0, 5)));
	board[max_position_size - 1][2].setFigure(new Bishop(this, WHITE, new Position(max_position_size - 1, 2)));
	board[max_position_size - 1][5].setFigure(new Bishop(this,WHITE, new Position(max_position_size - 1, 5)));
	
	board[0][1].setFigure(new Horse(this, BLACK, new Position(0, 1)));
	board[0][6].setFigure(new Horse(this,BLACK, new Position(0, 6)));
	board[max_position_size - 1][1].setFigure(new Horse(this, WHITE, new Position(max_position_size - 1, 1)));
	board[max_position_size - 1][6].setFigure(new Horse(this,WHITE, new Position(max_position_size - 1, 6)));
	
	board[0][0].setFigure(new Rook(this, BLACK, new Position(0, 0)));
	board[0][7].setFigure(new Rook(this, BLACK, new Position(0, 7)));
	board[max_position_size - 1][0].setFigure(new Rook(this, WHITE, new Position(max_position_size - 1, 0)));
	board[max_position_size - 1][7].setFigure(new Rook(this, WHITE, new Position(max_position_size - 1, 7)));

	for (int i = 0; i < max_position_size; i++)
	{
		board[1][i].setFigure(new Pawn(this, BLACK, new Position(1, i)));
		board[max_position_size - 2][i].setFigure(new Pawn(this, WHITE, new Position(max_position_size - 2, i)));
	}
}

Board::~Board()
{
	for (int i  = 0; i < max_position_size; i++)
	{
			delete board[i];
	}
	delete board;
	board = nullptr;
}


bool Board::isSpotEmpty(int row, int col) {
	return board[row][col].isSpotEmpty();
}

Figure * Board::getFigure(int row, int col)
{
	return board[row][col].getFigure();
}

bool Board::isSpotValid(int row, int col)
{
	if (row < 0 || row >= max_position_size || col < 0 || col >= max_position_size) {
		return false;
	}
	return true;
}



bool Board::placeFigure(Figure* figure,int row, int col)
{
	if (isSpotValid(row,col) && figure!= nullptr){
		this->board[row][col].setFigure(figure);
		this->board.
		figure->setPosition(row, col);
		return true;

	}
	return false;
}

void Board::removeFigureFromSpot(int row, int col)
{
	this->board[row][col].removeFigure();
}
