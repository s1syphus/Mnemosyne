
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
/*	
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
	        cout << "Net recent average error at index: "<<i<<": "
                << myNet.getRecentAverageError() << endl;

		}
*/
	


	//below is how main should look:
	//
	//trainingData myData("source file")
	//topology = myData.getTopology()
	//Net myNet(topology);
	//myNet.train(myData.trainingData());
	//myNet.test(myData.testingData());
	//myNet.getResults();
	//myNet.save("myWeights.meh");
	// or something to that affect, should be very simple 
	// and abstracted away

	Data myData("../data/XORData.txt");
	//prep data
	myData.makeCut();	//0.9 train/ 0.1 test, this can be changed
	vector<vector<double> > trainingDataInput;
	vector<vector<double> > trainingDataOutput;
	vector<vector<double> > testingDataInput;
	vector<vector<double> > testingDataOutput;

	trainingDataInput = myData.getTrainingInput();
	trainingDataOutput = myData.getTrainingOutput();
	testingDataInput = myData.getTestingInput();
	testingDataOutput = myData.getTestingOutput();

	vector<unsigned> topology;
	topology.push_back(trainingDataInput[0].size());
	topology.push_back(trainingDataOutput[0].size());
	for(size_t i = 0; i < topology.size(); i++){
		cout<<topology[i]<<"\t";
		}
	cout<<endl;
	unsigned n, curLayer = 0, sizeLayer;
	double myEta, myAlpha;
	cout<<"Number of hidden layers > ";
	cin>>n;
	vector<unsigned> hiddenLayers;
	while(n > curLayer){
		cout<<"Size of hidden layer "<<curLayer<<" > ";
		cin>>sizeLayer;
		hiddenLayers.push_back(sizeLayer);	
		curLayer++;
		}
	topology.insert(topology.begin()+1, hiddenLayers.begin(), hiddenLayers.end());

	cout<<"Eta (0.15 is recommended) > ";
	cin>>myEta;
	cout<<"Alpha (0.5 is recommended) > ";
	cin>>myAlpha;
	//add in bounds checking for eta and alpha soon
	
	Net myNet(topology);
	myNet.train(trainingDataInput,trainingDataOutput);



	return 0;
	}
