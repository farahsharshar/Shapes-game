#include "CSquare.h"
#include"ApplicationManager.h"
CSquare::CSquare(Point p, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID=++IDfigs;
	Center = p;
}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSqr(Center, FigGfxInfo, Selected);
}

bool CSquare::GetFigure(double x, double y) const
{
	if (abs(x - Center.x) <= 100 && abs(y - Center.y) <= 100)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CSquare::Save(ofstream& file)
{
	file << "SQUARE" << " " << ID << " " << Center.x << " " << Center.y << " ";
	file << stringColor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.FillClr == true) { file << " " << stringColor(FigGfxInfo.FillClr) << " "; }
	else { file << "NOTFILLED" << endl; }
}
void CSquare::Load(ifstream& file)
{
	string TFdrawcolor;
	string TFfillcolor;

	file >> ID >> Center.x >> Center.y >>(TFdrawcolor) >> (TFfillcolor);
	FigGfxInfo.DrawClr = colorString(TFdrawcolor);
	FigGfxInfo.FillClr = colorString(TFfillcolor);

}
color CSquare::colorString(string str)
{
	if (str == "RED") return RED;
	else if (str == "BLUE") return BLUE;
	else if (str == "GREEN") return GREEN;
	else if (str == "BLACK")return BLACK;
	else if (str == "YELLOW")return YELLOW;
	else if (str == "ORANGE")return ORANGE;
	else return UI.BkGrndColor;
}
string CSquare::stringColor(color col)
{
	if (col == RED) return "RED";
	else if (col == BLUE) return "BLUE";
	else if (col == GREEN) return "GREEN";
	else if (col == BLACK)return "BLACK";
	else if (col == YELLOW)return "YELLOW";
	else if (col == ORANGE)return "ORANGE";
	else return "NONE";
}

void CSquare::Get_ID()
{
	ID = IDfigs - 1;
	
}



void CSquare::PrintInfo(Output* pOut)
{
	string msg = "Square " + to_string(ID);
	pOut->PrintMessage(msg);
}

string CSquare::GetType()
{
	return "Square";
}

Point CSquare::Get_Center()
{
	return Center;
}