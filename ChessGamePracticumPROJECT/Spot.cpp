#include "stdafx.h"
#include "Spot.h"


Spot::Spot() {
	this->figure = nullptr;
	this->spotPosition = nullptr;
}


Spot::~Spot() {
	if (spotPosition!=nullptr) {
		delete spotPosition;
	}
	if (figure != nullptr) {
		delete figure;
	}
}

void Spot::setFigure(Figure* figure)
{
	this->figure = figure;
	this->spotPosition = figure->getCurrentPosition();
}

void Spot::setPosition(Position* spotPosition) {
	this->spotPosition = spotPosition;
}

Figure* Spot::getFigure() const
{
	return this->figure;
}

bool Spot::isSpotEmpty() const
{
	return this->figure == nullptr;
}



void Spot::removeFigure()
{
	this->figure = nullptr;
}

