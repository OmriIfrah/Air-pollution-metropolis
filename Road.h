/*
 * Road.h
 *
 *  Created on: 25 במאי 2020
 *      Author: Omrii
 */

#ifndef ROAD_H_
#define ROAD_H_

#include <iostream>
using namespace std;
class Road {
public:
	Road();
	Road(int from,int to,double& w);
	virtual ~Road();
	const Road operator++(int);



	double getPollution() const {
		return pollution;
	}

	void setPollution(double pollution) {
		this->pollution = pollution;
	}

	double getWeight() const {
		return weight;
	}

	void setWeight(double weigh) {
		this->weight = weigh;
	}

	int getFrom() const {
		return from;
	}

	void setFrom(int from) {
		this->from = from;
	}

	int getTo() const {
		return to;
	}

	void setTo(int to) {
		this->to = to;
	}

	double getC() const {
		return c;
	}

	void setC(double c) {
		this->c = c;
	}

	double pollutionNum();

private:
	int from;
	int to;
	double c;
	double weight;
	double pollution;

};

#endif /* ROAD_H_ */
