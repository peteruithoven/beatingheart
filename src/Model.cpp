/*
 *  Model.cpp
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 4/27/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Model.h"

Model::Model()
{
	ofAddListener(ofEvents.update, this, &Model::update);
	
	ofAddListener(timer.TICK, this, &Model::onTick);
}

void Model::onTick(int  & count)
{
	beat();
}

void Model::update(ofEventArgs & args)
{ 
	
}
	
void Model::loadData()
{
	cout << "Model::loadData\n";
	
	cout << " loading settings.xml\n";
	if( xml.loadFile("settings.xml") ){
		cout << "settings.xml loaded!\n";
	}else{
		cout << "unable to load settings.xml check data/ folder\n";
	}
	
	parseXML();
	
	storeValues();
}
void Model::parseXML()
{
	cout << "Model::parseXML\n";
	
	//TODO fill properties like flow -> interval scale etc. 
	
	//TODO start system
	onFlowUpdate(1);
}

void Model::onFlowUpdate(float flowValue)
{
	cout << "Model::onFlowUpdate\n";
	//TODO translate flowValue to interval with some kind of scale
	//  flowValue should be between 0 and 1
	
	
	// store interval
	// if interval complete begin new interval
	timer.setInterval(flowValue*1200);
	// after interfal: beat!
	if(!timer.getRunning())
		timer.start();
}

void Model::beat()
{
	cout << "Model::beat\n";
	int someInt = 0;
	ofNotifyEvent(BEAT,someInt,this);
}

void Model::learnBackground()
{
	//TODO implement
}
int Model::getThreshold()
{
	return 1; //TODO implement
}
void Model::setThreshold(int threshold)
{
	if (threshold > 255) threshold = 255;
	
	//TODO implement
	
	storeValues();
}
bool Model::getDebug()
{
	return false; //TODO implement
}
void Model::setDebug(bool debug)
{
	//TODO implement
}

void Model::storeValues()
{
	int fakeInt = 0;
	ofNotifyEvent(VALUES_UPDATED,fakeInt,this);
	
	xml.setValue("threshold", getThreshold());
	xml.saveFile("settings.xml");
}
