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
	ofBackground(255,255,255);
	ofAddListener(ofEvents.draw, this, &MainView::draw);
	
	margin = 20;
	
	inputX = 9;
	inputY = 134;
	inputWidth = 364;
	inputHeight = 273;
	
	world.x = margin+inputX;
	world.y = margin+inputY;
	world.width = inputWidth;
	world.height = inputHeight;
}

void MainView::setModel(Model * model)
{
	this->model = model;
	ofAddListener(model->COLOR_CHANGED,this,&MainView::onColorChanged);
	ofAddListener(model->TRACKED_OBJECTS,this,&MainView::onTrackedObjects);
}

void MainView::onColorChanged(int & _color)
{
//	color = _color;
	color = model->color;

	cout << "\n\nModel:\n";	
	cout << model->color;
	cout << "\n\n";	
	//indicator.x = 200;
	//indicator.y = 200;
}
void MainView::draw(ofEventArgs & args)
{
	//ofSetColor(model->color);
	//world.color = color;
	world.color = color;
}