#pragma once
#include"Actions/Action.h"
#include"Figures/CFigure.h"
#include"ApplicationManager.h"
class Copy :public Action
{

public:
	Copy(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

