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

	ofAddListener(timer.TICK, this, &Model::onTick);
}

void Model::update(ofEventArgs & args)
{ 
	//TODO get flowValue from Flow Detection instance
	//flowValue = ...;
	updateInterval();
}
void Model::start()
{
	flowValue = 0.3;
	updateInterval();
}

void Model::updateInterval()
{
	// limit flowValue
	if(useManualFlowValue)
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
	
	int fakeInt = 0;
	ofNotifyEvent(VALUES_UPDATED,fakeInt,this);
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

// ------ PROPERTIES --------
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