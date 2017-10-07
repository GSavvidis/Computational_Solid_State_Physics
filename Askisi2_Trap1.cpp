#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <stdlib.h>
#include <iterator>



#define seed 4324
 
using namespace std;

#ifdef seed

int main() {

int k; 			// ID of the walker
int t;			// steps
double N_particles,relative_prob;
double i,j;
double c,zz;
double sum;

// create files
ofstream hist("hist_trapping1.txt");
ofstream pdf("pdf_trapping1.txt");

// Map definition for counting steps
map <int, int> m_counter;

// Initialization

N_particles = pow(10,5); 			// Total number of free particles for this run

vector <vector <int>> plegma (1000, vector<int> (1000,0));		// Lattice definition

c = 0.1;			// Trap density

k = 1;
t  = 0;

srand (seed);

// Fill the lattice with traps in random locations
for ( i=0; i < plegma.size() ; i++ ) {
	for ( j=0; j < plegma.size() ; j++ ) {

	zz= 1.*rand()/RAND_MAX;	
	if ( zz <= c ) {
		plegma[i][j] = 1;
		}

	}

}

// Particle spawn
while ( k <= N_particles ) {
 
	// Start from a random location in the lattice
	i = ( 1.*rand()/RAND_MAX )*plegma.size();
	j = ( 1.*rand()/RAND_MAX )*plegma.size();


	// If you fall into a trap, map the time the particle survived and continue to the next particle
	if ( plegma[i][j] == 1 ) {

	hist << t  << endl; 
	m_counter[t]++;
	k++;	
	t = 0;
		continue;
	}

do{

	// Beginning of the walk
	zz = 1.*rand()/RAND_MAX;
	
	// Move upward
	if ( zz < 0.25 ) {
		i++;	
			if ( i > plegma.size()-1 ) { i = i - plegma.size() ; }	 // If you reach the one edge of the lattice, go to the other one
		}																											 // plegma.size() = 1000
	
	// Move downward
	else if ( zz < 0.5 ) {
			i--;
			if ( i < 0 ) {	 i = i + plegma.size() ; }	// If you reach the one edge of the lattice, go to the other one	
		}

	// Move left
	else if ( zz < 0.75 ) {	
		j++;
			if ( j > plegma.size() - 1 ) { j = j - plegma.size() ; }	 // If you reach the one edge of the lattice, go to the other one
		}		

	// Move right
	else {	
		 j--;
			if ( j < 0 ) { j = j + plegma.size() ; }	 // If you reach the one edge of the lattice, move to the other one
	}



	// If you fall into a trap, map the time the particle survived and continue to the next particle
	if ( plegma[i][j] == 1 ) {

	hist << t  << endl; 
	m_counter[t]++;
//	my_file << m_counter[k] << endl;
	k++;
	t = 0;
			}

// Increase the time the particle survived by 1.		
	t+=1 ;

		}while(plegma[i][j] != 1);		// do 
	}		// while
				
sum = 0;
// calculate the sum of all steps
for ( map<int,int> :: iterator itr = m_counter.begin(), end = m_counter.end(); itr!=end; ++itr ) {


	sum = sum + itr->second ;

	}

map <double,double> probability_density_function;

// divide each count with their sum = relative probability
for ( map<int,int> :: iterator itr = m_counter.begin(), end = m_counter.end(); itr!=end; ++itr ) {

 probability_density_function[itr->first] = itr->second/sum;

	}

// store each count with the corresponding probability
for ( map<double,double> :: iterator it = probability_density_function.begin(), end2 = probability_density_function.end(); it!=end2; ++it ) {
	
	pdf << it->first << "\t" << it->second << endl;

}


	return 0;
}

#endif
