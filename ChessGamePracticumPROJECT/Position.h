#pragma once
class Position
{
	int row, col;
public:
	int getRow()const;
	int getCol()const;
	void setRow(int Row);
	void setCol(int Col);
	Position();
	Position(int row, int col);
	static bool areValid(int row, int col);
	bool areValid(const Position * position);
	 ~Position();
};

