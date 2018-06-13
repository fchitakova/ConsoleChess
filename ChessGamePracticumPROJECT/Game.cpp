#include "stdafx.h"
#include "Game.h"
#include"Board.h"




//************************************
// Method:    Game
// FullName:  Game::Game
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: IView * view
//************************************
Game::Game(IView* view)
{
	this->view = view;
	this->board = new Board();
	this->lastMove = new Move();
	this->turnCounter = 0;


}

//************************************
// Method:    move
// FullName:  Game::move
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: int x1
// Parameter: int y1
// Parameter: int x2
// Parameter: int y2
//************************************
bool Game::move(int x1, int y1, int x2, int y2)
{

	// READ BEFORE EDIT
	// CLASS BOARD AND FIGURE ARE TIGHT COUPled
	// you should update board position, and figure coordinates
	// we identify every figure uniquely by it's last coordinates, not by id !
	if (!this->board->isEmpty(x1, y1))
	{
		if (this->board->getFigure(x1, y1)->move(x2, y2))
		{
			DynamicArray<Move*> arr;
			this->board->getFigure(x1, y1)->getPossibleMoves(&arr);
			for (unsigned int i = 0; i < arr.get_size(); i++)
			{
				if (arr.get_ElementAtIndex(i)->getToRow() == x2 && arr.get_ElementAtIndex(i)->getToCol() == y2)
				{
					turnCounter++;
					if (arr.get_ElementAtIndex(i)->getIsAttacking())
					{
						// the move is attacking othre figure
						board->getFigure(x2, y2)->setTurnTaken(turnCounter);
						this->board->getFigure(x1, y1)->pushTakenFigureList(board->getFigure(x2, y2));
						// move the attacking figure to new position
						board->setFigure(x2, y2, board->getFigure(x1, y1));
						board->makeTileEmpty(x1, y1);
						// update attacking figure new coordinates
						// every figure knows it's coordinates
						board->getFigure(x2, y2)->setRow(x2);
						board->getFigure(x2, y2)->setCol(y2);


						// update lastMove for undo function
						this->lastMove->setFromRow(x1);
						this->lastMove->setFromCol(y1);

						this->lastMove->setToRow(x2);
						this->lastMove->setToCol(y2);
						this->lastMove->setIsAttacking(true);
						return true;

					}
					else {
						//the move is over free position
						board->setFigure(x2, y2, board->getFigure(x1, y1));
						board->makeTileEmpty(x1, y1);

						// update attacking figure new coordinates
						// every figure knows it's coordinates
						board->getFigure(x2, y2)->setRow(x2);
						board->getFigure(x2, y2)->setCol(y2);

						// update lastMove for undo function
						this->lastMove->setFromRow(x1);
						this->lastMove->setFromCol(y1);

						this->lastMove->setToRow(x2);
						this->lastMove->setToCol(y2);
						this->lastMove->setIsAttacking(false);
						return true;
					}

				}
				else {
					// throw fatal logic exception

					//std::cerr << "Error Game figure moves" << std::endl;
					//return false;
				}
			}
			//this->board->
			return false;
		}
		else if (strcmp(this->board->getFigure(x1, y1)->getName(), "King") == 0) {
			view->printMessageNL("The position you try to move is occupied or under attack,or you could not move that way");
			return false;
		}
		else {
			view->printMessageNL("The position you try to move is occupied or you could not move that way");
			return false;
		}


	}
	else {
		view->printMessageNL("you selected empty cell");
		return false;
	}

}

//************************************
// Method:    print
// FullName:  Game::print
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void Game::print()
{
	view->printBoard(this->board);
}

//************************************
// Method:    startGame
// FullName:  Game::startGame
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void Game::startGame()
{
	// TODO: it's View job to extract user input
	// implement View, and inject in view variables for input
	// it's Route:Guard job to validate the input
	// move validation out of here
	// implement mvp model
	char* command = new char[16];
	int turn = 0;
	bool notParsed = true;
	while (true)
	{
		notParsed = true;
		while (notParsed)
		{
			view->readCommand(command);
			if (strncmp(command, "print", 5) == 0) {
				notParsed = false;
				this->print();
			}
			else if (strncmp(command, "undo", 4) == 0) {
				//std::cout << " log :undo hitted";
				notParsed = false;
				this->undo();

				--turn;
				this->print();
			}
			else if (strncmp(command, "stats", 5) == 0) {
				if (command[6] >= '0' && command[6] <= '9' &&command[8] >= '0' && command[8] <= '9') {
					//std::cout << " log :stats  hitted";
					notParsed = false;
					this->stats(command[6] - '0', command[8] - '0');
				}
				
			}
			else if (strncmp(command, "move", 4) == 0) {
				if (command[5] >= '0' && command[5] <= '9' &&command[7] >= '0' && command[7] <= '9' &&command[9] >= '0' && command[9] <= '9' &&command[11] >= '0' && command[11] <= '9')
				{
					if (!this->board->isEmpty(command[5] - '0', command[7] - '0'))
					{
						// make sure tile is tno-emptry

						if (turn % 2 == board->getFigure(command[5] - '0', command[7] - '0')->getColor()) {

							bool success = this->move(command[5] - '0', command[7] - '0', command[9] - '0', command[11] - '0');
							//	std::cout << " log : move" << std::endl;
							if (success) {
								notParsed = false;
								turn++;
								this->print();
							}
						}
						else {
							view->printMessageNL("You could not move that figure it's not yours -> F*** you cheater :) ");
						}
						// <---Tile is not emptry closes here>
					}
					else
					{
						view->printMessageNL(" you selected emptry tile, try again, honey ;) ");
					}
				}
			}

		}


	}
	delete[] command;
}

//************************************
// Method:    stats
// FullName:  Game::stats
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int x1
// Parameter: int x2
//************************************
void Game::stats(int x1, int x2)
{

	//DynamicArray<Figure*>* taken = new DynamicArray<Figure*>();
	if (!board->isEmpty(x1, x2))
	{
		board->getFigure(x1, x2)->printStats(view->getStream());
		/*
			board->getFigure(x1, x2)->getTakenFiguresList(taken);
			for ( int i = 0; i <taken->get_size() ; i++)
			{
				taken->get_ElementAtIndex(i)->printStats(view->getStream()) ;
			}*/
	}
	else {
		view->printMessageNL("The square is empty");
	}
	//delete taken;
}

//************************************
// Method:    undo
// FullName:  Game::undo
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void Game::undo()
{


	if (this->lastMove->getIsAttacking())
	{

		// Bad practice - call getters multiple  times - use local variable
		// saves time in future code refactoring/ editting/
		// makes the code reusable
		DynamicArray<Figure*>* taken = new DynamicArray<Figure*>();
		Figure* attacking = this->board->getFigure(this->lastMove->getToRow(), this->lastMove->getToCol());

		Figure* attacked = attacking->getLastTakenFigure();
		attacked->makeNonTaken();
		attacking->deleteLastTakenFigure();
		this->board->setFigure(lastMove->getToRow(), lastMove->getToCol(), attacked);

		/*
		Every figure should know it's corrdinates, and the board should know where each figure is
		// Alternative solution->keep unique id for each figure (We may have more than one figure instance of each Type)

		*/
		attacked->setRow(lastMove->getToRow());
		attacked->setCol(lastMove->getToCol());
		this->board->setFigure(this->lastMove->getFromRow(), this->lastMove->getFromCol(), attacking);
		attacking->setRow(this->lastMove->getFromRow());
		attacking->setCol(this->lastMove->getFromCol());
		attacked = nullptr;
		attacking = nullptr;

	}
	else {
		Figure* moving = this->board->getFigure(this->lastMove->getToRow(), this->lastMove->getToCol());
		this->board->setFigure(lastMove->getFromRow(), lastMove->getFromCol(), moving);
		moving->setRow(lastMove->getFromRow());
		moving->setCol(lastMove->getFromCol());
		this->board->makeTileEmpty(this->lastMove->getToRow(), this->lastMove->getToCol());
		moving = nullptr;
	}
	this->turnCounter = turnCounter - 1;

}


Game::~Game()
{
	delete this->board;
}
