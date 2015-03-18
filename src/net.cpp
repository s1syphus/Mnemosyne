
//net.cpp

#include "net.h"

Net::Net(vector<unsigned> topology){

	//THIS IS NOT DONE!!!!!!!!

	//default weights
	m_eta = 0.15;
	m_alpha = 0.5;		

	unsigned numOutputs;
	for(unsigned layerNum = 0; layerNum < topology.size(); layerNum++){
		m_layers.push_back(Layer());

		}		



	}

Net::Net(vector<unsigned> topology, double myEta, double myAlpha){
	setEta(myEta);
	setAlpha(myAlpha);
	}

double Net::getRecentAverageError(){
	return m_recentAverageError;
	}

void Net::getResults(vector<double> &resultVals){
	resultVals.clear();
	for(unsigned n = 0; n < m_layers.back().size() - 1; n++){
		resultVals.push_back(m_layers.back()[n].getOutputVal());
		}
	}

void Net::backProp(vector<double> &targetVals){
	//meh

	}

void Net::setEta(double myEta){
	//change this soon to update to every neuron in the net
	eta = myEta;
	}

void Net::setAlpha(double myAlpha){
	//change this soon to update to every neuron in the net
	alpha = myAlpha;	
	}

double Net::getEta(){
	return m_Eta;
	}

double Net::getAlpha(){
	return m_Alpha;
	}

void Net::feedForward(vector<double> &inputVals){


	}

void Net::backProp(vector<double> &targetVals){


	}














