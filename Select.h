#pragma once
#pragma once
#include"Actions/Action.h"
#include"Figures/CFigure.h"
class Select :public Action
{
private:
	Point P;
	CFigure* PSel;
public:
	Select(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void StatusBarmsg();
};

