#include "stdafx.h"
#include "Bishop.h"
#include "Board.h"


Bishop::Bishop():Figure(){
	this->setName(this->bishop_figure_name);
	vector<Position>movementRules {Position(1, 1) ,Position(1, -1),Position(-1, 1),Position(-1, -1) };
	setMovementRules(movementRules);
}

Bishop::Bishop(Board* chessBoard, Color color, Position* position):Figure(chessBoard,color,position) {
	Bishop();
}

Bishop::Bishop(const Bishop& otherBishop):Figure(otherBishop) {
	Bishop();
}

Bishop& Bishop::operator=(const Bishop& otherBishop) {
	Figure::operator=(otherBishop);
	return *this;
}

Bishop::~Bishop() {}

