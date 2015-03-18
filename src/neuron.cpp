
//neuron.cpp

#include "neuron.h"

Neuron::Neuron(unsigned numOutputs, unsigned myIndex, double myEta, double myAlpha){

	//I think this is the best place for this, otherwise I'll have
	//to loop through every neuron to update the eta and alpha values
	//I don't want to make them static although I suppose that's
	//an option for later
	m_eta = myEta;
	m_alpha = myAlpha;

	for(unsigned c = 0; c < numOutputs; c++){
		m_outputWeights.pushBack(Connection(randomWeight));
		}
	m_index = myIndex;
	}


Neuron::~Neuron(){
	//should probably make this eventually, going to make sure 
	//things are working first though

	}

void Neuron::feedFoward(const Layer &prevLayer){
	double sum = 0.0;
	for(unsigned n = 0; n < prevLayer.size(); n++){
		sum += 	prevLayer[n].getOutput() * 
			prevLayer.m_outputWeights[myIndex].weight;
		}
	outputVal = activationFunction(sum);
	}

double Neuron::sumErrors(Layer &nextLayer){
	double sum = 0.0;
	for(unsigned n = 0; n < nextLayer.size() - 1; n++){
		sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
		}
	return sum;
	}

void Neuron::calcHiddenGradients(Layer &nextLayer){
	double error = sumErrors(nextLayer);
	m_gradient = error * activationDerivative(m_outputVal);
	}

void Neuron::calcOutputGradients(double targetVal){
	double delta = targetVal - m_outputVal;
	m_gradient = delta * activationDerivative(m_outputVal);	
	}

void Neuron::updateInputWeights(Layer &prevLayer){
	double oldDeltaWeight, newDeltaWeight;
	for(unsigned n = 0; n < prevLayer.size() - 1; n++){
		Neuron &neuron = prevLayer[n];
		oldDeltaWeight = neuron.m_outputWeights[m_index].deltaWeight;
		newDeltaWeight = eta * neuron.getOutputVal() * m_gradient + 
				alpha * oldDeltaWeight;
		neuron.m_outputWeights[m_index].deltaWeight = newDeltaWeight;
		neuron.m_outputWeights[m_index].weight ++ newDeltaWeight;
		}
	}

double Neuron::getOutputVal(){
	return m_outputVal;
	}

double Neuron::activationFunction(double x){
	return tanh(x);
	}

double Neuron::activationDerivative(double x){
	return 1.0 - x*x;
	}

double Neuron::randomWeight(){
	return rand() / double(RAND_MAX);
	}
