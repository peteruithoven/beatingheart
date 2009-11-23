/*
 *  FysicalHeart.cpp
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 11/17/09.
 *  Copyright 2009 HKU. All rights reserved.
 *
 */

#include "FysicalHeart.h"

FysicalHeart::FysicalHeart()
{
	//serial.setup("/dev/tty.usbserial-A70060V8", 9600);
	//serial.setup("/dev/tty.usbserial-A9007L0E", 9600);
	//serial.startContinuesRead();
	ofAddListener(serial.NEW_MESSAGE,this,&FysicalHeart::onNewMessage);
}

void FysicalHeart::beat()
{
	cout << "FysicalHeart::beat\n";
	//serial.writeByte('b');
}

void FysicalHeart::onNewMessage(string & message)
{
	cout << "onNewMessage, message: " << message << "\n";
	
	//vector<string> input = ofSplitString(message, ",");
	
}