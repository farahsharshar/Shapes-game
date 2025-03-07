#pragma once
#include"Actions/Action.h"
class AddCircAction : public Action
{
private:
	Point P1, P2;
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

