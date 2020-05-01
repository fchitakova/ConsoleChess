#include "stdafx.h"
#include "Horse.h"
#include "Board.h"


Horse::Horse():Figure() {
	this->setName(this->horse_figure_name);
	vector<Position>movementRules{Position(-1, -2) ,Position(1, -2) , Position(-1, 2) ,
	 Position(1, 2), Position(-2, -1),Position(-2, 1),Position(2, -1),Position(2, 1)};
	setMovementRules(movementRules);
}

Horse::Horse(Board* chessBoard, Color color, Position* position) :Figure(chessBoard, color, position){
	Horse();
}

Horse::Horse(const Horse& otherHorse) : Figure(otherHorse) {
	Horse();
}

Horse& Horse::operator=(const Horse& otherHorse) {
	Figure::operator=(otherHorse);
	return *this;
}

Horse::~Horse() {}


