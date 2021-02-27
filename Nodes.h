/*
 * Nodes.h
 *
 *  Created on: 23 במאי 2020
 *      Author: Omrii
 */

#ifndef NODES_H_
#define NODES_H_
#include "Car.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

class Nodes {
public:
	Nodes();
	Nodes(int num);
	virtual ~Nodes();
	void setNeighbors();

	unsigned int getCarSize() const {
		return carSize;
	}

	void setCarSize(unsigned int carSize) {
		this->carSize = carSize;
	}

	int* getNeighbors() const {
		return neighbors;
	}

	unsigned int getNeighborsSize() const {
		return neighborsSize;
	}

	void setNeighborsSize(unsigned int neighborsSize) {
		this->neighborsSize = neighborsSize;
	}

	int getNumber() const {
		return number;
	}

	void setNumber(int number) {
		this->number = number;
	}
	void setNeighbors(int* neighbors,unsigned int nsize);


private:
	int number;
	unsigned int carSize,neighborsSize;
	int* neighbors;
};

#endif /* NODES_H_ */
