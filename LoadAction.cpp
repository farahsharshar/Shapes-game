#include "LoadAction.h"
#include"SaveAction.h"
#include "ApplicationManager.h"
#include <fstream>
#include "Figures/CRectangle.h"
#include"Figures/CFigure.h"
#include"CSquare.h"
#include"CHexagon.h"
#include"CTriangle.h"
#include"CCircle.h"



LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp) {}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();//Pointer to output interface
	Input* pIn = pManager->GetInput();
	pOut->ClearDrawArea();
	pOut->PrintMessage("Enter File Name to Load Drawing");
	name = pIn->GetSrting(pOut);
}

void LoadAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();//Pointer to output interface
	pManager->ClearFigureList();
	file.open(name, ios::in);

	if (file.is_open()) 	//check if file open
	{
		string clr, filClr;
		file >> clr >> filClr;
		UI.DrawColor = colorString(clr);//file>> stringColor(UI.DrawColor)>> stringColor(UI.FillColor);
		UI.FillColor = colorString(filClr);// beya5od string esmo color/fill color we beyhoto fel draw/fill colors

		int c;
		file >> c;
		for (int i = 0; i < c; i++)
		{
			Point dummyPoint1 = { 0,0 };
			Point dummyPoint2= { 0,0 };
			Point dummyPoint3 = { 0,0 };
			GfxInfo dummyInfo;
			string type;
			file >> type;
			CFigure* FIGPTR=nullptr;
			if (type == "RECT")
			{
				FIGPTR = new CRectangle(dummyPoint1, dummyPoint2, dummyInfo);
			}
			else if (type == "SQUARE")
			{
				FIGPTR = new CSquare(dummyPoint1,dummyInfo);
			}
			else if (type == "TRI")
			{
				FIGPTR = new CTriangle(dummyPoint1, dummyPoint2, dummyPoint3, dummyInfo);
			}
			else if (type == "HEX")
			{
				FIGPTR = new CHexagon(dummyPoint1, dummyInfo);
			}
			else if (type == "CIRCLE")
			{
				FIGPTR = new CCircle(dummyPoint1,dummyPoint2,dummyInfo);
			}

			if (FIGPTR)
			{
				FIGPTR->Load(file);
				pManager->AddFigure(FIGPTR);
			}
			else { pOut->PrintMessage("Error!"); }
		}
		file.close();
		pOut->PrintMessage("File has Loaded Successfully");
	}
	else 
	{
	  pOut->PrintMessage("Cannot Find Given File, Sorry");
	}
}


color LoadAction::colorString(string str) {
	if (str == "RED") return RED;
	else if (str == "BLUE") return BLUE;
	else if (str == "GREEN") return GREEN;
	else if (str == "BLACK")return BLACK;
	else if (str == "YELLOW")return YELLOW;
	else if (str == "ORANGE")return ORANGE;
	else return UI.BkGrndColor;
}
LoadAction::~LoadAction() {}
