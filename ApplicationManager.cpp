#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"AddCircAction.h"
#include"AddSqrAction.h"
#include"AddTriAction.h"
#include"AddHexAction.h"
#include"Select.h"
#include"Chng_Border.h"
#include"SendToBack.h"
#include"BringToFront.h"
#include"Copy.h"
#include"Paste.h"
#include"Delete.h"
#include"SwitchtoPlayMode.h"
#include"ClearAll.h"
#include "SaveAction.h"
#include"LoadAction.h"

//class BringToFront;

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	SelectedFig = NULL;
	SelFigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_Sqr:
			pAct = new AddSqrAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case DRAW_Hex:
			pAct = new AddHexAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;

		case SELECT:
			pAct = new Select(this);
			break;

		case brdclr:
			pAct = new Chng_Border(this);
			break;

		case SENDBACK:
			pAct = new SendToBack(this);
			break;

		case BRINGFRONT:
			pAct = new BringToFront(this);
			break;

		case COPY:
			pAct = new Copy(this);
			break;

		case PASTE:
			pAct = new Paste(this);
			break;

		case DEL:
			pAct = new Delete(this);
			break;

		case TO_PLAY:
			pAct = new SwitchtoPlayMode(this);
			break;

		case CLEAR_ALL:
			pAct = new clearALL(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case LOAD:
			pAct = new LoadAction(this);
			break;




		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(double x, double y)
{
	SelectedFig = NULL;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetFigure(x, y) == true)
		{
			SelectedFig = FigList[i];
		}
	}

	return SelectedFig;
}

void ApplicationManager::UnSelectAll()
{
	for (int i = 0; i < SelFigCount; i++)
	{
		SelFig[i]->SetSelected(false);
		SelFig[i]->ChngDrawClr(Selcols[i]);
	//}
	//for (int i = 0; i < FigCount; i++)
	//{
			SelFig[i] = NULL;
			//SelFigCount--;
	}
	SelFigCount = 0;
}
void ApplicationManager::AddSelectedFig(CFigure* pSel)
{
	Selcols[SelFigCount] = pSel->Get_DrawClr();
	SelFig[SelFigCount++] = pSel;
	
	Setoriginalcolor(pSel->Get_DrawClr());
}
void ApplicationManager::UnSelectedFig(CFigure* pUSel)
{
	for (int i = 0; i < SelFigCount; i++)
	{
		if (SelFig[i] == pUSel)
		{
			SelFig[i]->SetSelected(false);
			SelFig[i] = SelFig[SelFigCount - 1];
			SelFig[SelFigCount - 1] = NULL;
			SelFigCount--;
			SelectedFig = NULL;
		}
	}
}

void ApplicationManager::SelFigType(int& CR, int& CS, int& CT, int& CH, int& CC)
{
	for (int i = 0; i < SelFigCount; i++)
	{
		if (SelFig[i]->GetType() == "Rectangle")
		{
			CR++;
		}
		else if (SelFig[i]->GetType() == "Square")
		{
			CS++;
		}
		else if (SelFig[i]->GetType() == "Triangle")
		{
			CT++;
		}
		else if (SelFig[i]->GetType() == "Hexagon")
		{
			CH++;
		}
		else if (SelFig[i]->GetType() == "Circle")
		{
			CC++;
		}
	}
}
CFigure* ApplicationManager::oneisSelected()
{
	if (SelFigCount == 1)
	{
		return SelectedFig;
	}
	else
	{
		return NULL;
	}
}
void ApplicationManager::ClearFigureList() //clearALL action fn.
{
	for (int i = 0; i < FigCount; i++) // to clear figure list we use for loop to make an itt to delete all figures
	{
		delete FigList[i];
		FigList[i] == 0;
	}
	FigCount = 0;// make sure that figure count is = 0
}
void ApplicationManager::SaveAll(ofstream & file) const//SaveAction action fn.
{	
	file << FigCount << endl;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != nullptr)
		{
			FigList[i]->Save(file);
		}
	}
}




void ApplicationManager::BringTofront(CFigure* BTF)
 {
	for (int i = 1; i < FigCount + 1; i++)
	{
		CFigure* temp = FigList[FigCount - i];
		FigList[FigCount - i] = FigList[FigCount - 1];
		FigList[FigCount - 1] = temp;
		if (FigList[FigCount -1] == BTF)
		{
			break;
		}
	}
}

void ApplicationManager::Setoriginalcolor(color c)
{
	original = c;
}

color ApplicationManager::Getoriginalcolor() const
{
	return original;
}

void ApplicationManager::SendToback(CFigure* STB)
{
	for (int i = 0; i < FigCount; i++)
	{
		CFigure* temp = FigList[i];
		FigList[i] = FigList[0];
		FigList[0] = temp;
		if (FigList[0] == STB)
		{
			break;
		}
	}
}

int ApplicationManager::Get_SelectedItems_Counter()
{
	return SelFigCount;
}
void ApplicationManager::CopySelectedFig(CFigure* c)
{
	
	Clipboard = c;
	Clipboard->ChngDrawClr(original);
	UnSelectAll();

}

CFigure* ApplicationManager::Get_CopiedFig()
{
	return Clipboard;
}



void ApplicationManager::Delete_SelectedFig()
{
	int i = 0;
	while (i < FigCount)
	{

		if (FigList[i]->IsSelected())
		{

			FigList[i] = FigList[FigCount - 1];
		
			FigList[FigCount - 1] = NULL;

			FigCount--;
		}
		else 
		{
			i++;
		}
	}
	UnSelectAll();
}

CFigure* ApplicationManager::getSelected()
{
	return SelectedFig;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
