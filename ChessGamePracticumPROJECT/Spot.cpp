#include "stdafx.h"
#include "Spot.h"


bool Spot::isSpotEmpty() const
{
	return this->figure == nullptr;
}

void Spot::setFigure(Figure* figure)
{
	this->figure = figure;
}


Figure * Spot::getFigure() const
{
	return this->figure;
}

Figure * Spot::removeFigure()
{
	Figure* result = this->figure;
	this->figure = nullptr;
	return result;
}

Spot::Spot(){
	this->figure = NULL;
}


 Spot::~Spot()
{
	 std::cout << "delete square";
}
