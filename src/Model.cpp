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
	useManualFlowValue = true;
	
	ofAddListener(ofEvents.update, this, &Model::update);
	ofAddListener(ofEvents.keyReleased, this, &Model::keyReleased);
	ofAddListener(ofEvents.keyPressed, this, &Model::keyPressed);

	ofAddListener(timer.TICK, this, &Model::onTick);
}

void Model::update(ofEventArgs & args)
{ 
	//TODO get flowValue from Flow Detection instance
	//flowValue = value;
	//updateInterval();
}
void Model::keyReleased(ofKeyEventArgs & args)
{
	switch (args.key){
		case ' ':
			 //model->learnBackground();
			 updateInterval();
			 break;
		/*case '+':
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
			break;*/
	}
};
void Model::keyPressed(ofKeyEventArgs & args)
{
}

void Model::loadData()
{
	cout << "Model::loadData\n";
	
	cout << " loading settings.xml\n";
	if( xml.loadFile("settings.xml") )
	{
	   cout << "settings.xml loaded!\n";
	   parseXML();
	   storeValues();
	   
	   // start system
	   flowValue = 0.3;
	   updateInterval();
	}
	else
	{
		cout << "unable to load settings.xml check data/ folder\n";
	}
}
void Model::parseXML()
{
	cout << "Model::parseXML\n";
	
}

void Model::updateInterval()
{
	// limit flowValue
	if(manualFlowValue)
		flowValue = manualFlowValue;
	
	if(flowValue < 0)
		flowValue = 0;
	else if(flowValue > 1)
		flowValue = 1;	
	
	interval = (1-flowValue)*flowIntervalRatio;
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
	cout << "storeValues\n";
	int fakeInt = 0;
	ofNotifyEvent(VALUES_UPDATED,fakeInt,this);
	
	cout << "  flowIntervalRatio: " << flowIntervalRatio << endl;
	cout << "  baseInterval: " << baseInterval << endl;
}
