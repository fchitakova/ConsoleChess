#pragma once
#include "Figure.h"
class Rook : public Figure
{
public:
	const char* rook_figure_name = "Rook";

	Rook();
	Rook(Board* chessBoard, Color color, Position* position);
	Rook(const Rook& otherRook);
	Rook& operator=(const Rook& otherHorse);
	~Rook();
};

