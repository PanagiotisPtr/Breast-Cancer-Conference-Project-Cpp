#include <iostream>
#include <vector>
#include <cstdio>
#include <time.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Adaline
{
public:
	Adaline(float h, int e);
	void train(vector< vector<float> > const &X, vector<int> const &y);
	int predict(vector<float> const &X);
	void test(vector< vector<float> > const &X, vector<int> const &y);
private:
	float netInput(vector<float> const &X);
	float tanh_prime(float x);
	float bias = 1;
	vector<float> m_w;
	float eta;
	float epochs;
};

Adaline::Adaline(float h, int e)
{
	eta = (float)h;
	epochs = (int)e;
}

void Adaline::train(vector< vector<float> > const &X, vector<int> const &y)
{
	m_w = vector<float>(X[0].size());
	vector<int> m_err;
	cout << "Started Training" << endl;
	for(int i = 0; i < epochs; i++)
	{
		int errors = 0;
		for(int j = 0; j < X.size(); j++)
		{
			float netIn = netInput(X[j]);
			int pred = netIn >= 0 ? 1 : -1;
			float update = eta * (y[j] - netIn) * tanh_prime(netIn);
			//m_w += X[j] * update;
			for(int q = 0; q < m_w.size(); q++)m_w[q]+=X[j][q]*update;
			bias += update;
			errors += y[j]==pred ? 0 : 1;
		}
		float accuracyOnEpoch = (float)(X.size()-errors)/X.size();
		if(errors < 10)break;
		printf("Errors at Epoch %d: %d", i+1, errors);
		printf("\t Accuracy: %0.2f\n", accuracyOnEpoch);
		m_err.push_back(errors);
	}
}

void Adaline::test(vector< vector<float> > const &X, vector<int> const &y)
{
	int error = 0;
	for(int i = 0; i < X.size(); i++)
	{
		int ans = predict(X[i]);
		if(ans!=y[i])error++;
	}
	cout << "Accuracy on Test: " << (float)(299-error)/299 << endl;
}

float Adaline::netInput(vector<float> const &X)
{
	float sum = bias;
	for(int i = 0; i < X.size(); i++){
		sum += m_w[i]*X[i];
	}
	return tanh(sum);
	//return dotProduct(m_w,X) + bias;
}

int Adaline::predict(vector<float> const &X)
{
	return netInput(X)>=0 ? 1 : -1;
}

float Adaline::tanh_prime(float x){
	return 1.0 - x * x;
}