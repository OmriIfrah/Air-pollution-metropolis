/*
 * Road.cpp
 *
 *  Created on: 25 במאי 2020
 *      Author: Omrii
 */

#include "Road.h"

Road::Road()
{
	from = 0;
	to = 0;
	weight= 0;
	pollution = 0;
	c=0;
}

Road::Road(int from,int to,double& w) {
	this->from = from;
	this->to = to;
	weight = w;
	pollution = 0;
	c=0;
}

const Road Road::operator++(int)
{
	Road* tmp = this;
	this->pollution += c/weight;
	return (*tmp);
}

double Road::pollutionNum()
{
	return  c/weight;
}
Road::~Road() {
	// TODO Auto-generated destructor stub
}

