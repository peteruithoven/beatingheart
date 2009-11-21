/*
 *  HeartBeatSoundPlayer.h
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 11/18/09.
 *  Copyright 2009 HKU. All rights reserved.
 *
 */

#ifndef _HeartBeatSoundPlayer
#define _HeartBeatSoundPlayer

#include <ofUtils.h>
#include <ofSoundPlayer.h>
#include <vector>
#include "Timer.h"



class HeartBeatSoundPlayer{

public:
	
	HeartBeatSoundPlayer();
	void beat();
	
	
protected:
	ofSoundPlayer	heart;
	vector<string>	beats;
	vector<string>	beatsToPlay;
	Timer timer;
	
	void onTick(int  & count);
	void refillBeatsToPlay();
	vector<string> shuffle(vector<string>);
};

#endif
