/*
 *  Model.h
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 4/27/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _Model
#define _Model

#include "ofEvents.h"
#include "ofxXmlSettings.h"
#include "Timer.h"
#include "Detection.h"

class Model{

	public:
		ofxXmlSettings xml;
		Detection detection;
	
		Model();
		void start();
	
		int getInterval();
	
		float maxDecreasePercentage;
		float prevAverage;
		float flowValue;
		float manualFlowValue;
		float flowValueMultiplier;
		bool useManualFlowValue;
		int flowIntervalRatio;
		int baseInterval;
		int interval;
		// Num frames to extract average flow Value.
		int numAveragingFrames;
	
		bool getDebug();
		void setDebug(bool debug);
	
		
	
		ofEvent<int> BEAT;
		ofEvent< int > VALUES_UPDATED;
		
	protected:
		Timer timer;
		vector<float> flowValueHistory;
	
		void update(ofEventArgs & args);
		void onTick(int  & count);
		void updateInterval();
		void beat();
		float average(const vector<float> & v);
	float bezierAverage(const vector<float> & v);
};

#endif
