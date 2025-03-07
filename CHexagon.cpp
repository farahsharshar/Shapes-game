#include "CHexagon.h"
#include"SaveAction.h"
#include<fstream>

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
	ID = ++IDfigs;
}

void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

bool CHexagon::GetFigure(double x, double y) const
{
	if (abs(Center.x - x) <= 50 && abs(Center.y - y) <= 100)
	{
		return true;
	}
	else if (abs(Center.x - x) > 50 && abs(Center.x - x) <= 100)
	{
		if (Center.x > x)
		{
			double New = x - (Center.x - 100);
			if (abs(Center.y - y) <= pow(3, 0.5) * New)
			{
				return true;
			}
		}
		else if (x > Center.x)
		{
			double New = (Center.x + 100) - x;
			if (abs(Center.y - y) <= pow(3, 0.5) * New)
			{
				return true;
			}
		}
	}
	else
	{
		return false;
	}
}

void CHexagon::Save(ofstream& file)
{
	file << "HEX" << " " << ID << " " << Center.x << " " << Center.y << " " ;
	file << stringColor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.FillClr == true) { file << " " << stringColor(FigGfxInfo.FillClr) << " "; }
	else { file << "NOTFILLED" << endl; }
}
void CHexagon::Load(ifstream& file)
{
	string TFdrawcolor;
	string TFfillcolor;

	file >> ID >> Center.x >> Center.y >>(TFdrawcolor) >> (TFfillcolor);
	FigGfxInfo.DrawClr = colorString(TFdrawcolor);
	FigGfxInfo.FillClr = colorString(TFfillcolor);

}
color CHexagon::colorString(string str)
{
	if (str == "RED") return RED;
	else if (str == "BLUE") return BLUE;
	else if (str == "GREEN") return GREEN;
	else if (str == "BLACK")return BLACK;
	else if (str == "YELLOW")return YELLOW;
	else if (str == "ORANGE")return ORANGE;
	else return UI.BkGrndColor;
}
string CHexagon::stringColor(color col)
{
	if (col == RED) return "RED";
	else if (col == BLUE) return "BLUE";
	else if (col == GREEN) return "GREEN";
	else if (col == BLACK)return "BLACK";
	else if (col == YELLOW)return "YELLOW";
	else if (col == ORANGE)return "ORANGE";
	else return "NONE";
}

void CHexagon::Get_ID()
{
	ID = IDfigs - 1;
	
}



void CHexagon::PrintInfo(Output* pOut)
{
	string msg = "Hexagon "+to_string(ID);
	pOut->PrintMessage(msg);
}

string CHexagon::GetType()
{
	return "Hexagon";
}

Point CHexagon::Get_Center()
{
	return Center;
}
