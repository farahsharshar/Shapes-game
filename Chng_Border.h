#pragma once
#include"Actions/Action.h"
#include"Figures/CFigure.h"
class Chng_Border:public Action
{
private:
	color col;
	ActionType colorAct;
	CFigure* ChngB;
public:
	Chng_Border(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

