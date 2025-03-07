#pragma once
#include "Actions/Action.h"
#include"string"
#include"Figures/CRectangle.h"
#include"Figures/CFigure.h"
#include<fstream>

class LoadAction :public Action
{

private:
	ifstream file;
	string name;

public:
	LoadAction(ApplicationManager* pApp); // constructor of class

	virtual void ReadActionParameters( );

	virtual void Execute( ); // execute Saving Action
	color colorString(string );
	string stringColor(color );	

	~LoadAction(); //Destructor	

};