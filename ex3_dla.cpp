#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <fstream>

	#define seed 4324

	using namespace std;

		int main() {

			srand(seed);

			// variable declaration
			int N;
			int x,y;
			int i,j;
			int rnd;
			double sum;

			// variable initialization
			N = 300;

			double Xcenter = N/2.;
			double Ycenter = N/2.;
			int x_max = 3*N/4;
			int y_max = 3*N/4;
			int x_min = N/4; 
			int y_min = N/4;
			double R = N/4;
			int limit = pow(10,5);
			int counter = 0;
			int L = 0;	 // Length of the square side
			i = 1;

			// data output file
			ofstream myfile("dla_output.txt");
			ofstream myfile2("fractal_dimension.txt");

			// lattice 
			vector <vector<int>> plegma(N, vector<int>(N,0));

			// coodrinates
			vector <int> x_cor;
			vector <int> y_cor;

			// set trap at (N/2,N/2)
			plegma[(N-1)/2][(N-1)/2] = 1; 


			do {					
			x = 1.*rand()/RAND_MAX*3*N/4;
			y = 1.*rand()/RAND_MAX*3*N/4;

				// condition: every walker must begin from the circle's perifery
				 if ( x >= x_min && x <= x  && y >= y_min && y<= y_max ){			// if 1
				 	if( pow( x - Xcenter,2 ) + pow( y - Ycenter ,2 ) == pow(R,2) ) { 																																// if 2

				// begin of random walk
					do{

						rnd = rand()%4;

						// walk rightward
						if ( rnd == 0 ){
							x++;

								// check for trap 
								if ( plegma[x+1][y] == 1 || plegma[x][y+1] == 1 || plegma[x][y-1] == 1 ) {

										plegma[x][y] = 1;
										x_cor.push_back(x);
										y_cor.push_back(y);

								}

						}

						// walk leftward
						else if ( rnd == 1 ){
							 x--;
				
								// check for trap 
								if ( plegma[x-1][y] == 1 || plegma[x][y+1] == 1 || plegma[x][y-1] == 1 ) {

										plegma[x][y] = 1;
										x_cor.push_back(x);
										y_cor.push_back(y);

								}

						}

						// walk upward
						else if ( rnd == 2 ){
							y++;

								// check for trap 
								if ( plegma[x][y+1] == 1 || plegma[x+1][y] == 1 || plegma[x-1][y] == 1 ) {

										plegma[x][y] = 1;
										x_cor.push_back(x);
										y_cor.push_back(y);
								}


						}

						// walk downward
						else if ( rnd == 3 ){
							y--;

								// check for trap 
								if ( plegma[x][y-1] == 1 || plegma[x+1][y] == 1 || plegma[x-1][y] == 1 ) {

										plegma[x][y] = 1;
										x_cor.push_back(x);
										y_cor.push_back(y);
								}

						}

						// break condition
						if ( x < N/4 || x > 3*N/4 || y < N/4 || y > 3*N/4 ) 
							{ break; }


					}while( plegma[x][y] != 1 );

					i++;

				} // if 2
			}		// if 1

						}while( i != limit );

						for ( int k = 0; k < x_cor.size(); ++k ) {

							myfile << x_cor.at(k) << "\t" << y_cor.at(k) << endl;
						}


						// fractal dimension calculation
					for( int n = N/50; n<= R; n+= N/50 ){					// for 1
						for( int i = N/2-n ; i<= N/2+n; ++i ) {				// for 2
							for ( int j = N/2-n; j<= N/2+n; ++j){					// for 3

								if ( plegma[i][j] == 1 ){		

									sum+= 1;

								}

							}		// for 3

						}		// for 2

					L = 2*n;		// length of the square side
					counter++;
					myfile2 << sum << "\t" << L <<endl;
					sum = 0;
					L = 0;
					}    // for 1	



			return 0;

		}