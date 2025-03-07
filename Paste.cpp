#include "Paste.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"
#include"CSquare.h"
#include"CHexagon.h"
#include"CCircle.h"
#include"CTriangle.h"
#include"Figures/CRectangle.h"
Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{
}

void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage(" Click a point to paste figure.");
	pIn->GetPointClicked(P.x, P.y);
	copiedFig = pManager->Get_CopiedFig();
	PasteGfxInfo.isFilled = copiedFig->Get_Isfilled();
	PasteGfxInfo.DrawClr = copiedFig->Get_DrawClr();
	PasteGfxInfo.FillClr = copiedFig->Get_FillClr();
	copiedFig->SetSelected(false);

	pOut->ClearStatusBar();
}

void Paste::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (copiedFig->GetType() == "Square")
	{
		CSquare* S = new CSquare(P, PasteGfxInfo);
		pManager->AddFigure(S);
		S->Get_ID();

		pOut->PrintMessage("Square ");
	}
	else if (copiedFig->GetType() == "Hexagon")
	{
		CHexagon* H = new CHexagon(P, PasteGfxInfo);
		pManager->AddFigure(H);
		H->Get_ID();

		pOut->PrintMessage("Hexagon ");
	}
	else if (copiedFig->GetType() == "Circle")
	{
		Point center = ((CCircle*)copiedFig)->Get_Center();
		Point OnCircle = ((CCircle*)copiedFig)->Get_OnCircle();
		double x = P.x - center.x;
		double y = P.y - center.y;
		OnCircle.x = OnCircle.x + x;
		OnCircle.y = OnCircle.y + y;
		CCircle* C = new CCircle(P, OnCircle, PasteGfxInfo);
		pManager->AddFigure(C);
		C->Get_ID();

		pOut->PrintMessage("Circle ");

	}
	else if (copiedFig->GetType() == "Triangle")
	{
		Point leftpoint = ((CTriangle*)copiedFig)->Get_LeftPoint();
		double x = P.x - leftpoint.x;
		double y = P.y - leftpoint.y;
		Point corner2 = ((CTriangle*)copiedFig)->Get_Corner2Point();
		corner2.x = corner2.x + x;
		corner2.y = corner2.y + y;
		Point corner3 = ((CTriangle*)copiedFig)->Get_Corner3Point();
		corner3.x = corner3.x + x;
		corner3.y = corner3.y + y;
		CTriangle* T = new CTriangle(P, corner2, corner3, PasteGfxInfo);
		pManager->AddFigure(T);
		T->Get_ID();

		pOut->PrintMessage("Triangle ");
	}
	else if (copiedFig->GetType() == "Rectangle")
	{
		Point center = ((CRectangle*)copiedFig)->Get_Center();
		double x = P.x - center.x;
		double y = P.y - center.y;
		Point corner1 = ((CRectangle*)copiedFig)->Get_Corner1();
		corner1.x = corner1.x + x;
		corner1.y = corner1.y + y;
		Point corner2 = ((CRectangle*)copiedFig)->Get_Corner2();
		corner2.x = corner2.x + x;
		corner2.y = corner2.y + y;
		CRectangle* R = new CRectangle(corner1, corner2, PasteGfxInfo);
		pManager->AddFigure(R);
		R->Get_ID();
		pOut->PrintMessage("Rectangle ");
	}

}
