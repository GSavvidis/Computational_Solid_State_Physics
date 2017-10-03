#include <iostream>
#include <vector>
#include <stdlib.h>
#include <map>
#include <cmath>
#include <ctime>

#include "TCanvas.h"
#include "TGraph.h"


using namespace std;


#define seed 4324

	void Final(){

	//	srand(seed);
		srand(time(NULL));

		// variable declaration
		double P,rnd;
		int Y;


		// label vector L
		vector <int> L ;
		map<int,int> nl;

		// Size vector
		vector <int> S ;
		map <int,int> ns;

		// Vector with the average cluster size
		vector <double> Iav;

		// Vector with the average cluster size; biggest cluster not included
		vector <double> IIav; 

		// Vector of probabilities
		vector<double> prob;

		// variable initialization
		Y = 10; 			// realizations
		int N = 200;
		int k = 1;
		P = 0.8;
		double l_boundary = 0.5;
		double u_boundary = 0.6;
	//	double dp = 0.1;

				

		for ( double dp = 0.1 ; dp <= P; dp >= l_boundary && dp <= u_boundary ? dp+= 0.01 : dp += 0.1 ) {		// first for
			
			double s_sum = 0.; 
			double ss_sum = 0.;
			prob.push_back(dp);

			for ( int y = 1 ; y <= Y; ++y ){													// realization loop

		// Lattice declaration
		vector <vector<int>> plegma(N, vector<int> (N,0));

  		// Latice variables
		double sum = 0.;
	

		//lattice construction
		for (int i = 0; i < N ; ++i){
	//		cout << endl;
			for (int j = 0 ; j < N; ++j){

				 rnd = 1.*rand()/RAND_MAX;
				if (rnd <= dp) { plegma[i][j] = 1; }
	//			cout << plegma[i][j] << "\t";

					}
//				cout << endl;
				}

		// check the rest of the lattice
			for ( int j = 0; j<N; ++j ) {					// FOR1
				for ( int i = 0; i<N; ++i ){				// FOR2
			
//							 cout << "i= " << i << endl;
//						    cout << "j= " << j << endl;

				
				if ( plegma[i][j] !=0 ) {  								// IF1

					//scan the first column
					if ( i > 0 && j == 0 ) { 		
						if ( plegma[i-1][j] == 0 ) {

							L.push_back(1);
							S.push_back(0);
							L.at( k-1 ) = k;
							plegma[i][j] = L.at( k-1 );
							S.at( L.at( plegma[i][j] -1 ) -1 ) += 1;
							k++;

						}

						else if ( plegma[i-1][j] != 0 ){

							plegma[i][j] = L.at( plegma[i-1][j] -1 );
							S.at( L.at( plegma[i][j] -1 ) -1 ) += 1;

						}

					} // end of scan
				  
					
					else if ( i == 0 && j == 0 ){
						
							L.push_back(1);
							S.push_back(0);
							L.at( k-1 ) = k;
							plegma[i][j] = L.at( k-1 );
							S.at( L.at( plegma[i][j] -1 ) -1 ) += 1;
							k++;

					} // 1st column finished 
				
					
					if ( i == 0 && j > 0 ) { 		

						if ( plegma[i][j-1] != 0 ) {
						
						plegma[i][j] = L.at( plegma[i][j-1] -1 );
						S.at( L.at( plegma[i][j] -1 ) -1 ) ++;

							}

						else if( plegma[i][j-1] == 0 ){

							L.push_back(1);
							S.push_back(0);
							L.at( k-1 ) = k;
							plegma[i][j] = L.at( k-1 );
							S.at( L.at( plegma[i][j] -1 ) -1 ) ++;
							k++;

							}	
					
						}

					// core
					if ( i > 0 && j > 0 ) {

						if ( plegma[i][j-1] == 0 && plegma[i-1][j] == 0) {

							L.push_back(1);
							S.push_back(0);
							L.at( k-1 ) = k;
							plegma[i][j] = L.at( k-1 );
							S.at( L.at( plegma[i][j] -1 ) -1 )++;
							k++;	

						}

					 else if ( plegma[i][j-1] == 0 && plegma[i-1][j] != 0 ) {

							plegma[i][j] = L.at( plegma[i-1][j] -1 );
							S.at( L.at( plegma[i][j] -1 ) -1 )++;

								}	

					 else if ( plegma[i][j-1] != 0 ) {				// edw

						plegma[i][j] = L.at( plegma[i][j-1] -1 );
						S.at( L.at( plegma[i][j] -1 ) -1 )++;


						if ( plegma[i-1][j] != 0 ) {

								if (  L.at( plegma[i-1][j] -1 ) != L.at( plegma[i][j-1] -1 ) ){

									S.at( L.at( plegma[i][j-1] -1 ) -1) += S.at(  plegma[i-1][j] -1 );
									S.at( L.at( plegma[i-1][j] -1 ) -1 ) = 0;
										
										for( int a =0; a < L.size(); ++a ) {
								
										if( L.at(a) == L.at( plegma[i-1][j] -1 )  ) {
											L.at(a) = L.at( plegma[i][j-1] -1);
													
														}
												}
									
								}				
							

								}			

					} 	// edw

				}													

			}		// IF1


					}		// FOR2
				

				}		//FOR1			



				// map the values of S
					for (vector<int> :: iterator it= S.begin(), end= S.end(); it!= end; ++it ) 
					{
					
						ns[*it]++; 					
											}
													
				// Caclulate the average cluster size Iav
									
				for (map<int,int> :: iterator it = ns.begin() , end= ns.end(); it!= end; ++it) {

						sum += (it->second)*pow(it->first ,2)/(dp*pow(N,2));

				}	

					s_sum += sum;

			// Calculate IIav
					map<int,int> :: iterator itr = ns.end();
					ss_sum = s_sum - itr->first/(dp*pow(N,2));


				}	// end of realization loop
				cout << "end of realization " << endl;
				Iav.push_back( s_sum/Y );
				IIav.push_back( ss_sum/Y );

			} // first for						
	
			TGraph* gr1 = new TGraph(Iav.size(),&prob[0],&Iav[0] );
			c1 = new TCanvas("c1","c1",600,400);
			c1 ->cd();
			gr1 ->Draw("A*");

			TGraph* gr2 = new TGraph(IIav.size(),&prob[0],&IIav[0] );
			c2 = new TCanvas("c2","c2",600,400);
			c2 ->cd();
			gr2->Draw("A*");

		}

