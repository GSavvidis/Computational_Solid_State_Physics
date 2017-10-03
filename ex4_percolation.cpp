#include <iostream>
#include <vector>
#include <stdlib.h>
#include <map>

using namespace std;


#define seed 4324

	int main(){

		srand(seed);

		// variable declaration
		double P,dp,rnd;
		
		

		// label vector L
		vector <int> L ;
		map<int,int> nl;
		// Size vector
		vector <int> S ;
		map <int,int> ns;

		// variable initialization
		int N = 300;
		int k = 1;
		int t=0 ;
		P = 0.8;
		dp = 0.6;

		// Lattice declaration
		vector <vector<int>> plegma(N, vector<int> (N,0));		

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



					cout << "L" << endl;
					for (vector<int> :: iterator it= L.begin(), end= L.end(); it!= end; ++it ) 
					{
					
						nl[*it]++; 					
											}
													
					for(map<int,int> :: iterator it= nl.begin(), end= nl.end(); it!=end; ++it)
					 {

					 	cout << "first= " << it->first << "\t" << "second= " << it->second << endl;

											}	


					cout << "S" << endl;
					for (vector<int> :: iterator it= S.begin(), end= S.end(); it!= end; ++it ) 
					{
					
						ns[*it]++; 					
											}
													
					for(map<int,int> :: iterator it= ns.begin(), end= ns.end(); it!=end; ++it)
					 {

					 	cout << "first= " << it->first << "\t" << "second= " << it->second << endl;

											}	



				return 0;

		}

