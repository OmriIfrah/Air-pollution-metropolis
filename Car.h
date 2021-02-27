/*
 * Car.h
 *
 *  Created on: 23 במאי 2020
 *      Author: Omrii
 */

#ifndef CAR_H_
#define CAR_H_

#include <iostream>
using namespace std;

class Car {
public:
	Car(int id,int p);
	Car();
	virtual ~Car();

	int getName() const {
		return name;
	}

	void setName(int name) {
		this->name = name;
	}

	int getPlace() const {
		return place;
	}

	void setPlace(int place) {
		this->place = place;
	}

private:
	int name;
	int place;
};

#endif /* CAR_H_ */
