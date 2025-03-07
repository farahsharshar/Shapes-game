#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& file);
	virtual void Load(ifstream& file);
	color colorString(string str);
	virtual bool GetFigure(double x, double y) const;
	virtual void PrintInfo(Output* pOut);
	virtual string GetType();
	Point Get_Center();
	Point Get_Corner1();
	Point Get_Corner2();
	static string stringColor(color col);
	virtual void Get_ID();
};

#endif