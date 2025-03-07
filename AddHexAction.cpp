#include "AddHexAction.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include"ApplicationManager.h"
#include"CHexagon.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at it's Center.");
	pIn->GetPointClicked(P.x, P.y);

	HexGfxInfo.isFilled = false;
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddHexAction::Execute()
{
	ReadActionParameters();
	CHexagon* H = new CHexagon(P, HexGfxInfo);
	pManager->AddFigure(H);
}
