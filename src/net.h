
//net.h

//make this more parallel after working


#ifndef NET_H
#define NET_H

#include "neuron.h"
#include <vector>

using namespace std;

class Net{

	public:
		Net(vector<unsigned>);
		Net(vector<unsigned>,double, double);
		void setEta(double);
		void setAlpha(double);

		void feedForward(vector<double> &);
		void backProp(vector<double> &);


	private:
		vector<Layer> myLayers;	
		double error;
		double alpha;
		double eta;
	};


#endif
