{
  //TFile *_file0 = TFile::Open("B4.root");

  //TChain* T = new TChain("T");
  TChain* T = new TChain("tree");
  TChain* T2 = new TChain("tree");
  //T->Add("100kEventsFullAfternoMSC.root");
  //T->Add("noMSCafter.root");
  //T->Add("10000munuevent.root");
  //T->Add("100kmunu.root");
  //T->Add("Final100kTASDNustormNuMu.root");
  T->Add("MINDmubeam100k.root");
  T2->Add("MINDantimubeam100k.root"); 
  //T->Add("NuStorm/MINDnustormnumubeam100k.root");
  //T2->Add("NuStorm/MINDnustormantinumubeam100k.root");
  //T->Add("NuStorm/MINDTASDnumubeam100k.root");
  //T2->Add("NuStorm/MINDTASDantinumubeam100k.root");
  //T->Add("MSCafter.root");
  //T->Add("T2K/T2KnumubeamMIND.root");
  //T2->Add("T2K/T2KantinumubeamMIND.root");
  
  //T->Draw("MCtr_Mom:track_len","","COLZ");
  TH2D* momentum = new TH2D("momentum","#nu_{#mu} beam 50Mev/c/bin;True Momentum (MeV/c);Rec Momentum (MeV/c)",100,0,5000,100,0,5000);
  TH2D* momentum2 = new TH2D("momentum2","#bar{#nu_{#mu}} beam 50Mev/c/bin;True Momentum (MeV/c);Rec Momentum (MeV/c)",100,0,5000,100,0,5000);
  //TH2D* momentum = new TH2D("momentum","#mu^{-} beam 500Mev/c/bin;True Momentum (MeV/c);Rec Momentum (MeV/c)",20,0,10000,20,0,10000);
  //TH2D* momentum2 = new TH2D("momentum2","#mu^{+} beam 500Mev/c/bin;True Momentum (MeV/c);Rec Momentum (MeV/c)",20,0,10000,20,0,10000);

  TH2D* momentumDiff = new TH2D("momentumDiff",";True Momentum (MeV/c);Rec-True Momentum (MeV/c)",100,0,5000,100,-5,5);

  TH1D* eff = new TH1D("eff",";#mu^{#pm} True Momentum (MeV/c); Fractional Efficiency",100, 0, 10000);
  TH1D* all = new TH1D("all",";#mu^{#pm} True Momentum (MeV/c); Fractional Efficiency",100, 0, 10000);

  TH1D* feff = new TH1D("feff",";#mu^{#pm} True Momentum (MeV/c); Fractional Efficiency",100, 0, 10000);
  TH1D* fall = new TH1D("fall",";#mu^{#pm} True Momentum (MeV/c); Fractional Efficiency",100, 0, 10000);

  TH1D* eff2 = new TH1D("eff2",";#mu^{#pm} True Momentum (MeV/c); Fractional Efficiency",100, 0, 10000);
  TH1D* all2 = new TH1D("all2",";#mu^{#pm} True Momentum (MeV/c); Fractional Efficiency",100, 0, 10000);

  TH1D* feff2 = new TH1D("feff2",";#mu^{#pm} True Momentum (MeV/c); Fractional Efficiency",100, 0, 10000);
  TH1D* fall2 = new TH1D("fall2",";#mu^{#pm} True Momentum (MeV/c); Fractional Efficiency",100, 0, 10000);

    //T->Draw("abs(mom)-abs(MCtr_Mom):abs(MCtr_Mom)")
    //diff on y, mom on x;
    
  //T->Draw("abs(mom):abs(MCtr_Mom)>>momentum","","COLZ");
  //T->Draw("abs(Rec_mom):abs(MCtr_Mom)>>momentum","","COLZ");
  //Rec_mom
  //Rec_mom_range
  T->Draw("abs(Rec_mom):abs(MCtr_Mom)>>momentum","Fitted && pdg==13","COLZ");
  T2->Draw("abs(Rec_mom):abs(MCtr_Mom)>>momentum2","Fitted && pdg==-13","COLZ");

  //T->Draw("(abs(mom)-abs(MCtr_Mom))/abs(MCtr_Mom):abs(MCtr_Mom)>>momentumDiff","","COLZ");
  //T->Draw("(abs(Rec_mom)-abs(MCtr_Mom))/abs(MCtr_Mom):abs(MCtr_Mom)>>momentumDiff","","COLZ");

  T->Draw("(abs(Rec_mom)-abs(MCtr_Mom))/abs(MCtr_Mom):abs(MCtr_Mom)>>momentumDiff","","COLZ");

  //T->Draw("abs(MCtr_Mom)>>eff","Charge==-1","COLZ");
  //T->Draw("abs(MCtr_Energy)>>eff","Rec_Charge==-1","COLZ");
  T->Draw("abs(MCtr_Mom)>>eff","Rec_Charge==1 && Fitted && pdg==13","COLZ");
  T2->Draw("abs(MCtr_Mom)>>eff2","Rec_Charge==1 && Fitted && pdg==-13","COLZ");

  T->Draw("abs(MCtr_Mom)>>feff","Fitted && pdg==13","COLZ");
  T2->Draw("abs(MCtr_Mom)>>feff2","Fitted && pdg==-13","COLZ");
  //T->Draw("abs(MCtr_Mom)>>eff","abs(Charge)>0","COLZ"); // Check efficiency of charge rec.
  // If good, can flip sign after below 50%.
  T->Draw("abs(MCtr_Mom)>>all","Fitted && pdg==13","COLZ");
  T2->Draw("abs(MCtr_Mom)>>all2","Fitted && pdg==-13","COLZ");

  T->Draw("abs(MCtr_Mom)>>fall","pdg==13","COLZ");
  T2->Draw("abs(MCtr_Mom)>>fall2","pdg==-13","COLZ");
  //T->Draw("abs(MCtr_Energy)>>all","","COLZ");

  TEfficiency* pEff = 0;
  TEfficiency* pEff2 = 0;

  TEfficiency* fEff = 0;
  TEfficiency* fEff2 = 0;

  pEff = new TEfficiency((*eff),(*all));
  pEff->SetLineColor(kRed);
  pEff->SetTitle("Charge identification efficiency");
  pEff2 = new TEfficiency((*eff2),(*all2));
  pEff2->SetLineColor(kBlue);

  fEff = new TEfficiency((*feff),(*fall));
  fEff->SetLineColor(kRed);
  fEff->SetTitle("Reconstructed efficiency");
  fEff2 = new TEfficiency((*feff2),(*fall2));
  fEff2->SetLineColor(kBlue);

  fEff->CreateGraph()->Draw();
  fEff2->CreateGraph()->Draw("same");

  TLegend* leg = new TLegend(0.8,0.1,0.9,0.3);
  leg->SetHeader("Legend");
  //leg->AddEntry(&testA,"#9,3","f");
  //leg->AddEntry(&testB,"#9,6","f");

  //leg->AddEntry(pEff2,"#mu^{+}","l");
  //leg->AddEntry(pEff,"#mu^{-}","l");
  leg->AddEntry(pEff2,"#bar{#nu_{#mu}}","l");
  leg->AddEntry(pEff,"#nu_{#mu}","l");
  //leg->AddEntry(ChargeID,"Testbeam #mu^{-}","p");
  //leg->AddEntry(grp,"Testbeam #mu^{+}","p");
  //leg->AddEntry(grn,"Testbeam #mu^{-}","p");

  //leg->AddEntry(&testC,"#9,9","f");
  //leg->AddEntry(&testD,"#9,6,50","f");
  //leg->AddEntry(&testE,"#9,9,20","f");
  //leg->AddEntry(&testF,"#9,9,50","f");
  leg->Draw();

  /*
  eff->Sumw2();
  all->Sumw2();
  eff->Divide(all);
  eff->Draw();
  */

}
