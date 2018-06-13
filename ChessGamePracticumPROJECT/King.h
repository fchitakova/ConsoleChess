#pragma once
#include "Figure.h"
class King :
	public Figure
{
public:
	King() = delete;
	King& operator =(King&) = delete;
	King(King&) = delete;
	King(Position* position, Color color, DynamicArray<Figure*>* takenFigures);
	void getPossibleMoves( DynamicArray<Move*>* result)  override;
	virtual~King();
};

