
//data.cpp

#include "data.h"

Data::Data(string filename){
	loadData(filename);
	}

void Data::makeCut(){
	//make this random soon
	//right now just doing first 90/ last 10
	trainingInput.clear();
	testingInput.clear();
	double numCuts = 10;	//change this to be set later
	unsigned sizeData = inputVals.size();
	assert(sizeData == outputVals.size());	//sanity check
	unsigned trainSize = (int) sizeData*0.9;
	unsigned testSize = sizeData - trainSize;
	vector<unsigned> trainIndices;
	vector<unsigned> testIndices;	
	genIndices(trainIndices, trainSize, testIndices, testSize);
	for(unsigned i = 0; i < trainIndices.size(); i++){
		trainingInput.push_back(inputVals[trainIndices[i]]);
		trainingOutput.push_back(outputVals[trainIndices[i]]);
		}
	assert(trainingInput.size() == trainingOutput.size());
	for(unsigned i = 0; i < testIndices.size(); i++){
		testingInput.push_back(inputVals[testIndices[i]]);
		testingOutput.push_back(outputVals[testIndices[i]]);
		}
	}

void Data::genIndices(vector<unsigned> &train, unsigned trainSize, vector<unsigned> &test, unsigned testSize){
	train.clear();
	test.clear();
	//make this random soon
	for(unsigned i = 0; i < trainSize; i++){
		//random function or something no duplicates
		train.push_back(i);
		}		
	for(unsigned i = 0; i < testSize; i++){
		//random function or something no duplicates
		test.push_back(i+trainSize);
		}		
	}

vector<vector<double> > Data::getTrainingInput(){
	return trainingInput;
	}

vector<vector<double> > Data::getTrainingOutput(){
	return trainingOutput;
	}

vector<vector<double> > Data::getTestingInput(){
	return testingInput;
	}

vector<vector<double> > Data::getTestingOutput(){
	return testingOutput;
	}

void Data::loadData(string filename){
	topology.clear();
	inputVals.clear();
	outputVals.clear();
	string line;
	unsigned n;
	ifstream dataFile;
	dataFile.open(filename.c_str());
	getline(dataFile, line);
	stringstream ss(line);

	//first line contains input/output size info
	vector<unsigned> topology;
	while(!ss.eof()){
		ss >> n;
		topology.push_back(n);
		}
	double value;
	vector<double> tempInput, tempOutput;
	unsigned counter;
	while(!dataFile.eof()){
		getline(dataFile, line);
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
		outputVals.push_back(tempOutput);
		}
	}

//these can be deleted, just here for development
void Data::printInputVals(){
	for(size_t i = 0; i < inputVals.size(); i++){
		for(size_t j = 0; j < inputVals[i].size(); j++){
			cout<<inputVals[i][j]<<"\t";
			}
		cout<<endl;
		}
	}

void Data::printOutputVals(){
	for(size_t i = 0; i < outputVals.size(); i++){
		for(size_t j = 0; j < outputVals[i].size(); j++){
			cout<<outputVals[i][j]<<"\t";
			}
		cout<<endl;
		}
	}

