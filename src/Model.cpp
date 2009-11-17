/*
 *  Model.cpp
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 4/27/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Model.h"
#include "ofEvents.h"

Model::Model()
{
	
}
void Model::loadData()
{
	cout << "\nModel::loadData";
	
	cout << "\n loading settings.xml";
	if( xml.loadFile("settings.xml") ){
		cout << "\nsettings.xml loaded!";
	}else{
		cout << "\nunable to load settings.xml check data/ folder";
	}
	
	parseXML();
	
	storeValues();
}
void Model::parseXML()
{
	cout << "\nModel::parseXML";
	
				
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
