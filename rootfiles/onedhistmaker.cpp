void onedhistmaker()
{
  TFile *input0 = new TFile("photonprimary10gev", "read");
  TTree *tree0 = (TTree*)input0->Get("Hits");
  TFile *input1 = new TFile("photonprimary33gev", "read");
  TTree *tree1 = (TTree*)input1->Get("Hits");
  TFile *input2 = new TFile("photonprimary66gev", "read");
  TTree *tree2 = (TTree*)input2->Get("Hits");
  TFile *input3 = new TFile("photonprimary100gev", "read");
  TTree *tree3 = (TTree*)input3->Get("Hits");
  TFile *input4 = new TFile("photonprimary333gev", "read");
  TTree *tree4 = (TTree*)input4->Get("Hits");
  TFile *input5 = new TFile("photonprimary666gev", "read");
  TTree *tree5 = (TTree*)input5->Get("Hits");
  TFile *input6 = new TFile("photonprimary1kgev", "read");
  TTree *tree6 = (TTree*)input6->Get("Hits");
  TFile *input7 = new TFile("photonprimary2kgev", "read");
  TTree *tree7 = (TTree*)input7->Get("Hits");
  TFile *input8 = new TFile("photonprimary3kgev", "read");
  TTree *tree8 = (TTree*)input8->Get("Hits");
  TFile *input9 = new TFile("photonprimary4kgev", "read");
  TTree *tree9 = (TTree*)input9->Get("Hits");
  TFile *input10 = new TFile("photonprimary5kgev", "read");
  TTree *tree10 = (TTree*)input10->Get("Hits");
  TFile *input11 = new TFile("photonprimary6kgev", "read");
  TTree *tree11 = (TTree*)input11->Get("Hits");
  TFile *input12 = new TFile("photonprimary7kgev", "read");
  TTree *tree12 = (TTree*)input12->Get("Hits");
  TFile *input13 = new TFile("photonprimary8kgev", "read");
  TTree *tree13 = (TTree*)input13->Get("Hits");
  TFile *input14 = new TFile("photonprimary9kgev", "read");
  TTree *tree14 = (TTree*)input14->Get("Hits");
  TFile *input15 = new TFile("photonprimary10kgev", "read");
  TTree *tree15 = (TTree*)input15->Get("Hits");

  double z0, per0, z1, per1, z2, per2, z3, per3, z4, per4, z5, per5, z6, per6, z7, per7, z8, per8, z9, per9, z10, per10, z11, per11, z12, per12, z13, per13, z14, per14, z15, per15;
  int diff0, diff1, diff2, diff3, diff4, diff5, diff6, diff7, diff8, diff9, diff10, diff11, diff12, diff13, diff14, diff15;

//copied macro_graph and was too lazy to change all the variables so diff is energy and per is partnames now 

  tree0->SetBranchAddress("Z", &z0);
//  tree0->SetBranchAddress("nrg", &diff0);
 // tree0->SetBranchAddress("partnames", &per0);

  tree1->SetBranchAddress("Z", &z1);
//  tree1->SetBranchAddress("nrg", &diff1);
  //tree1->SetBranchAddress("partnames", &per1);

  tree2->SetBranchAddress("Z", &z2);
//  tree2->SetBranchAddress("nrg", &diff2);
  //tree2->SetBranchAddress("partnames", &per2);

  tree3->SetBranchAddress("Z", &z3);
//  tree3->SetBranchAddress("nrg", &diff3);
  //tree3->SetBranchAddress("partnames", &per3);

  tree4->SetBranchAddress("Z", &z4);
  //tree4->SetBranchAddress("nrg", &diff4);
//  tree4->SetBranchAddress("partnames", &per4);

  tree5->SetBranchAddress("Z", &z5);
  //tree5->SetBranchAddress("nrg", &diff5);
//  tree5->SetBranchAddress("partnames", &per5);

  tree6->SetBranchAddress("Z", &z6);
//  tree6->SetBranchAddress("nrg", &diff6);
  //tree6->SetBranchAddress("partnames", &per6);

  tree7->SetBranchAddress("Z", &z7);
//  tree7->SetBranchAddress("nrg", &diff7);
  //tree7->SetBranchAddress("partnames", &per7);

  tree8->SetBranchAddress("Z", &z8);
//  tree8->SetBranchAddress("nrg", &diff8);
  //tree8->SetBranchAddress("partnames", &per8);

  tree9->SetBranchAddress("Z", &z9);
  //tree9->SetBranchAddress("nrg", &diff9);
//  tree9->SetBranchAddress("partnames", &per9);

  tree10->SetBranchAddress("Z", &z10);
//  tree10->SetBranchAddress("nrg", &diff10);
  //tree10->SetBranchAddress("partnames", &per10);

  tree11->SetBranchAddress("Z", &z11);
//  tree11->SetBranchAddress("nrg", &diff11);
  //tree11->SetBranchAddress("partnames", &per11);

  tree12->SetBranchAddress("Z", &z12);
//  tree12->SetBranchAddress("nrg", &diff12);
  //tree12->SetBranchAddress("partnames", &per12);

  tree13->SetBranchAddress("Z", &z13);
//  tree13->SetBranchAddress("nrg", &diff13);
  //tree13->SetBranchAddress("partnames", &per13);

  tree14->SetBranchAddress("Z", &z14);
//  tree14->SetBranchAddress("nrg", &diff14);
  //tree14->SetBranchAddress("partnames", &per14);

  tree15->SetBranchAddress("Z", &z15);
//  tree15->SetBranchAddress("nrg", &diff15);
  //tree15->SetBranchAddress("partnames", &per15);

  int entries0 = tree0->GetEntries();
  int entries1 = tree1->GetEntries();
  int entries2 = tree2->GetEntries();
  int entries3 = tree3->GetEntries();
  int entries4 = tree4->GetEntries();
  int entries5 = tree5->GetEntries();
  int entries6 = tree6->GetEntries();
  int entries7 = tree7->GetEntries();
  int entries8 = tree8->GetEntries();
  int entries9 = tree9->GetEntries();
  int entries10 = tree10->GetEntries();
  int entries11 = tree11->GetEntries();
  int entries12 = tree12->GetEntries();
  int entries13 = tree13->GetEntries();
  int entries14 = tree14->GetEntries();
  int entries15 = tree15->GetEntries();

  TH1F *hist0 = new TH1F("hist0", "Number of Particles Throughout Photon Sim 10 GeV", 1000, 0, 10000);
  hist0->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist0->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist1 = new TH1F("hist1", "Number of Particles Throughout Photon Sim 33 GeV", 1000, 0, 10000);
  hist1->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist1->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist2 = new TH1F("hist2", "Number of Particles Throughout Photon Sim 66 GeV", 1000, 0, 10000);
  hist2->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist2->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist3 = new TH1F("hist3", "Number of Particles Throughout Photon Sim 100 GeV", 1000, 0, 10000);
  hist3->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist3->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist4 = new TH1F("hist4", "Number of Particles Throughout Photon Sim 333 GeV", 1000, 0, 10000);
  hist4->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist4->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist5 = new TH1F("hist5", "Number of Particles Throughout Photon Sim 666 GeV", 1000, 0, 10000);
  hist5->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist5->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist6 = new TH1F("hist6", "Number of Particles Throughout Photon Sim 1000 GeV", 1000, 0, 10000);
  hist6->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist6->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist7 = new TH1F("hist7", "Number of Particles Throughout Photon Sim 2000 GeV", 1000, 0, 10000);
  hist7->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist7->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist8 = new TH1F("hist8", "Number of Particles Throughout Photon Sim 3000 GeV", 1000, 0, 10000);
  hist8->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist8->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist9 = new TH1F("hist9", "Number of Particles Throughout Photon Sim 4000 GeV", 1000, 0, 10000);
  hist9->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist9->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist10 = new TH1F("hist10", "Number of Particles Throughout Photon Sim 5000 GeV", 1000, 0, 10000);
  hist10->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist10->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist11 = new TH1F("hist11", "Number of Particles Throughout Photon Sim 6000 GeV", 1000, 0, 10000);
  hist11->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist11->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist12 = new TH1F("hist12", "Number of Particles Throughout Photon Sim 7000 GeV", 1000, 0, 10000);
  hist12->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist12->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist13 = new TH1F("hist13", "Number of Particles Throughout Photon Sim 8000 GeV", 1000, 0, 10000);
  hist13->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist13->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist14 = new TH1F("hist14", "Number of Particles Throughout Photon Sim 9000 GeV", 1000, 0, 10000);
  hist14->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist14->GetYaxis()->SetTitle("Number of Particles");

  TH1F *hist15 = new TH1F("hist15", "Number of Particles Throughout Photon Sim 10000 GeV", 1000, 0, 10000);
  hist15->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist15->GetYaxis()->SetTitle("Number of Particles");

  for(int i = 0; i < entries0; i++)
  {
    tree0->GetEntry(i);

    hist0->Fill(z0);
  }
  for(int i = 0; i < entries1; i++)
  {
    tree1->GetEntry(i);

    hist1->Fill(z1);
  }
  for(int i = 0; i < entries2; i++)
  {
    tree2->GetEntry(i);

    hist2->Fill(z2);
  }
  for(int i = 0; i < entries3; i++)
  {
    tree3->GetEntry(i);

    hist3->Fill(z3);
  }
  for(int i = 0; i < entries4; i++)
  {
    tree4->GetEntry(i);

    hist4->Fill(z4);
  }
  for(int i = 0; i < entries5; i++)
  {
    tree5->GetEntry(i);

    hist5->Fill(z5);
  }

  for(int i = 0; i < entries6; i++)
  {
    tree6->GetEntry(i);

    hist6->Fill(z6);
  }
  for(int i = 0; i < entries7; i++)
  {
    tree7->GetEntry(i);

    hist7->Fill(z7);
  }
  for(int i = 0; i < entries8; i++)
  {
    tree8->GetEntry(i);

    hist8->Fill(z8);
  }
  for(int i = 0; i < entries9; i++)
  {
    tree9->GetEntry(i);

    hist9->Fill(z9);
  }
  for(int i = 0; i < entries10; i++)
  {
    tree10->GetEntry(i);

    hist10->Fill(z10);
  }
  for(int i = 0; i < entries11; i++)
  {
    tree11->GetEntry(i);

    hist11->Fill(z11);
  }

  for(int i = 0; i < entries12; i++)
  {
    tree12->GetEntry(i);

    hist12->Fill(z12);
  }
  for(int i = 0; i < entries13; i++)
  {
    tree13->GetEntry(i);

    hist13->Fill(z13);
  }
  for(int i = 0; i < entries14; i++)
  {
    tree14->GetEntry(i);

    hist14->Fill(z14);
  }
  for(int i = 0; i < entries15; i++)
  {
    tree15->GetEntry(i);

    hist15->Fill(z15);
  }

  hist0->SetMarkerStyle(3);
  hist1->SetMarkerStyle(3);
  hist2->SetMarkerStyle(3);
  hist3->SetMarkerStyle(3);
  hist4->SetMarkerStyle(3);
  hist5->SetMarkerStyle(3);
  hist6->SetMarkerStyle(3);
  hist7->SetMarkerStyle(3);
  hist8->SetMarkerStyle(3);
  hist9->SetMarkerStyle(3);
  hist10->SetMarkerStyle(3);
  hist11->SetMarkerStyle(3);
  hist12->SetMarkerStyle(3);
  hist13->SetMarkerStyle(3);
  hist14->SetMarkerStyle(3);
  hist15->SetMarkerStyle(3);

  TCanvas *c0 = new TCanvas("c0", "c0", 1000, 500);
  hist0->Draw();

  TCanvas *c1 = new TCanvas("c1", "c1", 1000, 500);
  hist1->Draw();

  TCanvas *c2 = new TCanvas("c2", "c2", 1000, 500);
  hist2->Draw();

  TCanvas *c3 = new TCanvas("c3", "c3", 1000, 500);
  hist3->Draw();

  TCanvas *c4 = new TCanvas("c4", "c4", 1000, 500);
  hist4->Draw();

  TCanvas *c5 = new TCanvas("c5", "c5", 1000, 500);
  hist5->Draw();

  TCanvas *c6 = new TCanvas("c6", "c6", 1000, 500);
  hist6->Draw();

  TCanvas *c7 = new TCanvas("c7", "c7", 1000, 500);
  hist7->Draw();

  TCanvas *c8 = new TCanvas("c8", "c8", 1000, 500);
  hist8->Draw();

  TCanvas *c9 = new TCanvas("c9", "c9", 1000, 500);
  hist9->Draw();

  TCanvas *c10 = new TCanvas("c10", "c10", 1000, 500);
  hist10->Draw();

  TCanvas *c11 = new TCanvas("c11", "c11", 1000, 500);
  hist11->Draw();

  TCanvas *c12 = new TCanvas("c12", "c12", 1000, 500);
  hist12->Draw();

  TCanvas *c13 = new TCanvas("c13", "c13", 1000, 500);
  hist13->Draw();

  TCanvas *c14 = new TCanvas("c14", "c14", 1000, 500);
  hist14->Draw();

  TCanvas *c15 = new TCanvas("c15", "c15", 1000, 500);
  hist15->Draw();

  c0->Print("numberofpartsphoton10gev.pdf");
  c1->Print("numberofpartsphoton33gev.pdf");
  c2->Print("numberofpartsphoton66gev.pdf");
  c3->Print("numberofpartsphoton100gev.pdf");
  c4->Print("numberofpartsphoton333gev.pdf");
  c5->Print("numberofpartsphoton666gev.pdf");
  c6->Print("numberofpartsphoton1000gev.pdf");
  c7->Print("numberofpartsphoton2000gev.pdf");
  c8->Print("numberofpartsphoton3000gev.pdf");
  c9->Print("numberofpartsphoton4000gev.pdf");
  c10->Print("numberofpartsphoton5000gev.pdf");
  c11->Print("numberofpartsphoton6000gev.pdf");
  c12->Print("numberofpartsphoton7000gev.pdf");
  c13->Print("numberofpartsphoton8000gev.pdf");
  c14->Print("numberofpartsphoton9000gev.pdf");
  c15->Print("numberofpartsphoton10000gev.pdf");

}

