
//dataIn.h

#ifndef READ_IN_DATA_H
#define READ_IN_DATA_H

//based on David Miller's neural network
//http://millermattson.com/dave
//
//currently for text input, going to add image support
//in the near future
//
//this is not really neccessary as a seperate class atm but will
//be more complicated soon

#include <fstream>
#include <sstream>
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>


using namespace std;

class TrainingData{
	public:
		TrainingData(string filename);
		void loadData(vector<unsigned> &, 
			vector<vector<double> > &, vector<vector<double> > &);
		bool isEOF();

	private:
		ifstream m_trainingDataFile;
	};

#endif
