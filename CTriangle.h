#pragma once
#include"Figures/CFigure.h"
class CTriangle :public CFigure
{
private:
	Point Corner1, Corner2, Corner3;
public:
	CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut)const;
	virtual bool GetFigure(double x, double y) const;
	virtual void PrintInfo(Output* pOut);
	virtual string GetType();
	Point Get_LeftPoint();
	Point Get_Corner2Point();
	Point Get_Corner3Point();
	virtual void Save(ofstream& file);
	virtual void Load(ifstream& file);
	color colorString(string str);
	string stringColor(color col);
	virtual void Get_ID();

};

