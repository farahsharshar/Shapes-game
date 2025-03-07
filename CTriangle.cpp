#include "CTriangle.h"
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	ID = ++IDfigs;
}

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

bool CTriangle::GetFigure(double x, double y) const
{
	double Distance12 = pow(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2), 0.5);
	double Distance13 = pow(pow((Corner1.x - Corner3.x), 2) + pow((Corner1.y - Corner3.y), 2), 0.5);
	double Distance32 = pow(pow((Corner3.x - Corner2.x), 2) + pow((Corner3.y - Corner2.y), 2), 0.5);

	double Distance_p1 = pow(pow((Corner1.x - x), 2) + pow((Corner1.y - y), 2), 0.5);
	double Distance_p2 = pow(pow((Corner2.x - x), 2) + pow((Corner2.y - y), 2), 0.5);
	double Distance_p3 = pow(pow((Corner3.x - x), 2) + pow((Corner3.y - y), 2), 0.5);

	double S_p12 = (Distance12 + Distance_p1 + Distance_p2) / 2;
	double S_p13 = (Distance13 + Distance_p1 + Distance_p3) / 2;
	double S_p23 = (Distance32 + Distance_p3 + Distance_p2) / 2;
	double S = (Distance12 + Distance13 + Distance32) / 2;

	double Area_p12 = pow((S_p12 * (S_p12 - Distance12) * (S_p12 - Distance_p1) * (S_p12 - Distance_p2)), 0.5);
	double Area_p13 = pow((S_p13 * (S_p13 - Distance13) * (S_p13 - Distance_p3) * (S_p13 - Distance_p1)), 0.5);
	double Area_p23 = pow((S_p23 * (S_p23 - Distance32) * (S_p23 - Distance_p3) * (S_p23 - Distance_p2)), 0.5);
	double Area = pow((S * (S - Distance12) * (S - Distance13) * (S - Distance32)), 0.5);


	if (Area >= (Area_p12 + Area_p13 + Area_p23))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CTriangle::PrintInfo(Output* pOut)
{
	string msg = "Triangle "+to_string(ID);
	pOut->PrintMessage(msg);
}

void CTriangle::Save(ofstream& file)
{
	file << "TRI ANG" << " " << ID << " " <<Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y << " ";
	file << stringColor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.FillClr == true) { file << " " << stringColor(FigGfxInfo.FillClr) << " "; }
	else { file << "NOTFILLED" << endl; }
}
void CTriangle::Load(ifstream& file)
{
	string TFdrawcolor;
	string TFfillcolor;
	string ang;

	file >> ang>> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y>>(TFdrawcolor) >> (TFfillcolor);
	FigGfxInfo.DrawClr = colorString(TFdrawcolor);
	FigGfxInfo.FillClr = colorString(TFfillcolor);

}
color CTriangle::colorString(string str)
{
	if (str == "RED") return RED;
	else if (str == "BLUE") return BLUE;
	else if (str == "GREEN") return GREEN;
	else if (str == "BLACK")return BLACK;
	else if (str == "YELLOW")return YELLOW;
	else if (str == "ORANGE")return ORANGE;
	else return UI.BkGrndColor;
}
string CTriangle::stringColor(color col)
{
	if (col == RED) return "RED";
	else if (col == BLUE) return "BLUE";
	else if (col == GREEN) return "GREEN";
	else if (col == BLACK)return "BLACK";
	else if (col == YELLOW)return "YELLOW";
	else if (col == ORANGE)return "ORANGE";
	else return "NONE";
}

void CTriangle::Get_ID()
{
	ID = IDfigs - 1;
	
}


string CTriangle::GetType()
{
	return "Triangle";
}

Point CTriangle::Get_LeftPoint()
{

	if (Corner2.x < Corner1.x && Corner2.x < Corner3.x)
	{
		Point p = Corner1;
		Corner1 = Corner2;
		Corner2 = p;

	}
	if (Corner3.x < Corner1.x && Corner3.x < Corner2.x)
	{
		Point p = Corner1;
		Corner1 = Corner3;
		Corner3 = p;

	}
	return Corner1;
}

Point CTriangle::Get_Corner2Point()
{
	return Corner2;
}

Point CTriangle::Get_Corner3Point()
{
	return Corner3;
}