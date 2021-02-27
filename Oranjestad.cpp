/*
 * Oranjestad.cpp
 *
 *  Created on: 25 במאי 2020
 *      Author: Omrii
 */

#include "Oranjestad.h"



void moveCars(Car* cars,unsigned int carSize,Nodes* nodes,Metropolis* metro,Road* roads)
{
	int* neighborsList;
	int neighborSize=0,from,to,roadNum;
	for (unsigned int i=0;i < carSize;i++)
	{
		from = cars[i].getPlace();
		neighborsList = nodes[from-1].getNeighbors();
		neighborSize = nodes[from-1].getNeighborsSize();
		to = neighborsList[getNewPlace(neighborSize)];
		cars[i].setPlace(to);
		nodes[from-1].setCarSize(nodes[from-1].getCarSize()-1);
		nodes[to-1].setCarSize(nodes[to-1].getCarSize()+1);
		roadNum = metro->getRoadNum(from-1,to-1);
		metro->addPollution(roads[roadNum].pollutionNum());
		roads[roadNum]++;
	}
}

int getNewPlace(int num)
{
	srand (time(NULL));
	 return rand() % num;
}

void printPollution(Road* roads,unsigned int roadSize,unsigned int size,Metropolis metro)
{
	int roadNum = -1;
	for(unsigned int i=0;i<size;i++)
	{
		for(unsigned int j=0;j<size;j++)
		{
			roadNum =  metro.getRoadNum(i,j);
			if(roadNum >= 0)
			{
				if(j == size-1)
				{
					cout<<roads[roadNum].getPollution()<<endl;
				}
				else
				{
					cout<<roads[roadNum].getPollution()<<" ";
				}
			}
			else
			{
				if(j == size-1)
				{
					cout<<"0"<<endl;
				}
				else
				{
					cout<<"0 ";
				}
			}
		}
	}
		return;
}

void printMetroRoads(Metropolis metro)
{
	unsigned int size = metro.getRoadSize();
	Road* roads = metro.getRoads();
	for(unsigned int i=0;i<size;i++)
	{
		cout<<i<<" road - "<<roads[i].getFrom()<< " , "<<roads[i].getTo()<< "whith w "<<roads[i].getWeight()<<endl;
	}

}



