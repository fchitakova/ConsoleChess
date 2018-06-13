#pragma once
#include "Figure.h"
#include"Board.h"
#include<iostream>
class Pawn :
	public Figure
{
public:
	Pawn() = delete;
	Pawn& operator =(Pawn&) = delete;
	Pawn(Pawn&) = delete;
	Pawn(Position* position, Color color, DynamicArray<Figure*>* takenFigures);
	void getPossibleMoves( DynamicArray<Move*>* result)  override;
	void evolveToQueen() {
		throw std::exception("Not implemented");
	}
	virtual ~Pawn();
};

