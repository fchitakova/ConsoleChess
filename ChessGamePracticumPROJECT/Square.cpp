#include "stdafx.h"
#include "Square.h"


//************************************
// Method:    isEmpty
// FullName:  Square::isEmpty
// Access:    public 
// Returns:   bool
// Qualifier: const
//************************************
bool Square::isEmpty() const
{
	return this->_isEmpty;
}

//************************************
// Method:    setFigure
// FullName:  Square::setFigure
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: Figure * figure
//************************************
void Square::setFigure(Figure* figure)
{
	this->figure = figure;
	this->_isEmpty = false;
}

//************************************
// Method:    getFigure
// FullName:  Square::getFigure
// Access:    public 
// Returns:   Figure *
// Qualifier: const
//************************************
Figure * Square::getFigure() const
{
	return this->figure;
}

//************************************
// Method:    removeFigure
// FullName:  Square::removeFigure
// Access:    public 
// Returns:   Figure *
// Qualifier:
//************************************
Figure * Square::removeFigure()
{
	this->_isEmpty = true;
	Figure* result = this->figure;
	this->figure = nullptr;
	return result;
}

//************************************
// Method:    Square
// FullName:  Square::Square
// Access:    public 
// Returns:   
// Qualifier:
//************************************
Square::Square()
{
	this->_isEmpty = true;
}


 Square::~Square()
{
	 std::cout << "delete square";
}
