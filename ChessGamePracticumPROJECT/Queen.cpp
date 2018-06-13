#include "stdafx.h"
#include "Queen.h"
#include"Bishop.h"
#include"Rook.h"
#include"Figure.h"




//************************************
// Method:    Queen
// FullName:  Queen::Queen
// Access:    public 
// Returns:   
// Qualifier: :Figure(position, color, takenFigures), Rook(position, color, takenFigures),Bishop(position, color, takenFigures)
// Parameter: Position * position
// Parameter: Color color
// Parameter: DynamicArray<Figure * > * takenFigures
//************************************
Queen::Queen(Position * position, Color color, DynamicArray<Figure*>* takenFigures) :Figure(position, color, takenFigures),
Rook(position, color, takenFigures),Bishop(position, color, takenFigures)
{
	
	this->setName("Queen");
}

//************************************
// Method:    getPossibleMoves
// FullName:  Queen::getPossibleMoves
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: DynamicArray<Move * > * result
//************************************
void Queen::getPossibleMoves(DynamicArray<Move*>* result)
{


	//Bishop* bish = new Bishop(this->position, this->getColor(), this->takenFigures);
	//Rook* Rk = new Rook(this->position, this->getColor(), this->takenFigures);


	/// Class queen shares one array for storing moves with Rook  and Bishop constructor
	// This it why it's enought to call only one of the getPossibleMoves method (Polymorphic)
	 Rook::getPossibleMoves(result);
	//Bishop::getPossibleMoves(board,result);
	//bishMoves->unionWith(*RKMoves);
	//return RKMoves;
	//delete bish;
	//delete Rk;
}

Queen::~Queen()
{
}
