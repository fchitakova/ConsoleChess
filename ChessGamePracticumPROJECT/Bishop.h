#pragma once
#include "Figure.h"

class Bishop :
	 public Figure
{
public:
	const char* bishop_figure_name = "Bishop";

	Bishop();
	Bishop(Board* chessBoard, Color color, Position* position);
	Bishop(const Bishop& otherBishop);
	Bishop& operator=(const Bishop& otherBishop);
	~Bishop();
};

