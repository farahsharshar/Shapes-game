#pragma once
#include"Figures/CFigure.h"
class CHexagon :public CFigure
{
private:
	Point Center;
public:
	CHexagon(Point P, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool GetFigure(double x, double y) const;
	virtual void PrintInfo(Output* pOut);
	virtual string GetType();
	Point Get_Center();
	virtual void Save(ofstream& file);
	virtual void Load(ifstream& file);
	color colorString(string str);
	string stringColor(color col);
	virtual void Get_ID();
};

