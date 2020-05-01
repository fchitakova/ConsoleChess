#pragma once
#include "Figure.h"
#include"Board.h"
#include<iostream>
class Pawn :
	public Figure
{
public:
	const char* pawn_figure_name = "Pawn";

	Pawn();
	Pawn(Board* chessBoard, Color color, Position* position);
	Pawn(const Pawn& otherPawn);
	Pawn& operator=(const Pawn& otherKing);
	~Pawn();
};
