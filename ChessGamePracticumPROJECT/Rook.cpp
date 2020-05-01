#include "stdafx.h"
#include "Rook.h"
#include"Board.h"



Rook::Rook() :Figure() {
	this->setName(this->rook_figure_name);
	vector<Position>movementRules{ Position(-1, 0), Position(1, 0),
		Position(0, -1),Position(0, 1)
	};
	this->setMovementRules(movementRules);
}


Rook::Rook(Board* chessBoard, Color color, Position* position) :Figure(chessBoard, color, position) {
	Rook();
}

Rook::Rook(const Rook& otherRook) : Figure(otherRook) {
	Rook();
}

Rook& Rook::operator=(const Rook& otherRook) {
	Figure::operator=(otherRook);
	return *this;
}

Rook::~Rook() {}

