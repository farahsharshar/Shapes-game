#include"SwitchtoPlayMode.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"



SwitchtoPlayMode::SwitchtoPlayMode(ApplicationManager* pApp) : Action(pApp) {}

void SwitchtoPlayMode::ReadActionParameters() { Input* pIn = pManager->GetInput(); }

void SwitchtoPlayMode::Execute()
{
	Output* pOut = pManager->GetOutput(); //Pointer to output interface
	
	pOut->PrintMessage("Switched to Play Mode !");
	UI.InterfaceMode = MODE_PLAY;
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();

}

SwitchtoPlayMode::~SwitchtoPlayMode() {}

