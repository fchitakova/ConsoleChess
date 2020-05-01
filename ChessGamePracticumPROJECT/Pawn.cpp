#include "stdafx.h"
#include "Pawn.h"
#include"Board.h"


Pawn::Pawn() :Figure() {
	this->setName(this->pawn_figure_name);
	vector<Position>movementRules{Position(1, 0),Position(1, -1),Position(1, 1) };
	setMovementRules(movementRules);
}

Pawn::Pawn(Board* chessBoard, Color color, Position* position) :Figure(chessBoard, color, position) {
	Pawn();
}

Pawn::Pawn(const Pawn& otherPawn) : Figure(otherPawn) {
	Pawn();
}

Pawn& Pawn::operator=(const Pawn& otherPawn) {
	Figure::operator=(otherPawn);
	return *this;
}

Pawn::~Pawn() {}