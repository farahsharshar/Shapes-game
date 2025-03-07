#pragma once
#include"Actions/Action.h"
class AddHexAction :public Action
{
private:
	Point P;
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

