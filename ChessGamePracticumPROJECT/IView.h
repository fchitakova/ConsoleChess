#pragma once
#include"Board.h"
#include<iostream>

class IView
{

public:
	
	virtual void printBoard(Board* board) = 0;
	virtual void printMessage(const char*) = 0;
	virtual std::ostream& getStream() = 0;
	virtual void readCommand(char * command) = 0;
	
	
};

