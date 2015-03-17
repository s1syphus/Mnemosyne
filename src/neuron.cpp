
//neuron.cpp

#include "neuron.h"

Neuron::Neuron(unsigned){



	}

Neuron::~Neuron(){


	}

void Neuron::feedFoward(const Layer &prevLayer){
	double sum = 0.0;
	for(unsigned n = 0; n < prevLayer.size(); n++){
		sum += 	prevLayer[n].getOutput() * 
			prevLayer.m_ouptuWeights[myIndex].weight;
		}
	outputVal = activationFunction(sum);
	}

void Neuron::setEta(double myEta){
	eta = myEta;
	}

void Neuron::setAlpha(double myAlpha){
	alpha = myAlpha;
	}

double Neuron::activationFunction(double x){
	return tanh(x);
	}

double Neuron::activationDerivative(double x){
	return 1.0 - x*x;
	}


