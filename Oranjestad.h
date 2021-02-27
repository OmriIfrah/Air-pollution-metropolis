/*
 * Oranjestad.h
 *
 *  Created on: 25 במאי 2020
 *      Author: Omrii
 */

#ifndef ORANJESTAD_H_
#define ORANJESTAD_H_
#include "Car.h"
#include "Nodes.h"
#include "Road.h"
#include "Metropolis.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
#include <time.h>
using namespace std;


void moveCars(Car* cars,unsigned int carSize,Nodes* nodes,Metropolis* metro,Road* roads);
int getNewPlace(int num);
void printPollution(Road* roads,unsigned int roadSize,unsigned int size,Metropolis metro);
void printMetroRoads(Metropolis metro);


#endif /* ORANJESTAD_H_ */
