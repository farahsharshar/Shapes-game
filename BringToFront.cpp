#include "BringToFront.h"
//#include"GUI/Input.h"
//#include"GUI/Output.h"
//#include"ApplicationManager.h"
#include"Figures/CFigure.h"

BringToFront::BringToFront(ApplicationManager* pApp):Action(pApp)
{
}

void BringToFront::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	if (BTF != NULL)
	{
		pOut->PrintMessage("Figure Brought to Front.");
	}
	else
	{
		pOut->PrintMessage("ERROR: Select one Figure Only.");
	}
}

void BringToFront::Execute()
{
	BTF = pManager->oneisSelected();
	if (BTF != NULL)
	{
		pManager->BringTofront(BTF);
		BTF->ChngDrawClr(pManager->Getoriginalcolor());
		pManager->UnSelectedFig(BTF);
		ReadActionParameters();
	}
	else
	{
		ReadActionParameters();
	}
}
