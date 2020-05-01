#pragma once
#include "Figure.h"

class Queen :public Figure {
public:
	const char* queen_figure_name = "Queen";

	Queen();
	Queen(Board* chessBoard, Color color, Position* position);
	Queen(const Queen& otherQueen);
	Queen& operator=(const Queen& otherQueen);
	~Queen();
};
