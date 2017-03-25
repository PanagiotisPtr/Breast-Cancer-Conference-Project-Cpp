#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;

void loadIris(vector< vector<float> > &X, vector<int> &y)
{	
	srand(time(NULL));
	freopen("iris.train", "rt", stdin);
	X = vector< vector<float> >(100, vector<float>(4));
	y = vector<int>(100);
	vector< vector<float> > temp(100, vector<float>(5));
	for(int i = 0; i < 100; i++)for(int j = 0; j < 5; j++)cin >> temp[i][j];	
	random_shuffle(temp.begin(), temp.end());
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 4; j++)X[i][j] = temp[i][j];
		y[i] = temp[i][4];
	}
}

void loadBC(vector< vector<float> > &X, vector<int> &y,vector< vector<float> > &test_X, vector<int> &test_y)
{
	srand(time(NULL));
	freopen("BC.train", "rt", stdin);
	X = vector< vector<float> >(400, vector<float>(9));
	y = vector<int>(400);
	vector< vector<float> > temp;

	for(int i = 0; i < 699; i++)
	{
		temp.push_back(vector<float>());
		for(int j = 0; j < 11; j++)
		{
			int a;
			cin >> a;
			temp.back().push_back(a);
		}
		if(temp.back().back()==4)temp.back().back() = 1;
		if(temp.back().back()==2)temp.back().back() = -1;
	}

	for(int i = 0; i < 699; i++)temp[i].erase(temp[i].begin()); //Deletes the patiets ID info since it is not needed

	random_shuffle(temp.begin(), temp.end());

	for(int i = 0; i < 400; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			X[i][j] = temp[i][j];
			//cout << X[i][j] << " ";
		}
		y[i] = temp[i][9];
		//cout << y[i] << endl;
	}

	test_X = vector< vector<float> >(299, vector<float>(9));
	test_y = vector<int>(299);

	for(int i = 0; i < 299; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			test_X[i][j] = temp[i+400][j];
			//cout << X[i][j] << " ";
		}
		test_y[i] = temp[i+400][9];
		//cout << y[i] << endl;
	}
}