#pragma once
#include "View.h"
#include<Windows.h>
class ConsoleView :
	public View
{
public:
	std::ostream* s;
	HANDLE hConsole;
	char king[10][12] = {
		"  =||=    ",
		" ++++++++  ",
		"========== ",
		" \\      /  ",
		"  |    |   ",
		"  |    |   ",
		"  |    |   ",
		"  |    |   ",
		" /      \\  ",
		"|________| ",
	};
	char queen[10][12] = {
		"          ",
		"|\\ ,'`. /| ",
		"| ------ | ",
		" \\      /  ",
		"  |    |   ",
		"  |    |   ",
		"  |    |   ",
		"  |    |   ",
		" /      \\  ",
		"|________| ",
	};
	char bishop[10][12] = {
		"          ",
		"     o     ",
		"   /\\^/\\   ",
		"  |  /  )  ",
		"  | /  /   ",
		"   Y  /    ",
		"   |  |    ",
		"   |  |    ",
		"  /    \\   ",
		" |______|  ",
	};
	char horse[10][12] = {
		"          ",
		"           ",
		"  |\\__     ",
		" /   o\\__  ",
		"|    ___=\' ",
		"|    \\     ",
		" \\    \\    ",
		"  >    \\   ",
		" /      \\  ",
		"|________| ",
	};;
	char rook[10][12] = {
		"          ",
		"           ",
		" _   _   _ ",
		"| |_| |_|| ",
		" \\      /  ",
		"  |    |   ",
		"  |    |   ",
		"  |    |   ",
		" /      \\  ",
		"|________| ",
	};
	char pawn[10][12] = {
		"          ",
		"           ",
		"    __     ",
		"   (  )    ",
		"    ><     ",
		"   |  |    ",
		"  |    |   ",
		"  |    |   ",
		" /      \\  ",
		"|________| ",
	};
public:
	void printRowQueen(int n, Color color);
	void printRowBishop(int n, Color color);
	void printRowHorse(int n, Color color);
	void printRowRook(int n, Color color);
	void printRowPawn(int n, Color color);

	// init
	/*void initRowQueen();
	void initRowBishop();
	void initRowHorse();
	void initRowRook();
	void initRowPawn();*/

public:
	ConsoleView() = delete;
	ConsoleView& operator =(ConsoleView&) = delete;
	ConsoleView(ConsoleView&) = delete;
	void printRowKing(int n, Color color);
	void printBoard(IBoard* board) override;
	void printMessageNL(const char*) override;
	void readCommand(char* command)override;
	std::ostream& getStream() override;

	ConsoleView(std::ostream& s);
	
	virtual ~ConsoleView();
};

