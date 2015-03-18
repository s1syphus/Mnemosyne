
//mnemosyne.cpp

#include "net.h"
#include "dataIn.h"

//other includes here for data input
//most of the net stuff is in "net" (duh)
//turn this into something more informative soon

#include <iostream>
#include <vector>

using namespace std;


void showVectorVals(string label, vector<double> &v)
{
    cout << label << " ";
    for (unsigned i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }

    cout << endl;
}

void showVectorVals(string label, vector<unsigned> &v)
{
    cout << label << " ";
    for (unsigned i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }

    cout << endl;
}
int main(int argc, char** argv){


	//this is working right now, should change to a trainingData vs testingData soon
	//add in a save function for weights, could be tricky but that should be the next step

	TrainingData myData("../data/newXORData.txt");	//change this to command line or something soon

	vector<unsigned> topology;
	vector<vector<double> > inputVals, targetVals;
	vector<double> resultVals;
	myData.loadData(topology,inputVals, targetVals);	
	Net myNet(topology);

	for(unsigned i = 0; i < inputVals.size(); i++){
		//this loops through all of the training samples that are saved in the vector
		//this will break down for large inputs but at that point, a parallel system
		//needs to be created anyways, which will alleviate both 
		//the memory and processing bottlenecks

		myNet.feedForward(inputVals[i]);	
		myNet.getResults(resultVals);
		myNet.backProp(targetVals[i]);	
		
		cout << "Net recent average error for pass "<<i<<": "<< myNet.getRecentAverageError() << endl;

		}

	return 0;
	}
