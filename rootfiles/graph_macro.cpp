void graph_macro()
{
  TFile *input0 = new TFile("percentexcess2000.root", "read");
  TTree *tree0 = (TTree*)input0->Get("result_tree");
  TFile *input1 = new TFile("percentexcess4000.root", "read");
  TTree *tree1 = (TTree*)input1->Get("result_tree");
  TFile *input2 = new TFile("percentexcess5000.root", "read");
  TTree *tree2 = (TTree*)input2->Get("result_tree");
  TFile *input3 = new TFile("percentexcess7000.root", "read");
  TTree *tree3 = (TTree*)input3->Get("result_tree");
  TFile *input4 = new TFile("percentexcess8000.root", "read");
  TTree *tree4 = (TTree*)input4->Get("result_tree");
  TFile *input5 = new TFile("percentexcess9000.root", "read");
  TTree *tree5 = (TTree*)input5->Get("result_tree");
//  TFile *input6 = new TFile("percentexcess1k.root", "read");
//  TTree *tree6 = (TTree*)input6->Get("result_tree");
//  TFile *input7 = new TFile("percentexcess3000.root", "read");
//  TTree *tree7 = (TTree*)input7->Get("result_tree");
//  TFile *input8 = new TFile("percentexcess6000.root", "read");
 // TTree *tree8 = (TTree*)input8->Get("result_tree");
//  TFile *input9 = new TFile("percentexcess10k.root", "read");
 // TTree *tree9 = (TTree*)input9->Get("result_tree");

  double z0, per0, z1, per1, z2, per2, z3, per3, z4, per4, z5, per5;//, z6, per6, z7, per7, z8, per8, z9, per9;
  int diff0, diff1, diff2, diff3, diff4, diff5;//, diff6, diff7, diff8, diff9;

  tree0->SetBranchAddress("z", &z0);
  tree0->SetBranchAddress("difference", &diff0);
  tree0->SetBranchAddress("percentage", &per0);

  tree1->SetBranchAddress("z", &z1);
  tree1->SetBranchAddress("difference", &diff1);
  tree1->SetBranchAddress("percentage", &per1);

  tree2->SetBranchAddress("z", &z2);
  tree2->SetBranchAddress("difference", &diff2);
  tree2->SetBranchAddress("percentage", &per2);

  tree3->SetBranchAddress("z", &z3);
  tree3->SetBranchAddress("difference", &diff3);
  tree3->SetBranchAddress("percentage", &per3);

  tree4->SetBranchAddress("z", &z4);
  tree4->SetBranchAddress("difference", &diff4);
  tree4->SetBranchAddress("percentage", &per4);

  tree5->SetBranchAddress("z", &z5);
  tree5->SetBranchAddress("difference", &diff5);
  tree5->SetBranchAddress("percentage", &per5);
/*
  tree6->SetBranchAddress("z", &z6);
  tree6->SetBranchAddress("difference", &diff6);
  tree6->SetBranchAddress("percentage", &per6);

  tree7->SetBranchAddress("z", &z7);
  tree7->SetBranchAddress("difference", &diff7);
  tree7->SetBranchAddress("percentage", &per7);

  tree8->SetBranchAddress("z", &z8);
  tree8->SetBranchAddress("difference", &diff8);
  tree8->SetBranchAddress("percentage", &per8);

  tree9->SetBranchAddress("z", &z9);
  tree9->SetBranchAddress("difference", &diff9);
  tree9->SetBranchAddress("percentage", &per9);
*/
  int entries0 = tree0->GetEntries();
  int entries1 = tree1->GetEntries();
  int entries2 = tree2->GetEntries();
  int entries3 = tree3->GetEntries();
  int entries4 = tree4->GetEntries();
  int entries5 = tree5->GetEntries();
/*
  int entries6 = tree6->GetEntries();
  int entries7 = tree7->GetEntries();
  int entries8 = tree8->GetEntries();
  int entries9 = tree9->GetEntries();
*/
  TH2F *hist0 = new TH2F("hist0", "Difference Between e- and e+ related to Sim distance 2000GeV", 1000, 0, 10000, 1000, 0, 150000);
  hist0->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist0->GetYaxis()->SetTitle("Number of Particles");
  TH2F *hist0a = new TH2F("hist0a", "Percent Diff Between e- and e+ related to Sim distance 2000GeV", 100, 0, 10000, 100, 0.3, 1.3);
  hist0a->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist0a->GetYaxis()->SetTitle("Percent Diff (diff/totalparts)");

  TH2F *hist1 = new TH2F("hist1", "Difference Between e- and e+ related to Sim distance 4000GeV", 1000, 0, 10000, 1000, 0, 400000);
  hist1->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist1->GetYaxis()->SetTitle("Number of Particles");
  TH2F *hist1a = new TH2F("hist1a", "Percent Diff Between e- and e+ related to Sim distance 4000GeV", 100, 0, 10000, 100, 0.3, 1.3);
  hist1a->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist1a->GetYaxis()->SetTitle("Percent Diff (diff/totalparts)");

  TH2F *hist2 = new TH2F("hist2", "Difference Between e- and e+ related to Sim distance 5000GeV", 1000, 0, 10000, 100, 0, 500000);
  hist2->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist2->GetYaxis()->SetTitle("Number of Particles");
  TH2F *hist2a = new TH2F("hist2a", "Percent Diff Between e- and e+ related to Sim distance 5000GeV", 100, 0, 10000, 100, 0.3, 1.3);
  hist2a->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist2a->GetYaxis()->SetTitle("Percent Diff (diff/totalparts)");

  TH2F *hist3 = new TH2F("hist3", "Difference Between e- and e+ related to Sim distance 7000GeV", 1000, 0, 10000, 10000, 0, 800000);
  hist3->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist3->GetYaxis()->SetTitle("Number of Particles");
  TH2F *hist3a = new TH2F("hist3a", "Percent Diff Between e- and e+ related to Sim distance 7000GeV", 100, 0, 10000, 100, 0.3, 1.3);
  hist3a->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist3a->GetYaxis()->SetTitle("Percent Diff (diff/totalparts)");

  TH2F *hist4 = new TH2F("hist4", "Difference Between e- and e+ related to Sim distance 8000GeV", 1000, 0, 10000, 10000, 0, 900000);
  hist4->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist4->GetYaxis()->SetTitle("Number of Particles");
  TH2F *hist4a = new TH2F("hist4a", "Percent Diff Between e- and e+ related to Sim distance 8000GeV", 100, 0, 10000, 100, 0.3, 1.3);
  hist4a->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist4a->GetYaxis()->SetTitle("Percent Diff (diff/totalparts)");

  TH2F *hist5 = new TH2F("hist5", "Difference Between e- and e+ related to Sim distance 9000GeV", 1000, 0, 10000, 10000, 0, 800000);
  hist5->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist5->GetYaxis()->SetTitle("Number of Particles");
  TH2F *hist5a = new TH2F("hist5a", "Percent Diff Between e- and e+ related to Sim distance 9000GeV", 100, 0, 10000, 100, 0.3, 1.3);
  hist5a->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist5a->GetYaxis()->SetTitle("Percent Diff (diff/totalparts)");
/*
  TH2F *hist6 = new TH2F("hist6", "Difference Between e- and e+ related to Sim distance 1000GeV", 1000, 0, 10000, 10000, 0, 75000);
  hist6->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist6->GetYaxis()->SetTitle("Number of Particles");
  TH2F *hist6a = new TH2F("hist6a", "Percent Diff Between e- and e+ related to Sim distance 1000GeV", 100, 0, 10000, 100, 0.3, 1.3);
  hist6a->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist6a->GetYaxis()->SetTitle("Percent Diff (diff/totalparts)");

  TH2F *hist7 = new TH2F("hist7", "Difference Between e- and e+ related to Sim distance 3000GeV", 1000, 0, 10000, 10000, 0, 400000);
  hist7->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist7->GetYaxis()->SetTitle("Number of Particles");
  TH2F *hist7a = new TH2F("hist7a", "Percent Diff Between e- and e+ related to Sim distance 3000GeV", 100, 0, 10000, 100, 0.3, 1.3);
  hist7a->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist7a->GetYaxis()->SetTitle("Percent Diff (diff/totalparts)");
  
  TH2F *hist8 = new TH2F("hist8", "Difference Between e- and e+ related to Sim distance 6000GeV", 1000, 0, 10000, 10000, 0, 450000);
  hist8->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist8->GetYaxis()->SetTitle("Number of Particles");
  TH2F *hist8a = new TH2F("hist8a", "Percent Diff Between e- and e+ related to Sim distance 6000GeV", 100, 0, 10000, 100, 0.3, 1.3);
  hist8a->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist8a->GetYaxis()->SetTitle("Percent Diff (diff/totalparts)");

  TH2F *hist9 = new TH2F("hist9", "Difference Between e- and e+ related to Sim distance 10000GeV", 1000, 0, 10000, 10000, 0, 1000000);
  hist9->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist9->GetYaxis()->SetTitle("Number of Particles");
  TH2F *hist9a = new TH2F("hist9a", "Percent Diff Between e- and e+ related to Sim distance 10000GeV", 100, 0, 10000, 100, 0.3, 1.3);
  hist9a->GetXaxis()->SetTitle("Simulation Distance [mm]");
  hist9a->GetYaxis()->SetTitle("Percent Diff (diff/totalparts)");
*/
  for(int i = 0; i < entries0; i++)
  {
    tree0->GetEntry(i);

    hist0->Fill(z0, diff0);
    hist0a->Fill(z0, per0);
  }
  for(int i = 0; i < entries1; i++)
  {
    tree1->GetEntry(i);

    hist1->Fill(z1, diff1);
    hist1a->Fill(z1, per1);
  }
  for(int i = 0; i < entries2; i++)
  {
    tree2->GetEntry(i);

    hist2->Fill(z2, diff2);
    hist2a->Fill(z2, per2);
  }
  for(int i = 0; i < entries3; i++)
  {
    tree3->GetEntry(i);

    hist3->Fill(z3, diff3);
    hist3a->Fill(z3, per3);
  }
  for(int i = 0; i < entries4; i++)
  {
    tree4->GetEntry(i);

    hist4->Fill(z4, diff4);
    hist4a->Fill(z4, per4);
  }
  for(int i = 0; i < entries5; i++)
  {
    tree5->GetEntry(i);

    hist5->Fill(z5, diff5);
    hist5a->Fill(z5, per5);
  }
/*
  for(int i = 0; i < entries6; i++)
  {
    tree6->GetEntry(i);

    hist6->Fill(z6, diff6);
    hist6a->Fill(z6, per6);
  }
  for(int i = 0; i < entries7; i++)
  {
    tree7->GetEntry(i);

    hist7->Fill(z7, diff7);
    hist7a->Fill(z7, per7);
  }
  for(int i = 0; i < entries8; i++)
  {
    tree8->GetEntry(i);

    hist8->Fill(z8, diff8);
    hist8a->Fill(z8, per8);
  }
  for(int i = 0; i < entries9; i++)
  {
    tree9->GetEntry(i);

    hist9->Fill(z9, diff9);
    hist9a->Fill(z9, per9);
  }
*/

  hist0->SetMarkerStyle(3);
  hist0a->SetMarkerStyle(3);
  hist1->SetMarkerStyle(3);
  hist1a->SetMarkerStyle(3);
  hist2->SetMarkerStyle(3);
  hist2a->SetMarkerStyle(3);
  hist3->SetMarkerStyle(3);
  hist3a->SetMarkerStyle(3);
  hist4->SetMarkerStyle(3);
  hist4a->SetMarkerStyle(3);
  hist5->SetMarkerStyle(3);
  hist5a->SetMarkerStyle(3);
/*
  hist6->SetMarkerStyle(3);
  hist6a->SetMarkerStyle(3);
  hist7->SetMarkerStyle(3);
  hist7a->SetMarkerStyle(3);
  hist8->SetMarkerStyle(3);
  hist8a->SetMarkerStyle(3);
  hist9->SetMarkerStyle(3);
  hist9a->SetMarkerStyle(3);
*/
  TCanvas *c0 = new TCanvas("c0", "c0", 1000, 500);
  hist0->Draw();
  TCanvas *c0a = new TCanvas("c0a", "c0a", 1000, 500);
  hist0a->Draw();

  TCanvas *c1 = new TCanvas("c1", "c1", 1000, 500);
  hist1->Draw();
  TCanvas *c1a = new TCanvas("c1a", "c1a", 1000, 500);
  hist1a->Draw();

  TCanvas *c2 = new TCanvas("c2", "c2", 1000, 500);
  hist2->Draw();
  TCanvas *c2a = new TCanvas("c2a", "c2a", 1000, 500);
  hist2a->Draw();

  TCanvas *c3 = new TCanvas("c3", "c3", 1000, 500);
  hist3->Draw();
  TCanvas *c3a = new TCanvas("c3a", "c3a", 1000, 500);
  hist3a->Draw();

  TCanvas *c4 = new TCanvas("c4", "c4", 1000, 500);
  hist4->Draw();
  TCanvas *c4a = new TCanvas("c4a", "c4a", 1000, 500);
  hist4a->Draw();

  TCanvas *c5 = new TCanvas("c5", "c5", 1000, 500);
  hist5->Draw();
  TCanvas *c5a = new TCanvas("c5a", "c5a", 1000, 500);
  hist5a->Draw();
/*
  TCanvas *c6 = new TCanvas("c6", "c6", 1000, 500);
  hist6->Draw();
  TCanvas *c6a = new TCanvas("c6a", "c6a", 1000, 500);
  hist6a->Draw();

  TCanvas *c7 = new TCanvas("c7", "c7", 1000, 500);
  hist7->Draw();
  TCanvas *c7a = new TCanvas("c7a", "c7a", 1000, 500);
  hist7a->Draw();

  TCanvas *c8 = new TCanvas("c8", "c8", 1000, 500);
  hist8->Draw();
  TCanvas *c8a = new TCanvas("c8a", "c8a", 1000, 500);
  hist8a->Draw();

  TCanvas *c9 = new TCanvas("c9", "c9", 1000, 500);
  hist9->Draw();
  TCanvas *c9a = new TCanvas("c9a", "c9a", 1000, 500);
  hist9a->Draw();
*/
  c0->Print("diff2000gev.pdf");
  c0a->Print("per2000gev.pdf");
  c1->Print("diff4000gev.pdf");
  c1a->Print("per4000gev.pdf");
  c2->Print("diff5000gev.pdf");
  c2a->Print("per5000gev.pdf");
  c3->Print("diff7000gev.pdf");
  c3a->Print("per7000gev.pdf");
  c4->Print("diff8000gev.pdf");
  c4a->Print("per8000gev.pdf");
  c5->Print("diff9000gev.pdf");
  c5a->Print("per9000gev.pdf");
/*
  c6->Print("diff1000gev.pdf");
  c6a->Print("per1000gev.pdf");
  c7->Print("diff3000gev.pdf");
  c7a->Print("per3000gev.pdf");
  c8->Print("diff6000gev.pdf");
  c8a->Print("per6000gev.pdf");
  c9->Print("diff10000gev.pdf");
  c9a->Print("per10000gev.pdf");
*/
}

