#include "stdafx.h"
#include "ConsoleView.h"
#include"Color.h"
#include"GlobalVariables.h"
#include<assert.h>
#include<Windows.h>
//#include <windows.h>



//************************************
// Method:    printRowKing
// FullName:  ConsoleView::printRowKing
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int n
// Parameter: Color color
//************************************
void ConsoleView::printRowKing(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*s << king[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}

//************************************
// Method:    printRowQueen
// FullName:  ConsoleView::printRowQueen
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int n
// Parameter: Color color
//************************************
void ConsoleView::printRowQueen(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*s << queen[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}

//************************************
// Method:    printRowBishop
// FullName:  ConsoleView::printRowBishop
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int n
// Parameter: Color color
//************************************
void ConsoleView::printRowBishop(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*s << bishop[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}

//************************************
// Method:    printRowHorse
// FullName:  ConsoleView::printRowHorse
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int n
// Parameter: Color color
//************************************
void ConsoleView::printRowHorse(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*s << horse[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}

//************************************
// Method:    printRowRook
// FullName:  ConsoleView::printRowRook
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int n
// Parameter: Color color
//************************************

void ConsoleView::printRowRook(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*s << rook[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}

//************************************
// Method:    printRowPawn
// FullName:  ConsoleView::printRowPawn
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int n
// Parameter: Color color
//************************************
void ConsoleView::printRowPawn(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*s << pawn[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}



//************************************
// Method:    printBoard
// FullName:  ConsoleView::printBoard
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: IBoard * board
//************************************
void ConsoleView::printBoard(IBoard * board)
{
	char* figName;
	Color figColor;
	for (int row = 0; row < GlobalVaribles::SIZE; row++)
	{
		*s << row;
		for (int printRow = 0; printRow < 10; printRow++)
		{


			for (int col = 0; col < GlobalVaribles::SIZE; col++)
			{
				if (printRow == 0) {
					*s << col << ' ' << ' ';
				}
				else {
					*s << ' ' << ' ';
				}

				if (!board->isEmpty(row, col)) {
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

		for (int k = 0; k < GlobalVaribles::SIZE; k++) {
			*s << "_____________.";
		}
		*s << std::endl;
		// row iterator closes here
	}
}

//************************************
// Method:    printMessageNL
// FullName:  ConsoleView::printMessageNL
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: const char * message
//************************************
void ConsoleView::printMessageNL(const char * message)
{
	*s << message << std::endl;
}

//************************************
// Method:    readCommand
// FullName:  ConsoleView::readCommand
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: char * command
//************************************
void ConsoleView::readCommand(char * command)
{
	std::cin.getline(command, 14, '\n');
}

std::ostream & ConsoleView::getStream()
{
	return *s;
}

//************************************
// Method:    ConsoleView
// FullName:  ConsoleView::ConsoleView
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: std::ostream & s
//************************************
ConsoleView::ConsoleView(std::ostream& s)
{
	this->s = &s;

	this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}


//************************************
// Method:    ~ConsoleView
// FullName:  ConsoleView::~ConsoleView
// Access:    virtual public 
// Returns:   
// Qualifier:
//************************************
ConsoleView::~ConsoleView()
{
}
