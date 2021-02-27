/*
 * Nodes.cpp
 *
 *  Created on: 23 במאי 2020
 *      Author: Omrii
 */

#include "Nodes.h"

Nodes::Nodes()
{
	number = 0;

	carSize=0;
	neighbors = NULL;
	carSize=0;
	neighborsSize=0;;

}

Nodes::Nodes(int num)
{
	number = num;
	carSize=0;
	neighborsSize=0;;
	neighbors = NULL;
}

void Nodes::setNeighbors(int* neighbors,unsigned int nsize)
{
	this->neighbors = new int[nsize];
	for(unsigned int i =0 ;i<nsize;i++)
	{
		this->neighbors[i] = neighbors[i];
	}
	return;
}
Nodes::~Nodes()
{

}




