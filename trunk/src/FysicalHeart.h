/*
 *  FysicalHeart.h
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 11/17/09.
 *  Copyright 2009 HKU. All rights reserved.
 *
 */

#ifndef _FysicalHeart
#define _FysicalHeart

#include <ofUtils.h>
#include "ofxSimpleSerial.h"
#include "DisplayObject.h"

class FysicalHeart : public DisplayObject 
{

public:
	FysicalHeart();
	void		beat();
	
protected:
	ofxSimpleSerial serial;
	
	void		onNewMessage(string & message);
		
};

#endif
