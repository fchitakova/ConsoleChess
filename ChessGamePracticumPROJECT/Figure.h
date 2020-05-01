#pragma once
#include"Color.h"
#include"Move.h"

#include <vector>
#include<iostream>

using namespace std;

class Board;
class Figure
{
protected:
	char* name;
	bool taken;
	int turnTaken;

	Board * board;
	Position* currentPosition;
	Color color;

	vector<Position> movementRules;
	vector<Figure> takenFigures;

public:
	Figure();
	Figure(Board*chessBoard,Color color,Position* position);
	Figure(const Figure&);
	Figure& operator =(const Figure&);
	~Figure();

	void setPosition(int row,int col);
	void makeTaken(int turn);
	void makeNonTaken();

	char* getName()const;
	Color getColor()const;
	Position* getCurrentPosition()const;

	bool isTaken()const;
	bool isMoveAllowed(int destionationRow, int destinationColumn);

	vector<Figure> getTakenFigures();
	Figure getLastTakenFigure();
	void addToTakenList(Figure* figure);
	void deleteLastTakenFigure();
	
	void printInfo(std::ostream& os);

protected:
	void setMovementRules(const vector<Position>movementRules);
	void setName(const char* name);
};

