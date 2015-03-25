
//net.h

#ifndef NET_H
#define NET_H

#include "neuron.h"
#include "data.h"
#include <vector>
#include <cassert>

using namespace std;

class Net{

	public:
		Net(vector<unsigned>);
		Net(vector<unsigned>,double, double);

		//this will reset the eta and alpha for every 
		//neuron in the net
		void setEta(double);
		void setAlpha(double);
		double getEta();
		double getAlpha();



		void feedForward(vector<double> &);
		void backProp(vector<double> &);
		void getResults(vector<double> &);


		void train(Data);
		void test(Data);
	
		double getRecentAverageError();

		void parameterSweep(Data, double, double, double, 
				double, double);

	private:

		//these functions will end up here but 
		//are currently commented out so program compiles
//		void feedForward(vector<double> &);
//		void backProp(vector<double> &);
//		void getResults(vector<double> &);



		vector<Layer> m_layers;	
		double m_error;
		double m_recentAverageSmoothing;
		double m_recentAverageError;

		//these values are for the neurons that make up the net
		//these values themselves just hold the data for bookkeeping 
		//purposes
		double m_alpha;
		double m_eta;
	};


#endif
