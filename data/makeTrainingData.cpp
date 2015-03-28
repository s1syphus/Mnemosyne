#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
	//2 inputs, 1 layer of 4 hidden neurons, 1 output
	cout<<"2 4 1"<<endl;

	int numSamples = 2000;
	for(int i = 0; i < numSamples; i++){
		int n1 = (int) (2.0*rand() / double(RAND_MAX));
		int n2 = (int) (2.0*rand() / double(RAND_MAX));
		int t = n1^n2;
		cout<<n1<<".0 "<<n2<<".0 "<<t<<".0"<<endl;
		}
	return 0;
	}
