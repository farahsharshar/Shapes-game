#include "CCircle.h"
#include"SaveAction.h"
#include<fstream>
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = ++IDfigs;
	center = P1;
	OnCircle = P2;
}

void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCirc(center, OnCircle, FigGfxInfo, Selected);
}

bool CCircle::GetFigure(double x, double y) const
{
	double Radius = pow(pow((center.x - OnCircle.x), 2) + pow((center.y - OnCircle.y), 2), 0.5);
	double Distance = pow(pow((center.x - x), 2) + pow((center.y - y), 2), 0.5);
	if (Distance <= Radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void CCircle::Save(ofstream& file)
{
	file << "CIRCLE" << " " << ID << " " << center.x << " " << center.y << " " <<OnCircle.x<<" "<<OnCircle.y<<" ";
	file << stringColor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.FillClr == true) { file << " " << stringColor(FigGfxInfo.FillClr) << " "; }
	else { file << "NOTFILLED" << endl; }
}
void CCircle::Load(ifstream& file)
{
	string TFdrawcolor;
	string TFfillcolor;

	file >> ID >> center.x >> center.y >>OnCircle.x>> OnCircle.y>>(TFdrawcolor) >> (TFfillcolor);
	FigGfxInfo.DrawClr = colorString(TFdrawcolor);
	FigGfxInfo.FillClr = colorString(TFfillcolor);

}
color CCircle::colorString(string str)
{
	if (str == "RED") return RED;
	else if (str == "BLUE") return BLUE;
	else if (str == "GREEN") return GREEN;
	else if (str == "BLACK")return BLACK;
	else if (str == "YELLOW")return YELLOW;
	else if (str == "ORANGE")return ORANGE;
	else return UI.BkGrndColor;
}
string CCircle::stringColor(color col)
{
	if (col == RED) return "RED";
	else if (col == BLUE) return "BLUE";
	else if (col == GREEN) return "GREEN";
	else if (col == BLACK)return "BLACK";
	else if (col == YELLOW)return "YELLOW";
	else if (col == ORANGE)return "ORANGE";
	else return "NONE";
}

void CCircle::Get_ID()
{
	ID = IDfigs-1;

}




void CCircle::PrintInfo(Output* pOut)
{
	string msg = "Circle "+to_string(ID);
	pOut->PrintMessage(msg);
}

string CCircle::GetType()
{
	return "Circle";
}

Point CCircle::Get_Center()
{
	return center;
}

Point CCircle::Get_OnCircle()
{
	return OnCircle;
}
