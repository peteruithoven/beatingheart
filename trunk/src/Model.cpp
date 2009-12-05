/*
 *  Model.cpp
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 4/27/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Model.h"
#include <numeric>

Model::Model()
{
	useManualFlowValue = true;
	
	ofAddListener(ofEvents.update, this, &Model::update);

	ofAddListener(timer.TICK, this, &Model::onTick);
	detection.setup();
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
	cout << "Model::updateInterval\n";
	if(useManualFlowValue)
		flowValue = manualFlowValue;
	if(!useManualFlowValue)
		flowValue = detection.getValue();
	
	flowValue *= flowValueMultiplier;
	// limit flowValue
	if(flowValue < 0)
		flowValue = 0;
	else if(flowValue > 1)
		flowValue = 1;	
	
	// keep flow Value History to calculate average flowValue 
	//   over a number of frames
	//cout << "flowValueHistory.size() > numAveragingFrames\n";
	cout << "  " << flowValueHistory.size() << " > " << numAveragingFrames << "\n";
	while(flowValueHistory.size() >= numAveragingFrames)
		flowValueHistory.erase(flowValueHistory.begin());
	flowValueHistory.push_back(flowValue);
	
	/*cout << "  flowValueHistory: \n";
	vector<float>::const_iterator i;
	for(i = flowValueHistory.begin();i!=flowValueHistory.end();i++)
	{
	   cout << "    *i: " << *i << endl;
	}*/
	
	float averageFlowValue = average(flowValueHistory);
	cout << "    averageFlowValue: " << averageFlowValue << endl;
	
	// implement max decrease
	float moveTreshhold = 1-maxDecreasePercentage;
	cout << "    maxDecreasePercentage: " << maxDecreasePercentage << endl;
	cout << "    moveTreshhold: " << moveTreshhold << endl;
	cout << "    prevAverage: " << prevAverage << endl;
	cout << "    prevAverage*moveTreshhold: " << prevAverage*moveTreshhold << endl;
	if(averageFlowValue < prevAverage*moveTreshhold)
	{
		averageFlowValue = prevAverage*moveTreshhold;
	}
	prevAverage = averageFlowValue;
	cout << "    -> averageFlowValue: " << averageFlowValue << endl;
	//n 
	
	interval = (1-averageFlowValue)*flowIntervalRatio;
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

float Model::average(const vector<float> & v)
{
	return accumulate(v.begin(),v.end(),0.0)/v.size();
	//return bezierAverage(v);
}
/*float Model::bezierAverage(const vector<float> & v)
{
	float tempVar = 0.0;
	
	
	tempVar = accumulate(v.begin(),v.end(),0.0)/v.size();
	
	if(tempVar < (prevAverage * moveTreshhold) ){
		tempVar = prevAverage * moveTreshhold;
	}
	
	prevAverage = tempVar;
	cout << "\n"+ofToString(tempVar) + " Current Average";

	
	return  tempVar;
}*/


