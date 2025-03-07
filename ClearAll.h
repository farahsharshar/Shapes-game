#pragma once
#include "Actions/Action.h"


class clearALL : public Action //include Action.h file 
{
private:

public:
	clearALL(ApplicationManager* pApp); // constructor of class

	virtual void ReadActionParameters(); 

	virtual void Execute(); // execute clearALL Action

	~clearALL(); //Destructor 

};
