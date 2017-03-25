#include <iostream>
#include <vector>
#include <cstdio>
#include <time.h>
#include <algorithm>
#include <math.h>
#include "Adaline.h"
#include "datasets.h"

using namespace std;

int main()
{
	Adaline model(0.001, 10000);
	vector< vector<float> > X;
	vector<int> y;
	vector< vector<float> > test_X;
	vector<int> test_y;

	loadBC(X,y,test_X,test_y);
	cout << "Train Size: " << X.size() << "\tTest Size: " << test_X.size() << '\n';
	model.train(X,y);
	
	model.test(test_X,test_y);
	return 0;
}