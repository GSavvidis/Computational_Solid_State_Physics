#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector> 
#include <cmath> 

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	// files with data generated
	ofstream file1("gamma1.txt");
	ofstream file2("gamma2.txt");
	ofstream file3("gamma3.txt");


	// variable declaration
	double Pk, Ps;
	double rnd;
	double x,y;
	int k,i;
	double x_max;

	// variable initialization
	int N = 100000;
	int node_num1[100000] = {0};
	int node_num2[100000] = {0};
	int node_num3[100000] = {0};

	double gamma1 = 2.;
	double gamma2 = 2.5;
	double gamma3 = 3;
	
	
	i = 0;
	x_max = (pow(N, 1-gamma1) - 1)/(1 - gamma1);

	// gamma = 2
	while(i<N){
		
				rnd = 1.*rand()/RAND_MAX;
			if ( rnd <= x_max){
				k = int(pow(rnd*(1-gamma1) +1, 1./(1-gamma1)));
				node_num1[i] = k;
				}

		i++;
	}

	// printing loop
		for (int i = 0; i < N; ++i)
	{
	
		file1 << i << "\t" << node_num1[i] << endl;
	}
	
	// gamma = 2.5
	 x_max = (pow(N, 1-gamma2) - 1)/(1 - gamma2);
	 i = 0;
	 k =0;
		while(i<N){
		
				rnd = 1.*rand()/RAND_MAX;
			if ( rnd <= x_max){
				k = int(pow(rnd*(1-gamma2) +1, 1./(1-gamma2)));
				node_num2[i] = k;
				}
	 
		i++;
	}

		// printing loop
			for (int i = 0; i < N; ++i)
	{
	
		file2 << i << "\t" << node_num2[i] << endl;
	}


	// gamma = 3
	x_max = (pow(N, 1- gamma3) - 1)/(1 - gamma3);
	 i = 0;
	 k=0;
		while(i<N){
		
			rnd = 1.*rand()/RAND_MAX;
			if ( rnd <= x_max){
				k = int(pow(rnd*(1-gamma3) +1, 1./(1-gamma3)));
				node_num3[i] = k;
				}

		i++;
	}

	// printing loop
			for (int i = 0; i < N; ++i)
	{
	
		file3 << i << "\t" << node_num3[i] << endl;
	}



	return 0;

}
