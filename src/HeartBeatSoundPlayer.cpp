/*
 *  HeartBeatSoundPlayer.cpp
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 11/18/09.
 *  Copyright 2009 HKU. All rights reserved.
 *
 */

#include "HeartBeatSoundPlayer.h"

HeartBeatSoundPlayer::HeartBeatSoundPlayer()
{
	timeSoundCompleted = -1;
	
	heart.loadSound("sounds/beat.wav");
}
void HeartBeatSoundPlayer::beat()
{
	cout << "HeartBeatSoundPlayer::beat\n";
	heart.play();
}