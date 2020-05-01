#include "stdafx.h"
#include "Queen.h"
#include"Figure.h"



Queen::Queen() :Figure() {
	this->setName(this->queen_figure_name);
	vector<Position>movementRules{ Position(-1, 0), Position(1, 0),
		Position(0, -1),Position(0, 1),Position(1, 1) ,Position(1, -1),Position(-1, 1),Position(-1, -1)
	};
	this->setMovementRules(movementRules);
}


Queen::Queen(Board* chessBoard, Color color, Position* position) :Figure(chessBoard, color, position) {
	Queen();
}

Queen::Queen(const Queen& otherQueen) : Figure(otherQueen) {
	Queen();
}

Queen& Queen::operator=(const Queen& otherQueen) {
	Figure::operator=(otherQueen);
	return *this;
}

Queen::~Queen() {}

