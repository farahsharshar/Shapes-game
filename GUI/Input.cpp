#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE: return DRAW_Sqr;
			case ITM_TRI: return DRAW_TRI;
			case ITM_HEX: return DRAW_Hex;
			case ITM_CIRCLE: return DRAW_CIRC;
			case ITM_SELECT: return SELECT;
			case ITM_DELETE: return DEL;
			case ITM_CLEARALL: return CLEAR_ALL;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_SENDBACK: return SENDBACK;
			case ITM_BRINGFRONT:return BRINGFRONT;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_BRDRCLR:return brdclr;
			case ITM_FILLCLR:return fillclr;
			case ITM_BLACK: return COLOUR_BLACK;
			case ITM_YELLOW: return COLOUR_YELLOW;
			case ITM_ORANGE: return COLOUR_ORANGE;
			case ITM_RED: return COLOUR_RED;
			case ITM_GREEN: return COLOUR_GREEN;
			case ITM_BLUE: return COLOUR_BLUE;
			case ITM_SWITCH_TOPLAY: return TO_PLAY;

			case ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_TYPE: return TYPE;
			case ITM_COLOUR: return COLOUR;
			case ITM_TYPEANDCOLOUR: return TYPEANDCOLOUR;
			case ITM_SWITCH_TODRAW: return TO_DRAW;
			case ITM_ADDVOICE: return ADDVOICE;
			case ITM_RESIZE: return RESIZE;
			default: return EMPTY;

			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAYING_AREA;
		}
		else if (y >= UI.height - UI.StatusBarHeight)
			return STATUS;

		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}

}
/////////////////////////////////

Input::~Input()
{
}
