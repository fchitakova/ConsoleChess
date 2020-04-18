#pragma once
#include "Figure.h"
class King :
	public Figure
{
public:
	King() = delete;
	King& operator =(King&) = delete;
	King(King&) = delete;
	King(Position* position, Color color, vector<Figure*>* takenFigures);
	void getPossibleMoves( vector<Move*>* result)  override;
	virtual~King();
};

