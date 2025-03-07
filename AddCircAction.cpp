#include "AddCircAction.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include"ApplicationManager.h"
#include"CCircle.h"
AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddCircAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at it's Center.");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at a point on it.");
	pIn->GetPointClicked(P2.x, P2.y);

	CircGfxInfo.isFilled = false;
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddCircAction::Execute()
{
	ReadActionParameters();
	CCircle* C = new CCircle(P1, P2, CircGfxInfo);
	pManager->AddFigure(C);
}