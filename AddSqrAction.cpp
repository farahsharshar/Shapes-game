#include "AddSqrAction.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include"ApplicationManager.h"
#include"CSquare.h"
AddSqrAction::AddSqrAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddSqrAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at it's Center.");
	pIn->GetPointClicked(P.x, P.y);

	SqrGfxInfo.isFilled = false;
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddSqrAction::Execute()
{
	ReadActionParameters();
	CSquare* S = new CSquare(P, SqrGfxInfo);
	pManager->AddFigure(S);
}
