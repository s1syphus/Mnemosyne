
//neuron.h

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
	};

class Neuron{

	public:
		Neuron(unsigned, double, double);
		~Neuron();		

		void feedForward(const Layer &prevLayer);	
		void setEta(double);
		void setAlpha(double);

	private:

		double eta;
		double alpha;	
		double activationFunction(double);
		double activationDerivative(double);	

	};


#endif


