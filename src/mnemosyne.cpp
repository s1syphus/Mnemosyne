
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


int main(int argc, char** argv){

	//net creation stuff here
	//add in some sort of load function
	//will have to create some data to test, probably XOR (standard)


	//this is from david miller
	//website is in one of the other files
	//just being used for testing purposes, will replace later

	TrainingData trainData("../data/xorData.txt");
	vector<unsigned> topology;
	    trainData.getTopology(topology);

	    Net myNet(topology);

	    vector<double> inputVals, targetVals, resultVals;
	    int trainingPass = 0;

	    while (!trainData.isEof()) {
		++trainingPass;
		cout << endl << "Pass " << trainingPass;

		// Get new input data and feed it forward:
		if (trainData.getNextInputs(inputVals) != topology[0]) {
		    break;
		}
		showVectorVals(": Inputs:", inputVals);
		myNet.feedForward(inputVals);

		// Collect the net's actual output results:
		myNet.getResults(resultVals);
		showVectorVals("Outputs:", resultVals);

		// Train the net what the outputs should have been:
		trainData.getTargetOutputs(targetVals);
		showVectorVals("Targets:", targetVals);
		assert(targetVals.size() == topology.back());

		myNet.backProp(targetVals);

		// Report how well the training is working, average over recent samples:
		cout << "Net recent average error: "
			<< myNet.getRecentAverageError() << endl;
	    }

	    cout << endl << "Done" << endl;











	


	return 0;
	}
