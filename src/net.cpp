
//net.cpp

#include "net.h"

Net::Net(vector<unsigned> topology){

	//default weights
	m_eta = 0.15;
	m_alpha = 0.5;		

	unsigned numOutputs;
	for(unsigned layerNum = 0; layerNum < topology.size(); layerNum++){
		m_layers.push_back(Layer());
		numOutputs = (layerNum == (topology.size() -1) ? 
				0 : topology[layerNum + 1];
		for(unsigned nn = 0; neuronNum <= topology[layerNum]; nn++){
			m_layers.back().push_back(Neuron(numOutputs, nn));
			}
		//bias node
		m_layers.back().setOutputVal(1.0);
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














