#pragma once
#include "Figure.h"
class Rook :
	virtual public Figure
{
public:
	Rook() = delete;
	Rook& operator =(Rook&) = delete;
	Rook(Rook&) = delete;
	Rook(Position* position, Color color, vector<Figure*>* takenFigures);
	void getPossibleMoves( vector<Move*>* result) override;
	 virtual ~Rook();
};

