#include "CFigure.h"
int CFigure::IDfigs = 0;
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
string CFigure::stringColor(color col)
{
	if (col == RED) return "RED";
	else if (col == BLUE) return "BLUE";
	else if (col == GREEN) return "GREEN";
	else if (col == BLACK)return "BLACK";
	else if (col == YELLOW)return "YELLOW";
	else if (col == ORANGE)return "ORANGE";
	else return "NONE";
}
color CFigure::colorString(string str)
{
	if (str == "RED") return RED;
	else if (str == "BLUE") return BLUE;
	else if (str == "GREEN") return GREEN;
	else if (str == "BLACK")return BLACK;
	else if (str == "YELLOW")return YELLOW;
	else if (str == "ORANGE")return ORANGE;
	else return UI.BkGrndColor;
}


color CFigure::Get_DrawClr()
{
	return FigGfxInfo.DrawClr;
}

color CFigure::Get_FillClr()
{
	return FigGfxInfo.FillClr;
}

bool CFigure::Get_Isfilled() const
{

	return FigGfxInfo.isFilled;
}

GfxInfo CFigure::Get_Info()
{
	return FigGfxInfo;
}