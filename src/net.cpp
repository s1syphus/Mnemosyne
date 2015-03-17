
//net.cpp

#include "net.h"

Net::Net(vector<unsigned> topology){

	//default weights
	eta = 0.15;
	alpha = 0.5;		


	}

Net::Net(vector<unsigned> topology, double myEta, double myAlpha){

	setEta(myEta);
	setAlpha(myAlpha);
	}

void Net::setEta(double myEta){
	eta = myEta;
	}

void Net::setAlpha(double myAlpha){
	alpha = myAlpha;	
	}

void Net::feedForward(vector<double> &inputVals){


	}

void Net::backProp(vector<double> &targetVals){


	}














