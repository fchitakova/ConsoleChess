#pragma once
#include "Figure.h"

class Bishop :
	virtual public Figure
{
public:
	Bishop() = delete;
	Bishop(Bishop&) = delete;
	Bishop(Position* position, Color color, DynamicArray<Figure*>* takenFigures);
	Bishop& operator =(Bishop&) = delete;
	void getPossibleMoves(DynamicArray<Move*>* result) override;
	virtual ~Bishop();
};

