#pragma once
#include"Actions/Action.h"
class AddTriAction :public Action
{
private:
	Point P1, P2, P3;
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
