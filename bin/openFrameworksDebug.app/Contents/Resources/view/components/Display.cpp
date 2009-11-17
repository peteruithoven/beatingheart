/*
 *  Display.cpp
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 5/30/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Display.h"
#include <sstream>

Display::Display()
{
	ttf.loadFont("mono.ttf", 7);
	ofAddListener(ofEvents.draw, this, &Display::draw);
}
void Display::draw(ofEventArgs & args)
{ 
	ofSetColor(0, 0, 0);
	
	int x = 20;
	int y = 20+480*2+20;
	
	std:stringstream displayStr;
	displayStr << "scale: " << objectScale;
	displayStr << "\ninvert: " << invert;
	displayStr << "\nthreshold: " << threshold;
	
	
	ttf.drawString(displayStr.str(), x, y);
}