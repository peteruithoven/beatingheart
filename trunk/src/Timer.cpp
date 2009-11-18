/*
 *  Timer.cpp
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 11/17/09.
 *  Copyright 2009 HKU. All rights reserved.
 *  
 *  Future TODO:
 *  - repeatCount option
 *    0: repeats continues
 *    >0: repeats that many times
 */

#include "Timer.h"

Timer::Timer()
{
	count		= 0;
	running		= false;
	interval	= 1000;
	startTime	= 0;
}
void Timer::update(ofEventArgs & args)
{
	//cout << "Timer::update\n";
	int elapsedTime = ofGetElapsedTimeMillis();
	if(elapsedTime > startTime+interval)
	 {
		tick();
		start();
	 }
}
void Timer::tick()
{
	ofNotifyEvent(TICK,count,this);
	count++;
}


bool Timer::getRunning()
{
	return running;
};
int Timer::getCount()
{
	return count;
};
int Timer::getInterval()
{
	return interval;
};	
void Timer::setInterval(int value)
{
	interval = value;
	//cout << "interval: " << interval << endl;
};
void Timer::start()
{
	//cout << "Timer::start\n";
	startTime = ofGetElapsedTimeMillis();
	running = true;
	ofAddListener(ofEvents.update, this, &Timer::update);
};
void Timer::pause()
{
	ofRemoveListener(ofEvents.update, this, &Timer::update);
	running = false;
};
void Timer::reset()
{
	pause();
	count = 0;
};