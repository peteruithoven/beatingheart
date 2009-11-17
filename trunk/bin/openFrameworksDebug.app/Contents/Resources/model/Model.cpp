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
	ofAddListener(objectTracker.TRACKED_OBJECTS,this,&Model::onTrackedObjects);
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
	
	//objectTracker.threshold		= xml.getValue("threshold", 1.0);
	
	///cout << "\n  threshold: " << objectTracker.threshold;
				
}
void Model::onFlowUpdate(float flowValue)
{
	ofNotifyEvent(FLOW_UPDATE,flowValue,this);
}

void Model::learnBackground()
{
	//objectTracker.learnBackground();
}
int Model::getThreshold()
{
	return 1; //objectTracker.threshold;
}
void Model::setThreshold(int threshold)
{
	if (threshold > 255) threshold = 255;
	cout << "\n    threshold: ";
	cout << threshold;
	//objectTracker.threshold = threshold;
	
	storeValues();
}
bool Model::getDebug()
{
	return false //bjectTracker.debug;
}
void Model::setDebug(bool debug)
{
	//objectTracker.debug = debug;
}

void Model::storeValues()
{
	int fakeInt = 0;
	ofNotifyEvent(VALUES_UPDATED,fakeInt,this);
	
	xml.setValue("threshold", getThreshold());
	xml.saveFile("settings.xml");
}
