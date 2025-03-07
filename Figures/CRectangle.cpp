#include "CRectangle.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../LoadAction.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID = ++IDfigs;
}
	
color CRectangle::colorString(string str)
{
	if (str == "RED") return RED;
	else if (str == "BLUE") return BLUE;
	else if (str == "GREEN") return GREEN;
	else if (str == "BLACK")return BLACK;
	else if (str == "YELLOW")return YELLOW;
	else if (str == "ORANGE")return ORANGE;
	else return UI.BkGrndColor;
}
string CRectangle::stringColor(color col)
{
	if (col == RED) return "RED";
	else if (col == BLUE) return "BLUE";
	else if (col == GREEN) return "GREEN";
	else if (col == BLACK)return "BLACK";
	else if (col == YELLOW)return "YELLOW";
	else if (col == ORANGE)return "ORANGE";
	else return "NONE";
}

void CRectangle::Get_ID()
{
	ID = IDfigs - 1;
	
}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
void CRectangle::Save(ofstream& file)
{
	file << "RECT" << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
	file << stringColor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.FillClr == true) { file << " " << stringColor(FigGfxInfo.FillClr) << " "; }
	else { file << "NOTFILLED" << endl; }
}
void CRectangle::Load(ifstream& file)
{
	string TFdrawcolor;
	string TFfillcolor;

	file >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> (TFdrawcolor) >> (TFfillcolor);
	FigGfxInfo.DrawClr = colorString(TFdrawcolor);
	FigGfxInfo.FillClr = colorString(TFfillcolor);

}


bool CRectangle::GetFigure(double x, double y) const
{
	Point Center;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
   if (abs(Center.x - x) <= abs(Center.x - Corner1.x) && abs(Center.y - y) <= abs(Center.y - Corner1.y))
   {
	return true;
   }
   else
   {
	return false;
   }

}

void CRectangle::PrintInfo(Output* pOut)
{
	string msg = "Rectangle "+to_string(ID);
	pOut->PrintMessage(msg);
}

string CRectangle::GetType()
{
	return "Rectangle";
}

Point CRectangle::Get_Center()
{
	Point Center;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	return Center;
}

Point CRectangle::Get_Corner1()
{
	return Corner1;
}

Point CRectangle::Get_Corner2()
{
	return Corner2;
}
