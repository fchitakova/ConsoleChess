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


bool Game::move(int startRow, int startCol, int destinationRow, int destinationCol)
{
	if (board->isSpotEmpty(startRow, startCol)) 
	{
		view->printMessage("you selected empty cell");
		return false;
	}

	Figure* figureToMove = this->board->getFigure(startRow, startCol);
	if (!figureToMove->isMoveAllowed(destinationRow, destinationCol))
	{
		view->printMessage("The position you try to move is occupied or you could not move that way");
		return false;
	}

	bool isDestinationSpotTakenByOponent = board->isSpotEmpty(destinationRow, destinationCol) 
			&& board->getFigure(destinationRow, destinationCol)->getColor() != figureToMove->getColor();
	
	turnCounter++;

	bool attackStatus = false;
	if (!isDestinationSpotTakenByOponent)
	{
	    Figure* takenFigure = board->getFigure(destinationRow, destinationCol);
		figureToMove->addToTakenList(takenFigure);
		takenFigure->makeTaken(turnCounter);
		attackStatus = true;
	}	

	this->lastMove->setStartPosition(startRow, startCol);
	this->lastMove->setDestinationPosition(destinationRow, destinationCol);
	this->lastMove->setAttackStatus(attackStatus);
	
	return true;
}


void Game::changeFigurePositionInBoard(Figure* figure, int destinationRow, int destinationCol) {
	this->board->placeFigure(figure, destinationRow, destinationCol);

	this->board->removeFigureFromSpot(figure->getCurrentPosition, startCol);
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
			board->getFigure(x1, x2)->getTakenFigures(taken);
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

	if (this->lastMove->isAttacking())
	{
		Figure* attacking = this->board->getFigure(this->lastMove->getDestinationRow(), this->lastMove->getDestinationCol());

		Figure* attacked = &attacking->getLastTakenFigure();
		attacked->makeNonTaken();
		attacking->deleteLastTakenFigure();
		this->board->placeFigure(attacked,lastMove->getDestinationRow(), lastMove->getDestinationCol());

		/*
		Every figure should know it's corrdinates, and the board should know where each figure is
		// Alternative solution->keep unique id for each figure (We may have more than one figure instance of each Type)

		*/
		attacked->setPosition(lastMove->getDestinationRow(), lastMove->getDestinationCol());
		this->board->placeFigure(attacking,this->lastMove->getStartingRow(), this->lastMove->getStartingCol());
		attacking->setPosition(lastMove->getStartingRow(), lastMove->getStartingCol());
		attacked = nullptr;
		attacking = nullptr;

	}
	else {
		Figure* moving = this->board->getFigure(this->lastMove->getDestinationRow(), this->lastMove->getDestinationCol());
		this->board->placeFigure(moving,lastMove->getStartingRow(), lastMove->getStartingCol());
		moving->setPosition(lastMove->getStartingRow(), lastMove->getStartingCol());
		this->board->removeFigureFromSpot(this->lastMove->getDestinationRow(), this->lastMove->getDestinationCol());
		moving = nullptr;
	}
	this->turnCounter = turnCounter - 1;

}


Game::~Game()
{
	delete this->board;
}
