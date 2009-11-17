/*
 *  DisplayView.cpp
 *  openFrameworks
 *
 *  Created by Peter Uithoven on 5/30/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "DisplayView.h"

DisplayView::DisplayView()
{
	
}

void DisplayView::setModel(Model * model)
{
	this->model = model;
	ofAddListener(model->VALUES_UPDATED,this,&DisplayView::onValuesUpdated);
}

void DisplayView::onValuesUpdated(int & arg)
{
	display.objectScale = +model->getObjectsScale();
	display.invert = +model->getInvert();
	display.threshold = +model->getThreshold();
}