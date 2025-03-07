#pragma once
#include"Actions/Action.h"
#include"Figures/CFigure.h"
class SendToBack:public Action
{
private:
	CFigure* STB;
public:
	SendToBack(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

