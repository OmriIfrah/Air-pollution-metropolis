/*
 * Metropolis.h
 *
 *  Created on: 25 במאי 2020
 *      Author: Omrii
 */

#ifndef METROPOLIS_H_
#define METROPOLIS_H_

#include "Road.h"
#include <iostream>
using namespace std;

class Metropolis {
public:
	Metropolis (double** graph, unsigned int size);
	void setRoads();
	int getRoadNum(int from,int to);
	Road* getRoads();
	virtual ~Metropolis();

	double getC() const {
		return c;
	}

	void setC(double c) {
		this->c = c;
	}

	double getPollution() const {
		return pollution;
	}

	void addPollution(double pollution) ;

	double** getGraph() const {
		return graph;
	}

	unsigned int getRoadSize() const {
		return roadSize;
	}

private:
	double** graph;
	unsigned int size;
	Road* roads;
	double pollution;
	double c;
	unsigned int roadSize;

};

#endif /* METROPOLIS_H_ */
