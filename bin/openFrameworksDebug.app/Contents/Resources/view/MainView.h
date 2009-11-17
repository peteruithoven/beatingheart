/*
 *  MainView.h
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 4/27/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *	
 *  One of the views. Views are responsible for hooking up 
 *	project indipendent components (gui for example) to the project. 
 *	I will listen to the model for changes in (mainly) data 
 *	and will update itself according to that data.
 */

#ifndef _MainView
#define _MainView

#include "model/Model.h"
#include "view/BaseView.h"

class MainView : public BaseView
{

	public:
		
		int color;
		int margin;
		
		float	inputX;
		float	inputY;
		float	inputWidth;
		float	inputHeight;
	
		MainView();
		
		void onColorChanged(int & color);
		void onTrackedObjects(vector<ObjectVO*> & tracked);
		void draw(ofEventArgs & args);
		
		void setModel(Model * model);
		
	protected:
		World world;
		
		vector<PhysicalObjectIndicator*>	indicators;
	
		FakeObject fakeObject;
};

#endif
