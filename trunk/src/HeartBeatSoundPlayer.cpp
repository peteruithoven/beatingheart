/*
 *  HeartBeatSoundPlayer.cpp
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 11/18/09.
 *  Copyright 2009 HKU. All rights reserved.
 *
 */

#include "HeartBeatSoundPlayer.h"
#include "ofMath.h"

HeartBeatSoundPlayer::HeartBeatSoundPlayer()
{
	int shortInterval = 500;
	timer.setInterval(shortInterval);
	timer.setRepeatCount(1);
	ofAddListener(timer.TICK, this, &HeartBeatSoundPlayer::onTick);
	
	//TODO find the proper way to fill a vector with multiple items at once
	beats.push_back("beat1.1.wav");
		beats.push_back("beat1.2.wav");
	beats.push_back("beat2.1.wav");
		beats.push_back("beat2.2.wav");
	beats.push_back("beat3.1.wav");
		beats.push_back("beat3.2.wav");
	
	refillBeatsToPlay();
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
	beatsToPlay = shuffle(beats);
}



vector<string > HeartBeatSoundPlayer::shuffle(vector<string> toShuffle)
{	
	vector<string> copy = toShuffle;
	vector<string> shuffled;
	
	vector<string>::iterator iter;
	while(copy.size() > 0)
	 {
		int randomIndex = ofRandom(0,copy.size()/2);
		iter = copy.begin()+randomIndex*2;
		shuffled.push_back(*iter);
		iter = copy.erase(iter);
		shuffled.push_back(*iter);
		copy.erase(iter);
	 }
	return shuffled;
}