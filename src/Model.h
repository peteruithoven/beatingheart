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

class Model{

	public:
		ofxXmlSettings xml;
		
		Model();
		void loadData();
		void learnBackground();
		int getThreshold();
		void setThreshold(int threshold);
		bool getDebug();
		void setDebug(bool debug);
		void storeValues();
		
		//TODO implement notify
		ofEvent< float > FLOW_UPDATE;
		ofEvent< int > VALUES_UPDATED;
		
	protected:
	
		void parseXML();
		void onFlowUpdate(float flowValue);
};

#endif
