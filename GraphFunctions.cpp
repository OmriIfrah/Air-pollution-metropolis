/*
 * GraphFunctions.cpp
 *
 *  Created on: 25 במאי 2020
 *      Author: Omrii
 */

#include "GraphFunctions.h"

double** getGraph(char* metFile,unsigned int& size,unsigned int& roadSize)
{
	ifstream infile(metFile);
	if(!infile)
	{
		cerr<<"Error: Invalid input."<<endl;
	}
	string str;

	unsigned int i=0 , j=0;
	getline(infile,str,'\n');
	size = strtof((str).c_str(),0);
	double**graph = new double*[size]();
	for(unsigned int k=0; k< size ;k++)
	{
		graph[k] = new double[size]();

	}
	while(getline(infile, str))
	{   // get a whole line
		istringstream ss(str);
	    while(getline(ss, str, ' '))
	    {
	    	graph[i][j] = strtof((str).c_str(),0);
	    	if(i == j && graph[i][j] != 0)
	    	{
	    		cerr<<"Error: Invalid input."<<endl;
	    		exit(1);
	    	}
	    	if(graph[i][j] > 0)
	    	{
	    		roadSize++;
	    	}
	    	++j;
	    	if(j == (size))
	    	{
	    		j=0;
	    		i++;
	    	}
	    }
	}
	infile.close();
	return graph;
}

void printGraph(double** graph,unsigned int& size)
{
	cout<<size<<endl;
	for(unsigned int i =0;i < size;i++)
	{
		for(unsigned int j=0;j<size;j++)
		{
			cout<< graph[i][j] <<" ";
		}
		cout<<endl;
	}

}

int** getGraphNodes(char* fileName,unsigned int size,unsigned int* carSize)
{
	ifstream infile(fileName);
	if(!infile)
	{
		cerr<<"Error: Invalid input."<<endl;
	}
	int** graphNodes = new int*[size]();
	for(unsigned int k=0; k< size ;k++)
	{
		graphNodes[k] = new int[size]();

	}
	string str;

	unsigned int i=0 , j=0;

	while(getline(infile, str))
	{   // get a whole line
		istringstream ss(str);
		getline(ss, str, ':');

		while(getline(ss, str,' '))
		{
			if (isdigit(str[0]))
			{
				graphNodes[i][j] = strtof((str).c_str(),0);
				j++;
				(*carSize)++;
			}
		}


		while(j<size)
		{
			graphNodes[i][j] = 0;
			j++;
		}
		j=0;
		i++;
	}



	infile.close();
	return graphNodes;

}

void printGraphNodes(int** graphNodes,unsigned int size)
{
	for(unsigned int i =0;i<size;i++)
	{
		cout<< i+1 <<":";
		for(unsigned int j=0;j<size;j++)
		{
			if(graphNodes[i][j] == 0)
			{
				cout<<endl;
				break;
			}

			if(j==(size-1))
				cout<<" "<<graphNodes[i][j]<<endl;
			else
				cout<<" "<< graphNodes[i][j];
		}

	}

	return;
}


Nodes* setNodesNeighbors(double** graph,unsigned int size)
{
	Nodes* nodes = new Nodes[size];
	for(unsigned int i=0;i<size;i++)
	{
		unsigned int nodeCnt=1;
		int* neighbors = new int[size];
		neighbors[nodeCnt-1] = i+1;
		nodes[i].setNumber(i+1);
		for(unsigned int j=0;j<size;j++)
		{
			if(graph[i][j] > 0 )
			{
				neighbors[nodeCnt] = (j+1);
				nodeCnt++;
			}
		}
		nodes[i].setNeighbors(neighbors,nodeCnt);
		nodes[i].setNeighborsSize(nodeCnt);
	}
	return nodes;
}

Car* setNodesAndCars(int** graphNodes,unsigned int size,Nodes* nodes)
{
	Car cars[1000];
	unsigned int carCnt=0;
	for(unsigned int i=0;i<size;i++)
	{
		for(unsigned int j=0;j<size;j++)
		{
			if(graphNodes[i][j] > 0 )
			{
				cars[carCnt].setName(graphNodes[i][j]);
				cars[carCnt].setPlace(i+1);
				carCnt++;
			}
		}

	}
	Car* newCar = new Car[carCnt];

	for(unsigned int j=0;j<carCnt;j++)
	{
		newCar[j].setName(cars[j].getName());
		newCar[j].setPlace(cars[j].getPlace());
	}
	return newCar;
}

int** newGraphNodes(unsigned int size,Car* cars,unsigned int carSize)
{
	int** graphNodes;
	int place;
	unsigned int j=0;
	graphNodes = new int*[size];
	for(unsigned int i=0;i<size;i++)
	{
		graphNodes[i] = new int[size];
	}
	for(unsigned int j=0;j<size;j++)
	{
		for(unsigned int k=0;k<size;k++)
		{
			graphNodes[j][k]=0;
		}
	}
	for(unsigned int i=0;i<carSize;i++)
	{
		place = cars[i].getPlace();
		while(j<size)
		{
			if(graphNodes[place-1][j] == 0)
			{
				graphNodes[place-1][j] = cars[i].getName();
				j=size;
			}
			else
				++j;
		}
		j=0;
	}
	return graphNodes;
}

void printCars(Car* cars,unsigned int carSize)
{
	for(unsigned int i=0;i<carSize;i++)
	{
		cout<<"car number " <<cars[i].getName()<<"in place"<<cars[i].getPlace()<<endl;
	}
	return;
}
void printNodes(Nodes* nodes,unsigned int size)
{
	unsigned int nsize;
	int* neb;
	for(unsigned int i=0;i<size;i++)
	{
		nsize = nodes[i].getNeighborsSize();
		cout<<"node number " <<nodes[i].getNumber()<<endl;
		neb = nodes[i].getNeighbors();
		for(unsigned int k=0;k<nsize;k++)
		{
			cout<<"neb  "<<i<<" = " <<neb[k]<<endl;
		}
	}
	return;
}



