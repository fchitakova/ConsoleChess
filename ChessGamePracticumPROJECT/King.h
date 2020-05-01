#pragma once
#include "Figure.h"
class King :
	public Figure
{
public:
	const char* king_figure_name = "King";

	King();
	King(Board* chessBoard, Color color, Position* position);
	King(const King& otherKing);
	King& operator=(const King& otherKing);
	~King();
};

