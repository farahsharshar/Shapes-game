#pragma once
#include "Actions/Action.h"
#include"Figures/CFigure.h"
class Paste : public Action
{
private:
	Point P;
	GfxInfo PasteGfxInfo;
	CFigure* copiedFig;
public:
	Paste(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

