#pragma once
#include"Board.h"
#include"IView.h"
class View :public  IView
{
public:
	View();
	virtual void printBoard(Board* board) = 0;
	virtual void printMessage(const char*) = 0;
	virtual void readCommand(char * command) = 0;
	virtual std::ostream& getStream() = 0;
	virtual ~View();
};

