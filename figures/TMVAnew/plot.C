{
	gROOT->SetBatch(0);

	TCanvas* c = new TCanvas("c","c",600,400);

	//TH1D* effA = new TH1D("effA",";True Momentum (GeV/c); Fractional Efficiency",50, 0, 1);

	const Int_t n = 10;
  	Float_t x[n]  = {0.5,1,1.5,2,2.5,3,3.5,4,4.5,5};
  	Float_t y[n]  = {1.8*1,1.8*1.1,1.8*1,1.8*1.1,1.8*1.15,1.8*1.2,1.8*1.08,1.8*0.95,1.8*1.1,1.8*1};
 	Float_t ex[n] = {0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25};
 	Float_t ey[n] = {0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01};


	//TH1F (const char *name, const char *title, Int_t nbinsx, const Double_t *xbins)

	TGraphAsymmErrors *gr = new TGraphAsymmErrors(n,x,y,ex,ex,ey,ey);

 	gr->SetTitle("Curvature/Field correction study;Momentum of Muon [GeV/c];B-Field Fudge Factor");

	gr->Draw();	

}