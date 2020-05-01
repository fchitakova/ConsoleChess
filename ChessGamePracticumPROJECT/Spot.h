#pragma once
#include"Figure.h"

class Spot
{
private:
	Position* spotPosition;
	Figure* figure;
public:
	Spot();
	~Spot();

	void setFigure(Figure* figure);
	void setPosition(Position* spotPosition);

	Figure* getFigure()const;
	bool isSpotEmpty() const;

	void removeFigure();
};

