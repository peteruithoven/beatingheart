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
	int shortInterval = 500;
	timer.setInterval(shortInterval);
	timer.setRepeatCount(1);
	ofAddListener(timer.TICK, this, &HeartBeatSoundPlayer::onTick);
	
	//TODO find the proper way to fill a vector with multiple items at once
	/*beats.assign(
				 "beat1.1.wav","beat1.2.wav",
				 "beat2.1.wav","beat2.2.wav"
				 );*/
	
	/*beats (
				 "beat1.1.wav","beat1.2.wav",
				 "beat2.1.wav","beat2.2.wav"
				 );*/
	
	/*beats = (
		   "beat1.1.wav","beat1.2.wav",
		   "beat2.1.wav","beat2.2.wav"
		   );*/
	
	/*beats = {
			 "beat1.1.wav","beat1.2.wav",
			 "beat2.1.wav","beat2.2.wav"
			};*/
	
	beats.push_back("beat1.1.wav");
		beats.push_back("beat1.2.wav");
	beats.push_back("beat2.1.wav");
		beats.push_back("beat2.2.wav");
	
	//TODO fill randomly (keeping the parts together)
	beatsToPlay = beats;
	
	//heart.loadSound("sounds/beat.wav");
	//heart.loadSound("sounds/beat1.1.wav");
}
void HeartBeatSoundPlayer::beat()
{
	cout << "HeartBeatSoundPlayer::beat\n";
	
	string url = "sounds/" + beatsToPlay.front();
	cout << "  url: " << url << "\n";
	beatsToPlay.erase(beatsToPlay.begin());
	heart.loadSound(url);
	
	heart.play();
	timer.start();
}
void HeartBeatSoundPlayer::onTick(int  & count)
{
	cout << "HeartBeatSoundPlayer::onTick\n";
	//heart.loadSound("sounds/beat1.2.wav");
	
	string url = "sounds/" + beatsToPlay.front();
	cout << "  url: " << url << "\n";
	beatsToPlay.erase(beatsToPlay.begin());
	heart.loadSound(url);
	heart.play();
	
	if(beatsToPlay.size() == 0)
		refillBeatsToPlay();
}

void HeartBeatSoundPlayer::refillBeatsToPlay()
{
	cout << "HeartBeatSoundPlayer::refillBeatsToPlay\n";
	beatsToPlay = beats;
}