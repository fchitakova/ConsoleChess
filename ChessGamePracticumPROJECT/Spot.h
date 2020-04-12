#pragma once
#include"Figure.h"

class Spot
{
private:
	Figure* figure;
public:
	Spot();
	Spot& operator =(Spot&) = delete;
	Spot(Spot&) = delete;
	bool isSpotEmpty() const;
	void setFigure(Figure* figure);
	Figure* getFigure()const;
	Figure* removeFigure();
	 ~Spot();
};

