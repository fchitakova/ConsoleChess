#include "stdafx.h"
#include "King.h"
#include "Board.h"

#include "stdafx.h"
#include "King.h"
#include "Board.h"


King::King():Figure() {
	this->setName(this->king_figure_name);
	vector<Position>movementRules{Position(-1, -1), Position(-1, 0) ,Position(-1, 1),Position(0, 1) ,Position(1, 1) ,
	Position(1, 0),Position(1, -1),Position(0, -1)
	};
	this->setMovementRules(movementRules);
}


King::King(Board* chessBoard, Color color, Position* position) :Figure(chessBoard, color, position) {
	King();
}

King::King(const King& otherKing) : Figure(otherKing) {
	King();
}

King& King::operator=(const King& otherKing) {
	Figure::operator=(otherKing);
	return *this;
}

King::~King() {}

