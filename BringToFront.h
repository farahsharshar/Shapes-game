#ifndef BRING_TO_ACTION_H
#define BRING_TO_ACTION_H
#include"Actions/Action.h"
#include"Figures/CFigure.h"

class BringToFront:public Action
{
private:
	CFigure* BTF;
public:
	BringToFront(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
