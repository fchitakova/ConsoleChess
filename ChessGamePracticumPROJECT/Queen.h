#pragma once
#include "Figure.h"
#include"Bishop.h"
#include"Rook.h"
class Queen :
	public Rook, public Bishop
{
	/// Class queen shares one array for storing moves with Rook  and Bishop constructor
	
public:
	Queen() = delete;
	Queen& operator =(Queen&) = delete;
	Queen(Queen&) = delete;

	Queen(Position* position, Color color, vector<Figure*>* takenFigures);
	void getPossibleMoves( vector<Move*>* result)  override;
	virtual ~Queen();
};

