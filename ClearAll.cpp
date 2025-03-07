#include "clearALL.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"


clearALL::clearALL(ApplicationManager* pApp) : Action(pApp) {}

void clearALL::ReadActionParameters() { Input* pIn = pManager->GetInput(); }

void clearALL::Execute()
{
	Output* pOut = pManager->GetOutput(); //Pointer to output interface

	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
	pManager->ClearFigureList();
	pOut->PrintMessage("Drawn Figures have been Cleared !");

}

clearALL::~clearALL() {}

