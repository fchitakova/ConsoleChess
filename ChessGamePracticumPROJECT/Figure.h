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
	Board * board;
	Position* position;
	vector<Position*> rules;
	vector<Figure*> takenFigures;
private:
	Color color;
	bool isTaken_m;
	int turnTaken;

public:
	Figure() = delete;
	Figure& operator =(Figure&) = delete;
	Figure(Figure&) = delete;

	Figure(Position* position, Color color, vector<Figure*>*);
	char*  getName() const;
	void  setName(const char* name);
	Color getColor()const;
	int getRow() const;
	int getCol()const;
	void setRow(int row);
	void setCol(int col);
	int getTurnNumber()const;
	void setTurnNumber(int turn);
	bool setBoard(Board * board);
	bool isTaken()const;
	void makeNonTaken();

	
	std::ostream& printInfo(std::ostream& os);
	void getTakenFiguresList(vector<Figure*>* res);
	void addToTakenList(Figure* figure);

	void deleteLastTakenFigure();

	//void deleteLastTakenFigureL();

	Figure * getLastTakenFigure();

	//Figure * getLastTakenFigureList();
	
	virtual bool move(int row, int col);
	//void  printInfo(std::ostream& os);

	 virtual void getPossibleMoves(vector<Move*>*result);
	 virtual ~Figure();

protected:
	//Figure();
	//virtual void setPosition(Position* position) =0;

};

