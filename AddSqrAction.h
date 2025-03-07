#pragma once
#include"Actions/Action.h"
class AddSqrAction : public Action
{
private:
	Point P;
	GfxInfo SqrGfxInfo;
public:
	AddSqrAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

