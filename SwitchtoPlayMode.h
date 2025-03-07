#pragma once
#include "Actions/Action.h"


class SwitchtoPlayMode : public Action //include Action.h file 
{
private:
public:
	SwitchtoPlayMode(ApplicationManager* pApp); // constructor of class

	virtual void ReadActionParameters();

	virtual void Execute(); // execute clearALL Action

	~SwitchtoPlayMode(); //Destructor 

};
