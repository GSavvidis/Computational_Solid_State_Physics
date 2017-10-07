		#include <iostream>
		#include <fstream>
		#include <vector>

		#include "TGraph.h"
		#include "TCanvas.h"
		#include "TMultiGraph.h"

		using namespace std;

		void pdf(){

		vector <double> v1,v11;
		vector <double> v2,v22;
		vector <double> v3,v33;
			
		double a,b;

		ifstream m1("pdf_trapping1.txt");
		ifstream m2("pdf_trapping2.txt");
		ifstream m3("pdf_trapping3.txt");


			do {

				m1 >> a >> b;
				v1.push_back(a);
				v11.push_back(b);

		}while(!m1.eof());

			a = 0;
			b = 0;

			do {

				m2 >> a >> b;
				v2.push_back(a);
				v22.push_back(b);

		}while(!m2.eof());

			a = 0;
			b = 0;
			
			do {

				m3 >> a >> b;
				v3.push_back(a);
				v33.push_back(b);

		}while(!m3.eof());

		TGraph* pdf1 = new TGraph(v1.size(),&v1[0],&v11[0]);
		TGraph* pdf2 = new TGraph(v2.size(),&v2[0],&v22[0]);
		TGraph* pdf3 = new TGraph(v3.size(),&v3[0],&v33[0]);
		TMultiGraph* mg = new TMultiGraph();

		c1 = new TCanvas("c1","c1",600,400);
		c1->cd();
		c1->SetLogx();
		c1->SetLogy();
		pdf1->SetLineColor(2);
		pdf1->SetMarkerColor(2);
//		pdf1->SetMarkerStyle(2);
//		pdf1->Draw("A*");

		//c2 = new TCanvas("c2","c2",600,400);
		//c2->cd();
		pdf2->SetLineColor(3);
		pdf2->SetMarkerColor(3);
//		pdf2->SetMarkerStyle(4);
//		pdf2->Draw("*");

		//c3 = new TCanvas("c3","c3",600,400);
		//c3->cd();
		pdf3->SetLineColor(4);
		pdf3->SetMarkerColor(4);
//		pdf3->SetMarkerStyle(5);
//		pdf3->Draw("*");

		mg->Add(pdf1);
		mg->Add(pdf2);
		mg->Add(pdf3);
		mg->Draw("A");
		mg->GetXaxis()->SetTitle("Number of steps n");
		mg->GetYaxis()->SetTitle("Survival probability P(n)");
		mg->SetTitle("P(n) vs n for the three different cases");



			// end
		}