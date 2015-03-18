
//neuron.h

//once this is working, optimize for speed,
//parallel, const, etc

#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

class Neuron;

typedef vector<Neuron> Layer;

struct Connection{
	double weight;
	double deltaWeight;
	Connection(double myWeight):weight(myWeight){}
	};

class Neuron{

	public:
		Neuron(unsigned, unsigned, double, double);
		~Neuron();	//this needs to be finished at some point

		void feedForward(const Layer &prevLayer);	

	private:

		double m_eta;
		double m_alpha;
		unsigned m_index;
		double m_outputVal;
		double m_gradient;
		vector<Connection> m_outputWeights;

		double activationFunction(double);
		double activationDerivative(double);	
		double randomWeight();
		double sumError(Layer&);
		void calcHiddenGradients(Layer&);
		void calcOutputGradients(double);
		void updateInputWeights(Layer&);
		double getOutputVal();
	};


#endif


