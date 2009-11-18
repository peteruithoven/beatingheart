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
	debugFlowValue = true;
	
	ofAddListener(ofEvents.update, this, &Model::update);
	ofAddListener(ofEvents.keyReleased, this, &Model::keyReleased);
	ofAddListener(ofEvents.keyPressed, this, &Model::keyPressed);

	ofAddListener(timer.TICK, this, &Model::onTick);
}

void Model::update(ofEventArgs & args)
{ 
	
}
void Model::keyReleased(ofKeyEventArgs & args)
{
	switch (args.key){
		case ' ':
			 //model->learnBackground();
			 break;
		case '+':
		case '=':
			 //model->setThreshold(model->getThreshold()+1);
			 break;
		case '-':
		case '_':
			 //model->setThreshold(model->getThreshold()-1);
			 break;
		case 'f':
 			 debugFlowValue = !debugFlowValue;
			 //TODO disable/enable normal flow detection
			 break;
		case ',':
			onFlowUpdate(flowValue+0.1);
			break;
		case '.':
			onFlowUpdate(flowValue-0.1);
			break;
	};
	
};
void Model::keyPressed(ofKeyEventArgs & args)
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
	baseInterval = 2000;
	flowIntervalRatio = 5000;
	
	//TODO start system
	onFlowUpdate(0.3);
}

void Model::onFlowUpdate(float value)
{
	cout << "Model::onFlowUpdate, value: " << value << "\n";
	flowValue = value;
	
	// limit flowValue 
	if(flowValue < 0)
		flowValue = 0;
	else if(flowValue > 1)
		flowValue = 1;	
	
	//TODO translate flowValue to interval with some kind of scale
	//  flowValue should be between 0 and 1 (0: no flow, 1: really busy)
	
	interval = (1-flowValue)*flowIntervalRatio; //*1200
	interval += baseInterval;
	
	timer.setInterval(interval);
	if(!timer.getRunning())
		timer.start();
	
	storeValues();
}

void Model::onTick(int  & count)
{
	beat();
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

// ------ PROPERTIES --------
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
float Model::getFlowValue()
{
	return flowValue;
}
float Model::getFlowIntervalRatio()
{
	return flowIntervalRatio;
}
int Model::getBaseInterval()
{
	return baseInterval;
}
int Model::getInterval()
{
	return interval;
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
	xml.setValue("flowIntervalRatio", flowIntervalRatio);
	xml.setValue("baseInterval", baseInterval);
	xml.saveFile("settings.xml");
}
