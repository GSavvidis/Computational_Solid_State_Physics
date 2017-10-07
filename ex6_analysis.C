#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

#include "TCanvas.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TLegend.h"


	using namespace std;

		void ex6_analysis(){

			vector<double> relative_distance;
			vector<double> point1_position;
			vector<double> point2_position;
			vector<double> point1_velocity;
			vector<double> point2_velocity;
			vector<double> point1_x;
			vector<double> point1_y;
			vector<double> point2_x;
			vector<double> point2_y;
			vector<double> time;
			vector<double> K;
			vector<double> V;
			vector<double> E;


			ifstream read_file("data1.txt");

			double a,b,c,d,e,f,g,h,i,j,k,l,m;


			
			do{

			read_file >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l >> m;
				
			relative_distance.push_back(a);	
			point1_position.push_back(b);
			point2_position.push_back(c);
			point1_velocity.push_back(d);
			point2_velocity.push_back(e);
			point1_x.push_back(f);
			point1_y.push_back(g);
			point2_x.push_back(h);
			point2_y.push_back(i);
			time.push_back(j);	
			K.push_back(k);
			V.push_back(l);
			E.push_back(m); 
				
		}while( !read_file.eof() );

 
			TGraph* gr1= new TGraph(time.size(),&time[0],&relative_distance[0]);
			TGraph* gr2= new TGraph(time.size(),&time[0],&point1_position[0]);
			TGraph* gr3= new TGraph(time.size(),&time[0],&point2_position[0]);
			TGraph* gr4= new TGraph(time.size(),&time[0],&point1_velocity[0]);
			TGraph* gr5= new TGraph(time.size(),&time[0],&point2_velocity[0]);
			TGraph* gr6= new TGraph(time.size(),&point1_x[0],&point1_y[0]);
			TGraph* gr7= new TGraph(time.size(),&point2_x[0],&point2_y[0]);
			TGraph* gr8 = new TGraph(time.size(),&time[0],&K[0]);
			TGraph* gr9 = new TGraph(time.size(),&time[0],&V[0]);
			TGraph* gr10 = new TGraph(time.size(),&time[0],&E[0]);
			TMultiGraph* mg1 = new TMultiGraph();
			TMultiGraph* mg2 = new TMultiGraph();

			c1 = new TCanvas("c1","relative_distance",600,400);
			c1->cd();
			gr1->SetTitle("Relative distance of the two particles vs time");
			gr1->GetXaxis()->SetTitle("Time");
			gr1->GetYaxis()->SetTitle("Relative distance");
			gr1->Draw();

			c2 = new TCanvas("c2","point1_position",600,400);
			c2->cd();
			gr2->SetTitle("Position of particle1 vs time");
			gr2->GetXaxis()->SetTitle("Time");
			gr2->GetYaxis()->SetTitle("Position");
			gr2->Draw();

			c3 = new TCanvas("c3","point2_position",600,400);
			c3->cd();
			gr3->SetTitle("Position of particle2 vs time");
			gr3->GetXaxis()->SetTitle("Time");
			gr3->GetYaxis()->SetTitle("Position");
			gr3->Draw();

			c4 = new TCanvas("c4","point1_velocity",600,400);
			c4->cd();
			gr4->SetTitle("Velocity of particle1 vs time");
			gr4->GetXaxis()->SetTitle("Time");
			gr4->GetYaxis()->SetTitle("Velocity");
			gr4->Draw();

			c5 = new TCanvas("c5","point2_velocity",600,400);
			c5->cd();
			gr5->SetTitle("Velocity of particle2 vs time");
			gr5->GetXaxis()->SetTitle("Time");
			gr5->GetYaxis()->SetTitle("Velocity");
			gr5->Draw();

			// orbit of the two particles
			c6 = new TCanvas("c6","Orbit",600,400);
			c6->cd();
			gr6->SetLineColor(2);
			gr7->SetLineColor(3);
			mg1->Add(gr6);
			mg1->Add(gr7);
			mg1->Draw("AC");
			mg1->GetXaxis()->SetTitle("X");
			mg1->GetYaxis()->SetTitle("Y");
			mg1->SetTitle("Orbit of the two particles");

			c7 = new TCanvas("c7", "Kinetic and Potential energy", 600,400);
			c7->cd();
			gr8->SetMarkerColor(2);		// red Kinetic energy
			gr8->SetLineColor(2);
			gr9->SetMarkerColor(3);		// green Potential energy
			gr9->SetLineColor(3);
			gr10->SetMarkerColor(4);
			gr10->SetLineColor(4);
			mg2->Add(gr8);
			mg2->Add(gr9);
			mg2->Add(gr10);
			mg2->Draw("AC");
			mg2->GetXaxis()->SetTitle("Time t ");
			mg2->GetYaxis()->SetTitle("Total-Kinetic-Potential energy");
			mg2->SetTitle("Energy vs time");

			// end
		}