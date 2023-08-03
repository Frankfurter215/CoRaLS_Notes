void tchainaveragehist()
{
  TChain *ch0 = new TChain("Hits");
  ch0->Add("photonprimarty0_t0.root");
  ch0->Add("photonprimarty0_t0.root");
  ch0->Add("photonprimarty0_t2.root");
  ch0->Add("photonprimarty0_t3.root");
  ch0->Add("photonprimarty0_t4.root");
  ch0->Add("photonprimarty0_t5.root");
  ch0->Add("photonprimarty0_t6.root");
  ch0->Add("photonprimarty0_t7.root");
  ch0->Add("photonprimarty0_t8.root");
  ch0->Add("photonprimarty0_t9.root");

  double Z;

  ch0->SetBranchAddress("Z", &Z);

  int entries = ch0->GetEntries();

  TH1F *hist0 = new TH1F("hist0", "Shower Length Average 6k GeV", 1000, 0, 10000);
  hist0->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist0->GetYaxis()->SetTitle("Number of Particles");

  for(int i = 0; i < entries; i++)
  {
    ch0->GetEntry(i);
    hist0->Fill(Z);
  }

  for (int i = 1; i <= hist0->GetNbinsX(); i++)
  {
    double binContent = hist0->GetBinContent(i);
    double averageBinContent = binContent / 10.;
    hist0->SetBinContent(i, averageBinContent);
  }

  TCanvas *c0 = new TCanvas();
  c0->SetGridx();
  c0->SetGridy();
  hist0->Draw();

}
