#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,      //Draw Rectangle
	DRAW_Sqr,       //Draw Square
	DRAW_TRI,       //Draw Triangle
	DRAW_Hex,       //Draw Hexagon
	DRAW_CIRC,      //Draw Circle
	SAVE,
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,//Switch interface to Play mode
	SELECT,
	DEL,
	CLEAR_ALL,
	COPY,
	CUT,
	PASTE,
	SENDBACK,
	BRINGFRONT,
	LOAD,
	ADDVOICE,
	RESIZE,
	brdclr,
	fillclr,
	COLOUR_BLACK,
	COLOUR_RED,
	COLOUR_YELLOW,
	COLOUR_ORANGE,
	COLOUR_GREEN,
	COLOUR_BLUE,

	TYPE,
	COLOUR,
	TYPEANDCOLOUR,
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	PLAYING_AREA,
	STATUS,         //A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif