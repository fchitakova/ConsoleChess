#pragma once

class Command {
protected:
	char* command;
public:
	virtual void execute() = 0;
	virtual void parseCommand() = 0;
	virtual ~Command() {
		delete[]command;
	}
};