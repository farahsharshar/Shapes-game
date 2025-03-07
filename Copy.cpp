#include "Copy.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"
#include"Figures/CRectangle.h"
#include"CTriangle.h"
#include"CSquare.h"
#include"CHexagon.h"
#include"CCircle.h"

Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
}

void Copy::ReadActionParameters()
{
}



void Copy::Execute()
{

	Output* pOut = pManager->GetOutput();
	if (pManager->Get_SelectedItems_Counter() == 1)
	{
		CFigure* fig = pManager->getSelected();
		if (fig->GetType() == "Rectangle")
		{

			Point corner1 = ((CRectangle*)fig)->Get_Corner1();
			Point corner2 = ((CRectangle*)fig)->Get_Corner2();
			CRectangle* rect = new CRectangle(corner1, corner2, fig->Get_Info());
			pManager->CopySelectedFig(rect);

		}
		else if (fig->GetType() == "Triangle")
		{
			Point corner1 = ((CTriangle*)fig)->Get_LeftPoint();
			Point corner2 = ((CTriangle*)fig)->Get_Corner2Point();
			Point corner3 = ((CTriangle*)fig)->Get_Corner3Point();
			CTriangle* tri = new CTriangle(corner1, corner2, corner3, fig->Get_Info());
			pManager->CopySelectedFig(tri);
		}
		else if (fig->GetType() == "Square")
		{
			Point center = ((CSquare*)fig)->Get_Center();
			CSquare* sqr = new CSquare(center, fig->Get_Info());
			pManager->CopySelectedFig(sqr);
		}
		else if (fig->GetType() == "Hexagon")
		{
			Point center = ((CHexagon*)fig)->Get_Center();
			CHexagon* hex = new CHexagon(center, fig->Get_Info());
			pManager->CopySelectedFig(hex);
		}
		else if (fig->GetType() == "Circle")
		{
			Point center = ((CCircle*)fig)->Get_Center();
			Point OnCircle = ((CCircle*)fig)->Get_OnCircle();
			CCircle* cir = new CCircle(center, OnCircle, fig->Get_Info());
			pManager->CopySelectedFig(cir);
		}

		pOut->PrintMessage("Figure copied.");

	}
	else if (pManager->Get_SelectedItems_Counter() == 0)
		pOut->PrintMessage("Select a figure to be copied.");
	else
		pOut->PrintMessage("Select only one figure to be copied.");
}


