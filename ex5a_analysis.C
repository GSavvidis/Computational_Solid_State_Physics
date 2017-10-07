#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <map>

#include "TCanvas.h"
#include "TH1F.h"
#include "TGraph.h"

	using namespace std;


	 		void ex5a_analysis(){

	 			// variable declaration
	 			double a,k;

	 			// map
	 			map<int,int> counts;

	 			// vector with number of connections
	 			vector<double> connections;
	 			vector<double> freq;
	 			vector<double> norm;
	 		
	 			// variable initialization
	 			double sum = 0;

	 			TH1F* h1 = new TH1F("Histogram","Histogram	 showing the distribution P(k) ",100,16000,17500);

	 		ifstream reader("data3b.txt");

	 		// read the data from the file and map the number of connections k
	 		do{

	 			reader >> a >> k ;
	 			counts[k]++;

	 			h1->Fill(k);


	 		}while(!reader.eof());

	 		// calculate the sum of the counts and save the number of connections k in a vector
	 		for( map<int,int> :: iterator it = counts.begin(), end= counts.end(); it!= end; ++it ) {

	 					sum+= it->second;
	 					freq.push_back(it->second);
	 					connections.push_back(it->first);


	 		}

	 		// normalization-relative frequency calculation 
	 		for ( vector<double> :: iterator it= freq.begin(), end= freq.end(); it!= end; ++it ){

	 					norm.push_back(*it/sum);

	 		}


	 		
	 		// Estimate the P(k) distribution
	 		gStyle->SetOptFit(11);
	 		c1 = new TCanvas("c1","c1",600,400);
	 		h1->SetXTitle("Number of connections k per node");
	 		h1->SetYTitle("Counts");
	 		h1->Fit("gaus");
	 		h1->Draw();

	 		// Plot P(k) vs k
	 		TGraph* gr1= new TGraph( norm.size(), &connections[0], &norm[0] );

	 		c2 = new TCanvas("c2","c2",600,400);
	 		gr1->SetLineColor(3);
	 		gr1->SetTitle("P(k) vs k");
	 		gr1->GetXaxis()->SetTitle("Number of connections k per node");
	 		gr1->GetYaxis()->SetTitle("Relative frequency");
	 		gr1->Draw("AC");


	 			// end
	 		}
