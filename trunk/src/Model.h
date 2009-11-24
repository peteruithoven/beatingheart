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

class Model{

	public:
		ofxXmlSettings xml;
		
		Model();
		void start();
	
		int getInterval();
	
		float flowValue;
		float manualFlowValue;
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
};

#endif
