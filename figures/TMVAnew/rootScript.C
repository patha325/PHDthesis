{

gROOT->SetBatch(1);

TFile f("5May_2_ON_MCR0_T2K_beamline_trigger_beam60us_neutrinos_ON_all.root");

TCanvas* c = new TCanvas("c","c",600,400);
TH1F *histo = new TH1F("histo","histo",100,-5000,5000);

TH2F *ratioHisto  = new TH2F("ratioHisto","ratioHisto", 96,0,95,100,0,1);

for(int j=0;j<64;j++)
{
	cout<<"FEB counter="<<j<<endl;
	TString tmpFEB; tmpFEB.Form("%d",j); 
	TTree *T = (TTree*)f.Get("FEB_"+tmpFEB);
	if(T)
	{
		for(int i=0;i<96;i++)
		{
			TString tmpchannel; tmpchannel.Form("%d",i); 
			TString cut ="FEB_"+tmpFEB+"_hitsChannel=="+tmpchannel;
			/*
			T->Draw("FEB_"+tmpFEB+"_hitTimeDif>>histo","abs(FEB_"+tmpFEB+"_hitTimeDif)>10 && "+cut);
			if(histo->GetEntries()<100)
			{
				cout<<"For FEB=="<<j<<" and for channel=="<<i<<" "<<histo->GetEntries()<<endl;
			}
			*/

			T->Draw("FEB_"+tmpFEB+"_hitLeadTime>>histo",cut);
			int times = histo->GetEntries();
			//cout<<times:
			T->Draw("FEB_"+tmpFEB+"_hitAmpl>>histo","abs(FEB_"+tmpFEB+"_hitAmpl)>1 && "+cut);
			int amps = histo->GetEntries();
			//cout<<times<<" "<<amps<<endl;
			double ratio = (double)amps/(double)times;
			//cout<<"For FEB=="<<j<<" and for channel=="<<i<<" "<<ratio<<endl;
			ratioHisto->Fill(i,ratio);
		}
	}
}
ratioHisto->Draw();
c->SaveAs("hist1.pdf");
c->SaveAs("hist1.root");

//histo->Draw();

/*
FEB_0_SN
_SpillTag
_SpillTime
_SpillTimeGTrig
_GTrigTag
_GTrigTime
_hitsChannel
_hitAmpl
_hitLGAmpl
_hitLeadTime
_hitTrailTime
_hitTimeDif
_hitTimefromSpill

*/

//hittime > 10, look for more than 100 events per channel.
}