#pragma once
#include "Actions/Action.h"
#include"Figures/CFigure.h"
class Delete :public Action
{
	CFigure* Deleted_Fig;

public:
	Delete(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

