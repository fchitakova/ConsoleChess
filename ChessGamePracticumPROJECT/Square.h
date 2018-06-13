#pragma once
#include"Figure.h"
class Square
{
	Figure* figure;
	bool _isEmpty;
public:
	
	Square& operator =(Square&) = delete;
	Square(Square&) = delete;
	bool isEmpty() const;
	void setFigure(Figure* figure);
	Figure* getFigure()const;
	Figure* removeFigure();
	Square();
	 ~Square();
};

