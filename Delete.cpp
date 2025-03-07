#include "Delete.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{
}

void Delete::ReadActionParameters()
{
}



void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (pManager->Get_SelectedItems_Counter() != 0)
	{
		pManager->Delete_SelectedFig();
		pOut->PrintMessage("Selected figures are deleted.");

	}
	else
	{
		pOut->PrintMessage("Select a figure to be deleted.");
	}
}
