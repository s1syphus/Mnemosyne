
//net.h

#ifndef NET_H
#define NET_H

#include "neuron.h"
#include "data.h"
#include <vector>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Net{

	public:
		Net(vector<unsigned>);
		Net(vector<unsigned>,double, double);

		void setEta(double);
		void setAlpha(double);
		double getEta();
		double getAlpha();

		void feedForward(vector<double> &);
		void backProp(vector<double> &);
		void getResults(vector<double> &);

		void train(	vector<vector<double> > &, 
				vector<vector<double> > &);

		void test(	vector<vector<double> > &, 
				vector<vector<double> > &,
			       	double &);

		void saveWeights(string);
		void loadWeights(string);

		double getRecentAverageError();

	private:

		vector<Layer> m_layers;	
		double m_error;
		double m_recentAverageSmoothing;
		double m_recentAverageError;

		//these values are for the neurons that make up the net
		//these values themselves just hold the data for bookkeeping 
		//purposes
		double m_alpha;
		double m_eta;

		double rms(vector<double> &, vector<double> &);
	};


#endif
