#pragma once
#include "Figure.h"
class Horse :
	public Figure
{
public:
	Horse() = delete;
	Horse& operator =(Horse&) = delete;
	Horse(Horse&) = delete;
	Horse(Position* position, Color color, DynamicArray<Figure*>* takenFigures);
	//virtual void getPossibleMoves(Board* board, DynamicArray<Move*>* result)  ;
	virtual ~Horse();
};

