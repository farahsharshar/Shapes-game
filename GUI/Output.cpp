#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.LineUnderTBWidth = 2;
	UI.MenuItemWidth = 49;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project - Spring 2024");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
void Output::ClearToolBar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.height - UI.StatusBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_square.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_triangle.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_hexagon.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_circle.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_select.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_delete.jpg";
	MenuItemImages[ITM_CLEARALL] = "images\\MenuItems\\Menu_deleteall.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_paste.jpg";
	MenuItemImages[ITM_SENDBACK] = "images\\MenuItems\\Menu_bringfront.jpg";
	MenuItemImages[ITM_BRINGFRONT] = "images\\MenuItems\\Menu_bringtofront.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_loadgraph.jpg";
	MenuItemImages[ITM_BRDRCLR] = "images\\MenuItems\\Menu_BrdrClr.jpg";
	MenuItemImages[ITM_FILLCLR] = "images\\MenuItems\\Menu_FillClr.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Menu_orange.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_blue.jpg";
	MenuItemImages[ITM_SWITCH_TOPLAY] = "images\\MenuItems\\Menu_switchtoplay.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_TYPE] = "images\\MenuItems\\Menu_type.jpg";
	MenuItemImages[ITM_COLOUR] = "images\\MenuItems\\Menu_colour.jpg";
	MenuItemImages[ITM_TYPEANDCOLOUR] = "images\\MenuItems\\Menu_typeandcolour.jpg";
	MenuItemImages[ITM_ADDVOICE] = "images\\MenuItems\\Menu_addvoice.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Menu_resize.jpg";
	MenuItemImages[ITM_SWITCH_TODRAW] = "images\\MenuItems\\Menu_switchtoplay.jpg";
	MenuItemImages[PLAY_ITM_COUNT] = "images\\MenuItems\\Menu_count.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawSqr(Point P, GfxInfo SqrGfxInfo, bool selected) const
{
	Point P3;
	Point P4;
	double z = 100;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SqrGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SqrGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqrGfxInfo.FillClr);
	}
	else
		style = FRAME;


	P3.x = P.x - z;
	P3.y = P.y - z;
	P4.x = P.x + z;
	P4.y = P.y + z;
	pWind->DrawRectangle(P3.x, P3.y, P4.x, P4.y, style);

}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawHex(Point P, GfxInfo HexGfxInfo, bool selected) const
{
	int z = 100;
	int PX[6];
	int PY[6];
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
	{
		style = FRAME;
	}

	PX[0] = P.x - 0.5 * z;
	PX[1] = P.x + 0.5 * z;
	PX[2] = P.x + z;
	PX[3] = P.x + 0.5 * z;
	PX[4] = P.x - 0.5 * z;
	PX[5] = P.x - z;

	PY[0] = P.y + (pow(3, 0.5) / 2) * z;
	PY[1] = P.y + (pow(3, 0.5) / 2) * z;
	PY[2] = P.y;
	PY[3] = P.y - (pow(3, 0.5) / 2) * z;
	PY[4] = P.y - (pow(3, 0.5) / 2) * z;
	PY[5] = P.y;

	pWind->DrawPolygon(PX, PY, 6, style);
}

void Output::DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
	{
		style = FRAME;
	}
	double Radius = pow(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2), 0.5);
	pWind->DrawCircle(P1.x, P1.y, Radius, style);
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

