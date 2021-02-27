/*
 * GraphFunctions.h
 *
 *  Created on: 25 במאי 2020
 *      Author: Omrii
 */

#ifndef GRAPHFUNCTIONS_H_
#define GRAPHFUNCTIONS_H_

#include "Nodes.h"
#include "Car.h"
#include "Road.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;


double** getGraph(char* metFile,unsigned int& size,unsigned int& roadSize);
void printGraph(double** graph,unsigned int& size) ;
int** getGraphNodes(char* fileName,unsigned int size,unsigned int* carSize);
void printGraphNodes(int** graphNodes,unsigned int size);
Nodes* setNodesNeighbors(double** graph,unsigned int size);
Car* setNodesAndCars(int** graphNodes,unsigned int size,Nodes* nodes);
int** newGraphNodes(unsigned int size,Car* cars,unsigned int carSize);
void printCars(Car* cars,unsigned int carSize);
void printNodes(Nodes* nodes,unsigned int size);

#endif /* GRAPHFUNCTIONS_H_ */
