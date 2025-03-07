#include "SaveAction.h"
#include "ApplicationManager.h"
#include<fstream>


SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp) {}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput(); //Pointer to output interface
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter File Name to Save Drawing");
	name = pIn->GetSrting(pOut);
}

void SaveAction::Execute()
{
	Output* pOut = pManager->GetOutput();//Pointer to output interface
	ReadActionParameters();
	file.open(name,ios::out);
	file << stringColor(UI.DrawColor)<<"  "<<stringColor(UI.FillColor) << "   " << endl;
	pManager->SaveAll(file);
	pOut->PrintMessage("Saved!");
	file.close();

}

string SaveAction::stringColor(color col)
{
	if (col == RED) return "RED";
	else if (col == BLUE) return "BLUE";
	else if (col == GREEN) return "GREEN";
	else if (col == BLACK)return "BLACK";
	else if (col == YELLOW)return "YELLOW";
	else if (col == ORANGE)return "ORANGE";
	else return "NONE";
}
SaveAction::~SaveAction() {}
