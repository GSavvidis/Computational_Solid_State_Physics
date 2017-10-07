#include <iostream>
#include <vector>
#include <fstream>

#include "TCanvas.h"
#include "TGraph.h"
#include "TMath.h"

	using namespace std;

			void dla_analysis(){

				// x-y coordinate vectors
				vector<int> x_cor;
				vector<int> y_cor;

				// vector for fractal dimention calculation
				vector<double> M_vec;
				vector<double> L_vec;

				// file streaming
				ifstream reader1("dla_output.txt");
				ifstream reader2("fractal_dimension.txt");

				double a,b;

				do{

					reader1 >> a >> b;
					x_cor.push_back(a);
					y_cor.push_back(b);



				}while( !reader1.eof() );

				a = 0;
				b = 0;

				do{

				 	reader2 >> a >> b;
				 	M_vec.push_back(log(a));
				 	L_vec.push_back(log(b));


				}while( !reader2.eof() );

				TGraph* gr1 = new TGraph(x_cor.size(), &x_cor[0], &y_cor[0]);
				TGraph* gr2 = new TGraph(M_vec.size(), &L_vec[0], &M_vec[0]);


				c1 = new TCanvas("c1","c1",600,400);
				c1->cd();
				gr1->SetMarkerColor(4);
				gr1->SetMarkerStyle(6);
				gr1->SetTitle("Fractal pictured in the x-y plane");
				gr1->GetXaxis()->SetTitle("X");
				gr1->GetYaxis()->SetTitle("Y");
				gr1->Draw("AP");

				gStyle->SetOptFit(11);
				c2 = new TCanvas("c2","c2",600,400);
				c2->cd();
				gr2->SetTitle("log(M) vs log(L) graph");
				gr2->GetXaxis()->SetTitle("Log(L)");
				gr2->GetYaxis()->SetTitle("Log(M)");
				gr2->Fit("pol1");
				gr2->Draw("A*");




				// end
			}