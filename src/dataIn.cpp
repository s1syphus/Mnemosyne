
//dataIn.cpp
//
//This is going to be for reading in/parsing csv's containing data for training/testing

#include "dataIn.h"

//Current (for now) format:
//
//First line: 
//
//n1, n2, ..., nn
//n1 = number inputs
//n2..nn-1 = hidden neurons
//nn = number outputs
//
//rest of file:
//input1, input2, ..., inputn, output1, output2, ..., outputn 
//
//


TrainingData::TrainingData(const string filename){
	m_trainingDataFile.open(filename.c_str());
	}

bool TrainingData::isEOF(){
	return m_trainingDataFile.eof();
	}

void TrainingData::loadData(vector<unsigned> &topology, 
		vector<vector<double> > &inputVals, vector<vector<double> > &targetOutputs){
	
	topology.clear();
	inputVals.clear();
	targetOutputs.clear();
	string line;
	unsigned n;
	getline(m_trainingDataFile, line);
	stringstream ss(line);
	//first line contains topology information
	while(!ss.eof()){
		ss >> n;
		topology.push_back(n);
		}
	double value;
	vector<double> tempInput, tempOutput;
	unsigned counter;
	while(!isEOF()){
		getline(m_trainingDataFile, line);
		stringstream ss(line);
		counter = 0;
		tempInput.clear();
		tempOutput.clear();
		while(ss >> value){
			if(counter < topology.front()){
				//input vals
				tempInput.push_back(value);
								}
			else{
				//output vals
				tempOutput.push_back(value);
				}
			counter++;
			}

		inputVals.push_back(tempInput);
		targetOutputs.push_back(tempOutput);

		}
	}


