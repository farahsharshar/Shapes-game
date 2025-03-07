#include "SendToBack.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"

SendToBack::SendToBack(ApplicationManager* pApp):Action(pApp)
{
}

void SendToBack::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	if (STB != NULL)
	{
		pOut->PrintMessage("Figure Sent To Back.");
	}
	else
	{
		pOut->PrintMessage("ERROR: Select one Figure only.");
	}
}

void SendToBack::Execute()
{
	STB = pManager->oneisSelected();
	if (STB != NULL)
	{
		pManager->SendToback(STB);
		STB->ChngDrawClr(pManager->Getoriginalcolor());
		pManager->UnSelectedFig(STB);
		ReadActionParameters();
	}
	else
	{
		ReadActionParameters();
	}
}
