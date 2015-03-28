
//net.cpp

#include "net.h"

void Net::train(vector<vector<double> > &input,
		vector<vector<double> > &output){
	assert(input.size() == output.size());
	for(unsigned i = 0; i < input.size(); i++){
		feedForward(input[i]);
		backProp(output[i]);
		}
	}


void Net::test(	vector<vector<double> > &input,
		vector<vector<double> > &output, double &error){
	assert(input.size() == output.size());
	vector<double> tempOut;
	error = 0.0;
	for(unsigned i = 0; i < (input.size() - 1); i++){
		feedForward(input[i]);
		getResults(tempOut);
		cout<<"is: "<<tempOut[0]<<" should be: "<<output[i][0]<<endl;

//		error += rms(tempOut,output[i]);
		if((tempOut[0] - output[i][0]) > 1){
			cout<<"mislabelled, is: "<<tempOut[0]<<" should be: "<<output[i][0]<<endl;
			error++;	
			}
		}

	error /= (double) input.size();
	}

double Net::rms(vector<double> &one, vector<double> &two){
	assert(one.size() == two.size());
	double delta;
	double error = 0.0;
	for(unsigned i = 0; i < one.size(); i++){
		delta = one[i] - two[i];
		error += delta * delta;
		}
	return sqrt(error / (double) one.size());
	}

void Net::saveWeights(string filename){
	//stub



	}

void Net::loadWeights(string filename){
	//stub
	}

Net::Net(vector<unsigned> topology){

	//default weights
	m_eta = 0.15;
	m_alpha = 0.5;		
	m_recentAverageSmoothing = 100.0;
	m_recentAverageError = 0.0;

	for(unsigned layerNum = 0; layerNum < topology.size(); layerNum++){
		m_layers.push_back(Layer());
		unsigned numOutputs = (layerNum == (topology.size() -1)) ? 
				0 : topology[layerNum + 1];
		for(unsigned nn = 0; nn <= topology[layerNum]; nn++){
			m_layers.back().push_back(Neuron(numOutputs, nn, m_eta, m_alpha));
			}
		//bias node
		m_layers.back().back().setOutputVal(1.0);
		}		
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

	Layer &outputLayer = m_layers.back();	
	m_error = 0.0;

	for(unsigned n = 0; n < outputLayer.size(); n++){
		double delta = targetVals[n] - outputLayer[n].getOutputVal();
		m_error += delta * delta;
		}	
	m_error = sqrt(m_error/(outputLayer.size() - 1)); //RMS

	m_recentAverageError = 
			(m_recentAverageError * m_recentAverageSmoothing + 
			 m_error) / (m_recentAverageSmoothing + 1.0);

	for(unsigned n = 0; n < outputLayer.size() - 1; n++){
		outputLayer[n].calcOutputGradients(targetVals[n]);
		}
	
	for(unsigned layerNum = m_layers.size() - 2; layerNum > 0; layerNum--){
		Layer &hiddenLayer = m_layers[layerNum];
		Layer &nextLayer = m_layers[layerNum + 1];
		for(unsigned n = 0; n < hiddenLayer.size(); n++){
			hiddenLayer[n].calcHiddenGradients(nextLayer);
			}
		}

	for(unsigned layerNum = m_layers.size() - 1; layerNum > 0; layerNum--){
		Layer &layer = m_layers[layerNum];
		Layer &prevLayer = m_layers[layerNum - 1];
		for(unsigned n = 0; n < layer.size(); n++){
			layer[n].updateInputWeights(prevLayer);
			}
		}
	}

void Net::feedForward(vector<double> &inputVals){
	for(unsigned i = 0; i < inputVals.size(); i++){
		m_layers[0][i].setOutputVal(inputVals[i]);
		}

	for(unsigned layerNum = 1; layerNum < m_layers.size(); layerNum++){
		Layer &prevLayer = m_layers[layerNum - 1];
		for(unsigned n = 0; n < m_layers[layerNum].size() - 1; n++){
			m_layers[layerNum][n].feedForward(prevLayer);
			}
		}
	}

void Net::setEta(double myEta){
	//change this soon to update to every neuron in the net
	//not a priority though
	m_eta = myEta;
	}

void Net::setAlpha(double myAlpha){
	//change this soon to update to every neuron in the net
	//not a priority
	m_alpha = myAlpha;	
	}

double Net::getEta(){
	return m_eta;
	}

double Net::getAlpha(){
	return m_alpha;
	}


