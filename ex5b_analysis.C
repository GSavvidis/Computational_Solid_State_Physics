#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <map>

#include "TCanvas.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TMath.h"


	using namespace std;


	 		void ex5b_analysis(){

	 			// variable declaration
	 			double a,k;

	 			// map
	 			map<int,int> counts1;
	 			map<int,int> counts2;
	 			map<int,int> counts3;

	 			// vector with number of connections
	 			vector<double> connections1;
	 			vector<double> connections2;
	 			vector<double> connections3;
	 			vector<double> freq1;
	 			vector<double> freq2;
	 			vector<double> freq3;
	 			vector<double> norm1;
	 			vector<double> norm2;
	 			vector<double> norm3;
	 		
	 			// variable initialization
	 			double sum = 0;


	 //			TH1F* h1 = new TH1F("Histogram","Histogram	 showing the distribution P(k) for gamma = 2",100,0.,100);
	 	//		TH1F* h2 = new TH1F("Histogram","Histogram	 showing the distribution P(k) for gamma = 2.5 ",100,0.,100);
	 	//		TH1F* h3 = new TH1F("Histogram","Histogram	 showing the distribution P(k) for gamma = 3 ",100,0.,100);

	 		ifstream reader1("gamma1.txt");
	 		ifstream reader2("gamma2.txt");
	 		ifstream reader3("gamma3.txt");

	 		// read the data from the file and map the number of connections k
	 		do{

	 			reader1 >> a >> k ;
	 			counts1[k]++;
	 	//		h1->Fill(k);

	 			reader2 >> a >> k ;
	 			counts2[k]++;
	 	//		h2->Fill(k)

	 			reader3 >> a >> k ;
	 			counts3[k]++;
	 	//		h3->Fill(k)


	 		}while(!reader3.eof());


	 		// gamma = 2 
	 		// calculate the sum of the counts and save the number of connections k in a vector
	 		for( map<int,int> :: iterator it = counts1.begin(), end= counts1.end(); it!= end; ++it ) {

	 					sum+= it->second;
	 					freq1.push_back(it->second);
	 					connections1.push_back(it->first);


	 		}

	 		// normalization-relative frequency calculation 
	 		for ( vector<double> :: iterator it= freq1.begin(), end= freq1.end(); it!= end; ++it ){

	 					norm1.push_back(*it/sum);

	 		}

	 		// gamma = 2.5
	 		// calculate the sum of the counts and save the number of connections k in a vector
	 		sum = 0;
	 		for( map<int,int> :: iterator it = counts2.begin(), end= counts2.end(); it!= end; ++it ) {

	 					sum+= it->second;
	 					freq2.push_back(it->second);
	 					connections2.push_back(it->first);


	 		}

	 		// normalization-relative frequency calculation 
	 		for ( vector<double> :: iterator it= freq2.begin(), end= freq2.end(); it!= end; ++it ){

	 					norm2.push_back(*it/sum);

	 		}

	 		// gamma = 3
	 		// calculate the sum of the counts and save the number of connections k in a vector
	 		sum = 0;
	 		for( map<int,int> :: iterator it = counts3.begin(), end= counts3.end(); it!= end; ++it ) {

	 					sum+= it->second;
	 					freq3.push_back(it->second);
	 					connections3.push_back(it->first);


	 		}

	 		// normalization-relative frequency calculation 
	 		for ( vector<double> :: iterator it= freq3.begin(), end= freq3.end(); it!= end; ++it ){

	 					norm3.push_back(*it/sum);

	 		}

	 		
	 		// Estimate the P(k) distribution
	// 		c1 = new TCanvas("c1","c1",600,400);
	// 		h1->SetXTitle("Number of connections");
	// 		h1->SetYTitle("Counts");
	 //		h1->Draw();

	 		// Plot P(k) vs k
	 		TMultiGraph* mg = new TMultiGraph();
	 		TGraph* gr1= new TGraph( norm1.size(), &connections1[0], &norm1[0] );
	 		TGraph* gr2= new TGraph( norm2.size(), &connections2[0], &norm2[0] );
	 		TGraph* gr3= new TGraph( norm3.size(), &connections3[0], &norm3[0] );

	 		// Fitting function
	 		TF1* f1 = new TF1("f1","TMath::Power(x,[2])");


	 		c1 = new TCanvas("c1","P(k) vs k ",600,400);
	 		c1->cd();
	 		c1->SetLogy();
	 		c1->SetLogx();
	 		gr1->SetLineColor(1);
	 		gr1->SetMarkerColor(2);	// red
	 		gr2->SetLineColor(2);
	 		gr2->SetMarkerColor(3);	// green
	 		gr3->SetLineColor(3);
	 		gr3->SetMarkerColor(4);	// blue
	 		mg->Add(gr1);
	 		mg->Add(gr2);
	 		mg->Add(gr3);
	 		mg->Draw("A*");
	 		mg->GetXaxis()->SetTitle("Number of connections k per node");
	 		mg->GetYaxis()->SetTitle("P(k)");
	 		mg->SetTitle("P(k) vs k for gamma =2, gamma =2.5, gamma =3" );  

	 		c2 = new TCanvas("c1","c1",600,400);
	 		c2->cd();
	 		c2->SetLogx();
	 		c2->SetLogy();
	 		gStyle->SetOptFit(11);
	 		gr1->SetMarkerStyle(2);
	 		gr1->SetTitle("P(k) vs k for #gamma = 2");
	 		gr1->GetXaxis()->SetTitle("Number of connections k per node");
	 		gr1->GetYaxis()->SetTitle("P(k)");
	 		gr1->Fit(f1,"","",0,10000);
	 		gr1->Draw("AC");



	 			// end
	 		}
