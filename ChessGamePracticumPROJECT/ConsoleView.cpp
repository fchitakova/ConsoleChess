#include "stdafx.h"
#include "ConsoleView.h"
#include"Color.h"
#include<assert.h>
#include<Windows.h>




void ConsoleView::printRowKing(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*outputStream << king[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}


void ConsoleView::printRowQueen(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*outputStream << queen[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}


void ConsoleView::printRowBishop(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*outputStream << bishop[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}


void ConsoleView::printRowHorse(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*outputStream << horse[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}


void ConsoleView::printRowRook(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*outputStream << rook[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}


void ConsoleView::printRowPawn(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*outputStream << pawn[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}




void ConsoleView::printBoard(Board * board)
{
	for (int row = 0; row < 8; row++)
	{
		*outputStream << row;
		for (int printRow = 0; printRow < 10; printRow++)
		{


			for (int col = 0; col < max_position_size; col++)
			{
				if (printRow == 0) {
					*outputStream << col << ' ' << ' ';
				}
				else {
					*outputStream << ' ' << ' ';
				}

				if (!board->isSpotEmpty(row, col)) {

					string figureName = board->getFigure(row, col)->getName();
					Color figureColor = board->getFigure(row, col)->getColor();

					if (!figureName.compare( "Pawn")) { printRowPawn(printRow, figureColor); }
					else if (!figureName.compare("Rook")) { printRowRook(printRow, figureColor); }
					else if (!figureName.compare("Bishop")) { printRowBishop(printRow, figureColor); }
					else if (!figureName.compare("Horse")) { printRowHorse(printRow, figureColor); }
					else if (!figureName.compare("Queen")) { printRowQueen(printRow, figureColor); }
					else if (!figureName.compare("King")) { printRowKing(printRow, figureColor); }
					else {
						assert(false);
					}
				}
				else {
					if (printRow == 0) {
						*outputStream << "          ";
					}

					else {
						*outputStream << "           ";
					}

				}
				//if (printRow != 0 && col == 0) { std::cout << "&"; }
				*outputStream << "|";


			}
			// printrow closes here

			*outputStream << std::endl;
			*outputStream << " ";
		}

		for (int k = 0; k < max_position_size; k++) {
			*outputStream << "_____________.";
		}
		*outputStream << std::endl;
		// row iterator closes here
	}
}


void ConsoleView::printMessage(const char * message)
{
	*outputStream << message << std::endl;
}


void ConsoleView::readCommand(char * command)
{
	std::cin.getline(command, 14, '\n');
}

std::ostream & ConsoleView::getStream()
{
	return *outputStream;
}


ConsoleView::ConsoleView(std::ostream& outputStream)
{
	this->outputStream = &outputStream;

	this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}


ConsoleView::~ConsoleView()
{
}
