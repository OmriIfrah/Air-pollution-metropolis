/*
 * Metropolis.cpp
 *
 *  Created on: 25 במאי 2020
 *      Author: Omrii
 */

#include "Metropolis.h"

Metropolis::Metropolis(double** graph, unsigned int size)
{
	this->graph = graph;
	this->size = size;
	 pollution = 0;
	 roadSize = 0;
	 c=0;
	 roads = NULL;
}

void Metropolis::setRoads()
{
	Road* tmp = new Road[500];
	for(unsigned int i=0;i<size;i++)
	{
		for(unsigned int j=0;j<size;j++)
		{
			if(graph[i][j]>0)
			{
				tmp[roadSize].setFrom(i);
				tmp[roadSize].setTo(j);
				tmp[roadSize].setWeight(graph[i][j]);
				roadSize+=1;
			}
		}
	}
	roads = new Road[roadSize];
	for(unsigned int i=0;i<roadSize;i++)
	{
		roads[i].setFrom(tmp[i].getFrom());
		roads[i].setTo(tmp[i].getTo());
		roads[i].setWeight(tmp[i].getWeight());
		roads[i].setC(c);
	}
	delete[] tmp;
	return;
}

int Metropolis::getRoadNum(int from,int to)
{
	int f,t;
	for(unsigned int i=0;i<roadSize;i++)
	{
		f=roads[i].getFrom();
		t=roads[i].getTo();
		if(f == from && t == to)
		{
			return i;
		}
	}
	return -1;
}

void Metropolis::addPollution(double pollution)
{
		this->pollution += pollution;
}

Road* Metropolis::getRoads()
{
	return roads;
}


Metropolis::~Metropolis() {
	// TODO Auto-generated destructor stub
}

