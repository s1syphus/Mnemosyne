
//neural.h: header for all the neural network types that will be included
//Multi-layer Peceptron
//Convolution Neural Network

#ifndef __NEURAL_H_INCLUDED__
#define __NEURAL_H_INCLUDED__

using namespace std;

//sigmoid and the derivative of the sigmoid
//this is the non-lineararity

#define SIGMOID(x) (1.7159*tanh(0.66666667*x))
#define DSIGMOID(S) (0.66666667/1.7159*(1.7159+(S))*(1.7159-(S)))

//Multi-layer Peceptron (MLP) Network

class MLP{
	public:
		MLP();
		virtual ~MLP();
		void Initialize();
		void Train();
		void Test();

	}


