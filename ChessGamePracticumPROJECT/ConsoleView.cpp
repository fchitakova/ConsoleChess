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
	*s << king[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}


void ConsoleView::printRowQueen(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*s << queen[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}


void ConsoleView::printRowBishop(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*s << bishop[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}


void ConsoleView::printRowHorse(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*s << horse[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}


void ConsoleView::printRowRook(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*s << rook[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}


void ConsoleView::printRowPawn(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*s << pawn[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}




void ConsoleView::printBoard(Board * board)
{
	char* figName;
	Color figColor;
	for (int row = 0; row < 8; row++)
	{
		*s << row;
		for (int printRow = 0; printRow < 10; printRow++)
		{


			for (int col = 0; col < max_position_size; col++)
			{
				if (printRow == 0) {
					*s << col << ' ' << ' ';
				}
				else {
					*s << ' ' << ' ';
				}

				if (!board->isSpotEmpty(row, col)) {
					// the board position is non empty
					figName = board->getFigure(row, col)->getName();
					figColor = board->getFigure(row, col)->getColor();
					if (!strcmp(figName, "Pawn")) { printRowPawn(printRow, figColor); }
					else if (!strcmp(figName, "Rook")) { printRowRook(printRow, figColor); }
					else if (!strcmp(figName, "Bishop")) { printRowBishop(printRow, figColor); }
					else if (!strcmp(figName, "Horse")) { printRowHorse(printRow, figColor); }
					else if (!strcmp(figName, "Queen")) { printRowQueen(printRow, figColor); }
					else if (!strcmp(figName, "King")) { printRowKing(printRow, figColor); }
					else {
						assert(false);
					}
				}
				else {
					if (printRow == 0) {
						*s << "          ";
					}

					else {
						*s << "           ";
					}

				}
				//if (printRow != 0 && col == 0) { std::cout << "&"; }
				*s << "|";


			}
			// printrow closes here

			*s << std::endl;
			*s << " ";
		}

		for (int k = 0; k < max_position_size; k++) {
			*s << "_____________.";
		}
		*s << std::endl;
		// row iterator closes here
	}
}


void ConsoleView::printMessage(const char * message)
{
	*s << message << std::endl;
}


void ConsoleView::readCommand(char * command)
{
	std::cin.getline(command, 14, '\n');
}

std::ostream & ConsoleView::getStream()
{
	return *s;
}


ConsoleView::ConsoleView(std::ostream& s)
{
	this->s = &s;

	this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}


ConsoleView::~ConsoleView()
{
}
