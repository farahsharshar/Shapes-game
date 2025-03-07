#include "Chng_Border.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"

Chng_Border::Chng_Border(ApplicationManager* pApp):Action(pApp)
{
}

void Chng_Border::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
    pOut->PrintMessage("Change Border Color: Choose a color.");
	colorAct = pManager->GetUserAction();
	switch (colorAct)
	{
	
	case COLOUR_BLACK:
		col = BLACK;
		break;
	case COLOUR_YELLOW:
		col = YELLOW;
		break;
	case COLOUR_ORANGE:
		col = ORANGE;
		break;
	case COLOUR_RED:
		col = RED;
		break;
	case COLOUR_GREEN:
		col = GREEN;
		break;
	case COLOUR_BLUE:
		col = BLUE;
		break;
	
	default:
		break;
	}

	pOut->ClearStatusBar();
	
}

void Chng_Border::Execute()
{
	ChngB = pManager->oneisSelected();
	if (ChngB != NULL)
	{
		ReadActionParameters();
		
		ChngB->ChngDrawClr(col);
		pManager->UnSelectedFig(ChngB);

	}
	else if (ChngB == NULL)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("ERROR: Select only one Figure.");
	}
   
}
