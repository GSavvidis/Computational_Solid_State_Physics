		#include <iostream>
		#include <fstream>

		#include "TH1F.h"
		#include "TCanvas.h"
		#include "TPaveText.h"



		void histogram(){

		double t1,t2,t3;
			
		ifstream m1("hist_trapping1.txt");
		ifstream m2("hist_trapping2.txt");
		ifstream m3("hist_trapping3.txt");

//		TH1F *hist1 = new TH1F("Trapping1","P(n) distribution for c = 0.1",100,0,200);
		TH1F *hist1 = new TH1F("Trapping","P(n) distribution in logarithmic scale ",10000,0,200000);
		TH1F *hist2 = new TH1F("Trapping2","P(n) distribution for c = 0.01",100,0,2000);
		TH1F *hist3 = new TH1F("Trapping3","P(n) distribution for c = 0.001",100,0,20000);


			do {

				m1 >> t1;
				hist1->Fill(t1);

				m2 >> t2;
				hist2->Fill(t2);

				m3 >> t3;
				hist3->Fill(t3);

		}while(!m1.eof());

			do {

				m2 >> t2;
				hist2->Fill(t2);

		}while(!m2.eof());

			do {

				m3 >> t3;
				hist3->Fill(t3);

		}while(!m3.eof());

		hist1->SetLineColor(2);
		hist2->SetLineColor(3);
		hist3->SetLineColor(4);


		c1 = new TCanvas("c1","c1",600,400);
		c1->cd();
		c1->SetLogx();
		c1->SetLogy();
		hist1->SetXTitle("Number of steps n");	
		hist1->SetYTitle("counts");
		hist1->Draw();

//		c2 = new TCanvas("c2","c2",600,400);
//		c2->cd();
//		hist2->SetXTitle("Number of steps n");
//		hist2->SetYTitle("counts");
//		hist2->Draw();

//		c3 = new TCanvas("c3","c3",600,400);
//		c3->cd();
//		hist3->SetXTitle("Number of steps n");
//		hist3->SetYTitle("counts");
//		hist3->Draw();

		hist2->Draw("same");
		hist3->Draw("same");

			// end
		}