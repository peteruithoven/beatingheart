/*
 *  MainView.cpp
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 4/27/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *	
 *	
 */

#include "MainView.h"
#include "ofMain.h"
#include "ofEvents.h"

MainView::MainView()
{
	ofBackground(0,0,0);
	ofAddListener(ofEvents.draw, this, &MainView::draw);
	
}

void MainView::setModel(Model * model)
{
	this->model = model;
}

void MainView::draw(ofEventArgs & args)
{
	
}