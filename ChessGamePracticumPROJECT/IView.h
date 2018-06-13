#pragma once
#include"IBoard.h"
#include<iostream>

class IView
{

public:
	
	virtual void printBoard(IBoard* board) = 0;
	virtual void printMessageNL(const char*) = 0;
	virtual std::ostream& getStream() = 0;
	virtual void readCommand(char * command) = 0;
	
	
};

