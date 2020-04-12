#pragma once

const int max_position_size = 8;

class Position
{
private:
	int row, col;
public:
	Position();
	Position(int row, int col);
	~Position();

	int getRow()const;
	int getCol()const;
	void setRow(int Row);
	void setCol(int Col);
	static bool isValid(int row, int col);
	bool isValid(const Position * position);
};

