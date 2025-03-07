#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include "Actions/Action.h"
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include<fstream>

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* SelFig[MaxFigCount];
	color Selcols[MaxFigCount];
	int SelFigCount;
	color original;
	color Drawclr;
	color Fillclr;
	bool selectedfig;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(double x, double y); //Search for a figure given a point inside the figure
	void UnSelectAll();
	void AddSelectedFig(CFigure* pSel);
	void UnSelectedFig(CFigure* pUSel);
	void SelFigType(int& CR, int& CS, int& CT, int& CH, int& CC);
	CFigure* oneisSelected();
	void SendToback(CFigure* STB);
	void BringTofront(CFigure* BTF);
	void Setoriginalcolor(color);
	color Getoriginalcolor() const;
	int Get_SelectedItems_Counter();
	void CopySelectedFig(CFigure*);
	CFigure* Get_CopiedFig();
	void Delete_SelectedFig();
	CFigure* getSelected();
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void ClearFigureList();
	void SaveAll(ofstream& file) const;

	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif