#include "stdafx.h"
#include "Figure.h"
#include "Position.h"
#include "Board.h"

#include<iostream>

Figure::Figure()
{
	this->board = nullptr;
	this->currentPosition = nullptr;
	this->taken = false;
	this->turnTaken = 0;
}


Figure::Figure(Board* chessBoard, Color color, Position* position)
{
	this->board = chessBoard;
	this->color = color;
	this->currentPosition = position;
	this->turnTaken = 0;
	this->taken = false;
}

Figure::Figure(const Figure& otherFigure) {
	this->name = new char[strlen(otherFigure.name) + 1];
	strcpy_s(this->name, strlen(otherFigure.name) + 1, otherFigure.name);
	this->taken = otherFigure.taken;
	this->turnTaken = otherFigure.turnTaken;
	this->board = otherFigure.board;
	this->currentPosition = otherFigure.currentPosition;
	this->color = otherFigure.color;
	this->takenFigures = otherFigure.takenFigures;
	this->movementRules = otherFigure.movementRules;
}

Figure& Figure::operator = (const Figure& otherFigure) {
	if (this != &otherFigure) {
		delete this;
		Figure(otherFigure);
	}
	return *this;
}

Figure::~Figure() {
	if (currentPosition != nullptr) {
		delete currentPosition;
	}
	if (this->name != nullptr) {
		delete[]name;
	}
}


void Figure::setPosition(int row, int col) {
	this->currentPosition->setPosition(row, col);
}

void Figure::makeTaken(int turn)
{
   this->taken = true;
   this->turnTaken = turn;
}

void Figure::makeNonTaken() {
	this->taken = false;
}

char* Figure::getName()const {
	return this->name;
}

Color Figure::getColor()const {
	return this->color;
}

Position* Figure::getCurrentPosition()const {
	return this->currentPosition;
}


bool Figure::isTaken() const
{
	return this->taken;
}

bool Figure::isMoveAllowed(int destinationRow, int destinationCol)
{
	bool validDestinationSpot = this->board->isSpotValid(destinationRow, destinationCol);
	bool isDestinationReachableByFigure = false;
	for (unsigned int i = 0; i < movementRules.size(); i++)
	{
		bool isDestinationReachableByFigure = ((movementRules.at(i).getRow() + this->currentPosition->getRow()) == destinationRow)
			&& ((movementRules.at(i).getCol() + this->currentPosition->getCol()) == destinationCol);
	}
	return validDestinationSpot && isDestinationReachableByFigure;
}

vector<Figure> Figure::getTakenFigures()
{
	return this->takenFigures;
}

Figure Figure::getLastTakenFigure()
{
	return takenFigures.at(takenFigures.size() - 1);
}


void Figure::addToTakenList(Figure * figure)
{
	takenFigures.push_back(*figure);
}

void Figure::deleteLastTakenFigure()
{
	takenFigures.erase(takenFigures.end() - 1);
}



void Figure::printInfo(std::ostream & os)
{
	os << "Figure" << " Color:" << this->getColor() << " Name:" << this->getName() << " Capture figures:\n";
	for (unsigned int i = 0; i < takenFigures.size(); i++)
	{
		os << ". --------------------------";
		
		Figure* ithTakenFigure = &takenFigures.at(i);
		os  << "\nName: " << ithTakenFigure->name
			<< "\nColor:" << ithTakenFigure->color
			<< "\nTurn taken:" << ithTakenFigure->turnTaken;

	}
	os << "\n--------------------------\n";
}

void Figure::setMovementRules(const vector<Position>movementRules) {
	this->movementRules = movementRules;
}

void Figure::setName(const char* name) {
	int size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);
}


