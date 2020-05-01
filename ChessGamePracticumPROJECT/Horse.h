#pragma once
#include "Figure.h"
class Horse :
	public Figure
{
public:
	const char* horse_figure_name = "Horse";

	Horse();
	Horse(Board* chessBoard, Color color, Position* position);
	Horse(const Horse& otherHorse);
	Horse& operator=(const Horse& otherHorse);
	~Horse();

};

