#include "Select.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"
#include<string>
Select::Select(ApplicationManager* pApp) :Action(pApp)
{
}

void Select::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select: Click at a point.");
	pIn->GetPointClicked(P.x, P.y);

	pOut->ClearStatusBar();
}


void Select::Execute()
{
	ReadActionParameters();
	PSel = pManager->GetFigure(P.x, P.y);
	if (PSel != NULL)
	{
		if (PSel->IsSelected() == false)
		{
			pManager->Setoriginalcolor(PSel->Get_DrawClr());
			PSel->SetSelected(true);
			pManager->AddSelectedFig(PSel);
			PSel->ChngDrawClr(MAGENTA);
			

		}
		else
		{
			PSel->SetSelected(false);
			PSel->ChngDrawClr(pManager->Getoriginalcolor());
			pManager->UnSelectedFig(PSel);
		}

	}
	else if (PSel == NULL)
	{
		pManager->UnSelectAll();
	}
	StatusBarmsg();
	PSel = NULL;
}


void Select::StatusBarmsg()
{
	Output* pOut = pManager->GetOutput();
	int CR = 0, CS = 0, CT = 0, CH = 0, CC = 0;
	pManager->SelFigType(CR, CS, CT, CH, CC);
	if (CR + CS + CT + CH + CC != 1 && CR + CS + CT + CH + CC != 0)
	{
		string tempR = to_string(CR) + " Rectangle(s), ";
		string tempS = to_string(CS) + " Square(s), ";
		string tempT = to_string(CT) + " Triangle(s), ";
		string tempH = to_string(CH) + " Hexagon(s), ";
		string tempC = to_string(CC) + " Circle(s), ";
		pOut->PrintMessage(tempR + tempS + tempT + tempH + tempC);
	}
	else if ( CR + CS + CT + CH + CC == 1)
	{
		PSel->PrintInfo(pOut);
	}
	else if (CR + CS + CT + CH + CC == 0)
	{
		pOut->ClearStatusBar();
	}
}
