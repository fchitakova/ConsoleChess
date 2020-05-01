#include "stdafx.h"
#include "Game.h"
#include"Board.h"


Game::Game(IView* view)
{
	this->view = view;
	this->board = new Board();
	this->lastMove = new Move();
	this->turnCounter = 0;
}


bool Game::move(int x1, int y1, int x2, int y2)
{

	// READ BEFORE EDIT
	// CLASS BOARD AND FIGURE ARE TIGHT COUPled
	// you should update board position, and figure coordinates
	// we identify every figure uniquely by it's last coordinates, not by id !
	if (!this->board->isSpotEmpty(x1, y1))
	{
		if (this->board->getFigure(x1, y1)->move(x2, y2))
		{
			vector<Move*> arr;
			this->board->getFigure(x1, y1)->getPossibleMoves(&arr);
			for (unsigned int i = 0; i < arr.size(); i++)
			{
				if (arr.at(i)->getDestinationRow() == x2 && arr.at(i)->getDestinationCol() == y2)
				{
					turnCounter++;
					if (arr.at(i)->getAttackingStatus())
					{
						// the move is attacking othre figure
						board->getFigure(x2, y2)->setTurnNumber(turnCounter);
						this->board->getFigure(x1, y1)->addToTakenList(board->getFigure(x2, y2));
						// move the attacking figure to new position
						board->placeFigure(board->getFigure(x1, y1),x2, y2);
						board->removeFigureFromSpot(x1, y1);
						// update attacking figure new coordinates
						// every figure knows it's coordinates
						board->getFigure(x2, y2)->setRow(x2);
						board->getFigure(x2, y2)->setCol(y2);


						// update lastMove for undo function
						this->lastMove->setStartingRow(x1);
						this->lastMove->setStartingCol(y1);

						this->lastMove->setDestinationRow(x2);
						this->lastMove->setDestionationCol(y2);
						this->lastMove->setAttackStatus(true);
						return true;

					}
					else {
						//the move is over free position
						board->placeFigure(board->getFigure(x1, y1),x2, y2);
						board->removeFigureFromSpot(x1, y1);

						// update attacking figure new coordinates
						// every figure knows it's coordinates
						board->getFigure(x2, y2)->setRow(x2);
						board->getFigure(x2, y2)->setCol(y2);

						// update lastMove for undo function
						this->lastMove->setStartingRow(x1);
						this->lastMove->setStartingCol(y1);

						this->lastMove->setDestinationRow(x2);
						this->lastMove->setDestionationCol(y2);
						this->lastMove->setAttackStatus(false);
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
			view->printMessage("The position you try to move is occupied or under attack,or you could not move that way");
			return false;
		}
		else {
			view->printMessage("The position you try to move is occupied or you could not move that way");
			return false;
		}


	}
	else {
		view->printMessage("you selected empty cell");
		return false;
	}

}


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
				this->view->printBoard(this->board);
			}
			else if (strncmp(command, "undo", 4) == 0) {
				//std::cout << " log :undo hitted";
				notParsed = false;
				this->undo();

				--turn;
				this->view->printBoard(this->board);
			}
			else if (strncmp(command, "printInfoForSpot", 5) == 0) {
				if (command[6] >= '0' && command[6] <= '9' &&command[8] >= '0' && command[8] <= '9') {
					//std::cout << " log :printInfoForSpot  hitted";
					notParsed = false;
					this->printInfoForSpot(command[6] - '0', command[8] - '0');
				}
				
			}
			else if (strncmp(command, "move", 4) == 0) {
				if (command[5] >= '0' && command[5] <= '9' &&command[7] >= '0' && command[7] <= '9' &&command[9] >= '0' && command[9] <= '9' &&command[11] >= '0' && command[11] <= '9')
				{
					if (!this->board->isSpotEmpty(command[5] - '0', command[7] - '0'))
					{
						// make sure tile is tno-emptry

						if (turn % 2 == board->getFigure(command[5] - '0', command[7] - '0')->getColor()) {

							bool success = this->move(command[5] - '0', command[7] - '0', command[9] - '0', command[11] - '0');
							//	std::cout << " log : move" << std::endl;
							if (success) {
								notParsed = false;
								turn++;
								this->view->printBoard(this->board); 
							}
						}
						else {
							view->printMessage("You could not move that figure it's not yours -> F*** you cheater :) ");
						}
						// <---Tile is not emptry closes here>
					}
					else
					{
						view->printMessage(" you selected emptry tile, try again, honey ;) ");
					}
				}
			}

		}


	}
	delete[] command;
}


void Game::printInfoForSpot(int x1, int x2)
{

	//DynamicArray<Figure*>* taken = new DynamicArray<Figure*>();
	if (!board->isSpotEmpty(x1, x2))
	{
		board->getFigure(x1, x2)->printInfo(view->getStream());
		/*
			board->getFigure(x1, x2)->getTakenFiguresList(taken);
			for ( int i = 0; i <taken->get_size() ; i++)
			{
				taken->get_ElementAtIndex(i)->printInfo(view->getStream()) ;
			}*/
	}
	else {
		view->printMessage("The square is empty");
	}
	//delete taken;
}


void Game::undo()
{


	if (this->lastMove->getAttackingStatus())
	{
		Figure* attacking = this->board->getFigure(this->lastMove->getDestinationRow(), this->lastMove->getDestinationCol());

		Figure* attacked = attacking->getLastTakenFigure();
		attacked->makeNonTaken();
		attacking->deleteLastTakenFigure();
		this->board->placeFigure(attacked,lastMove->getDestinationRow(), lastMove->getDestinationCol());

		/*
		Every figure should know it's corrdinates, and the board should know where each figure is
		// Alternative solution->keep unique id for each figure (We may have more than one figure instance of each Type)

		*/
		attacked->setRow(lastMove->getDestinationRow());
		attacked->setCol(lastMove->getDestinationCol());
		this->board->placeFigure(attacking,this->lastMove->getStartingRow(), this->lastMove->getStartingCol());
		attacking->setRow(this->lastMove->getStartingRow());
		attacking->setCol(this->lastMove->getStartingCol());
		attacked = nullptr;
		attacking = nullptr;

	}
	else {
		Figure* moving = this->board->getFigure(this->lastMove->getDestinationRow(), this->lastMove->getDestinationCol());
		this->board->placeFigure(moving,lastMove->getStartingRow(), lastMove->getStartingCol());
		moving->setRow(lastMove->getStartingRow());
		moving->setCol(lastMove->getStartingCol());
		this->board->removeFigureFromSpot(this->lastMove->getDestinationRow(), this->lastMove->getDestinationCol());
		moving = nullptr;
	}
	this->turnCounter = turnCounter - 1;

}


Game::~Game()
{
	delete this->board;
}
