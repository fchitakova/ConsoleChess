#pragma once
#include "Figure.h"
class Rook :
	virtual public Figure
{
public:
	Rook() = delete;
	Rook& operator =(Rook&) = delete;
	Rook(Rook&) = delete;
	Rook(Position* position, Color color, DynamicArray<Figure*>* takenFigures);
	void getPossibleMoves( DynamicArray<Move*>* result) override;
	 virtual ~Rook();
};

