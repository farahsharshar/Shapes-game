#pragma once
#include "Actions/Action.h"
#include"string"
#include<fstream>


class SaveAction :public Action
{

private :
	string name;
	ofstream file;
public:
	SaveAction(ApplicationManager* pApp); // constructor of class

	virtual void ReadActionParameters();

	virtual void Execute(); // execute Saving Action
	string stringColor(color);
	color colorString(string);

	~SaveAction(); //Destructor	

};