/*
 *  Timer.h
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 11/17/09.
 *  Copyright 2009 HKU. All rights reserved.
 *	
 */

#ifndef _Timer
#define _Timer

#include <ofUtils.h>
#include <ofEvents.h>

class Timer{

	public:
		Timer();
	
		bool getRunning();
		int getCount();
		int getInterval();	
		void setInterval(int interval);
		
		void start();
		void reset();
		void pause();
		
		ofEvent< int > TICK;
	
	protected:
		bool running;
		int interval; //milliseconds
		int startTime;
		int count;
	
		void update(ofEventArgs & args);
	void tick();
};

#endif
