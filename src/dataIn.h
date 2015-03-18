
//dataIn.h

#ifndef READ_IN_DATA_H
#define READ_IN_DATA_H

//right now this is verbatim from david miller
//http://millermattson.com/dave
//
//going to write my own soon but what to make sure stuff is working
//neural-net-wise

#include <fstream>
#include <sstream>
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>


using namespace std;

class TrainingData
{
public:
    TrainingData(const string filename);
    bool isEof(void) { return m_trainingDataFile.eof(); }
    void getTopology(vector<unsigned> &topology);

    // Returns the number of input values read from the file:
    unsigned getNextInputs(vector<double> &inputVals);
    unsigned getTargetOutputs(vector<double> &targetOutputVals);

private:
    ifstream m_trainingDataFile;
};








#endif
