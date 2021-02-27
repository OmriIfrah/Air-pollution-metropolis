//============================================================================
// Name        : HomeWork3.cpp
// Author      : Omri
// Version     :
// Copyright   : Your copyright notice
// Description : 
//============================================================================

#include "GraphFunctions.h"
#include "Nodes.h"
#include "Car.h"
#include "Road.h"
#include "Metropolis.h"
#include "Oranjestad.h"
#include <iostream>
using namespace std;

int main(int argc,char *argv[]) {
	if(argc != 3)
	{
		cerr<<"Error: Invalid input."<<endl;
		exit(0);
	}
	double** graph;
	int** graphNodes;
	double c=0;
	int timeCnt=0;
	unsigned int roadSize=0,carSize=0,size=0;
	graph = getGraph(argv[1],size,roadSize);

	graphNodes = getGraphNodes(argv[2],size,&carSize);

	Nodes* nodes = setNodesNeighbors(graph,size);
	
	Car* cars= setNodesAndCars(graphNodes,size,nodes);
	Metropolis metro(graph,size);
	
	cin>>c;
	cin>>timeCnt;
	
	metro.setC(c);
	metro.setRoads();
	
	Road* roads = metro.getRoads();
	
	for(int i=0;i<timeCnt;i++)
	{
	moveCars(cars,carSize,nodes,&metro,metro.getRoads());
	}
	
	graphNodes= newGraphNodes(size,cars,carSize);
	printPollution(roads,metro.getRoadSize(),size,metro);
	printGraphNodes(graphNodes,size);
	cout<<endl;



	return 0;
}
