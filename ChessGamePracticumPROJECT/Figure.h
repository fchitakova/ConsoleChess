#pragma once
#include"Color.h"
#include"DynamicArray.h"
#include"Move.h"


#include<iostream>
class IBoard;
class Figure
{
private:
	
protected:
	char* name;
	IBoard * board;
	Position* position;
	DynamicArray<Position*> rules;
	DynamicArray<Figure*>* takenFigures;
private:

	
	Color color;
	bool isTaken_m;
	int turnTaken;

public:
	Figure() = delete;
	Figure& operator =(Figure&) = delete;
	Figure(Figure&) = delete;

	Figure(Position* position, Color color, DynamicArray<Figure*>*);
	char*  getName() const;
	void  setName(const char* name);
	Color getColor()const;
	int getRow() const;
	int getCol()const;
	void setRow(int row);
	void setCol(int col);
	int getTurnTaken()const;
	void setTurnTaken(int turn);
	bool setBoard(IBoard * board);
	bool isTaken()const;
	void makeNonTaken();

	
	std::ostream& printStats(std::ostream& os);
	void getTakenFiguresList(DynamicArray<Figure*>* res);
	void pushTakenFigureList(Figure* fig);

	void deleteLastTakenFigure();

	//void deleteLastTakenFigureL();

	Figure * getLastTakenFigure();

	//Figure * getLastTakenFigureList();
	
	virtual bool move(int row, int col);
	//void  printStats(std::ostream& os);

	 virtual void getPossibleMoves( DynamicArray<Move*>* result) ;
	 virtual ~Figure();

protected:
	//Figure();
	//virtual void setPosition(Position* position) =0;

};

