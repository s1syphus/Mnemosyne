
//data.h

#ifndef DATA_H
#define DATA_H

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

class Data{

	public:
		Data(string);
		void makeCut();	//k-folds for data
		vector<vector<double> > getTrainingInput();
		vector<vector<double> > getTrainingOutput();
		vector<vector<double> > getTestingInput();
		vector<vector<double> > getTestingOutput();
		void printInputVals();
		void printOutputVals();

	private:
		//these are aligned, ie.
		//inputVal[0] corresponds to outputVal[0]
		vector<vector<double> > inputVals;
		vector<vector<double> > outputVals;
		vector<unsigned> topology;
		vector<vector<double> > trainingInput;
		vector<vector<double> > trainingOutput;
		vector<vector<double> > testingInput;
		vector<vector<double> > testingOutput;
		void loadData(string);
		void genIndices(vector<unsigned> &, unsigned, 
				vector<unsigned> &, unsigned);

	};



#endif
