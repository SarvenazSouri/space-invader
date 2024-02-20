#pragma once
//  Translated into English 03/2019

//	15/01/2015 version
#define VERSION_H 15012015

#include <windows.h>
#include <iostream>
using namespace std;

//	color constants
#define FOREGROUND_BLUE      0x0001 // text blue.
#define FOREGROUND_GREEN     0x0002 // text green.
#define FOREGROUND_RED       0x0004 // text red.
#define FOREGROUND_INTENSITY 0x0008 // text color is intensified.
#define BACKGROUND_BLUE      0x0010 // background blue.
#define BACKGROUND_GREEN     0x0020 // background green.
#define BACKGROUND_RED       0x0040 // background color red.
#define BACKGROUND_INTENSITY 0x0080 // background color is intensified.

class UIKit {

public:

	//Set the console window dimensions relative to the default settings
	static void setWindowDimensions(int x1, int y1, int x2, int y2);

	//Set text color
	//see pre-defined color codes above, add text and backgroud color
	//for example for blue text on green background 0x0021 = 
	//for high intensity blue text on green background 0x0029 = 
	static void color(unsigned short theColor);

	// Positions the cursor on screen
	// x= column, y=row : position 0,0 is the top left corner
	static void gotoXY(int x, int y);

	/* Get the current cursor horizontal position X (column)*/
	static int whereX();
	/* Get the current cursor vertical position Y (row)*/
	static int whereY();

	// Get the character found at column x, line y
	static char getCharXY(int x, int y);

	// Draw a rectangular frame on the screen
	// x1,y1 upper left corner
	// x2,y2 lower right corner
	// color the color of the frame, see color codes aboves
	static void frame(int x1,int y1,int x2,int y2, int color);

	// Make the cursor visible or invisible
	static void visibleCursor(bool visible);

private:
	// for internal use only
	static HANDLE handle;
	static bool isPaletteReset;

	static void resetPalette();
};

