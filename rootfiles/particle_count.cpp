#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <iostream>

int main() {
  // Open the first ROOT file for reading
  TFile* file1 = TFile::Open("e-10000gev", "READ");
  if (!file1 || file1->IsZombie()) {
    std::cout << "Failed to open elecs10000.root." << std::endl;
    return 1;
  }

  // Open the second ROOT file for reading
  TFile* file2 = TFile::Open("e+10000gev", "READ");
  if (!file2 || file2->IsZombie()) {
    std::cout << "Failed to open posits1000.root." << std::endl;
    file1->Close();
    return 1;
  }

  // Access the TTree from the first ROOT file
  TTree* tree1 = dynamic_cast<TTree*>(file1->Get("Hits"));
  if (!tree1) {
    std::cout << "Failed to retrieve the TTree from elecs1000.root." << std::endl;
    file1->Close();
    file2->Close();
    return 1;
  }

  // Access the TTree from the second ROOT file
  TTree* tree2 = dynamic_cast<TTree*>(file2->Get("Hits"));
  if (!tree2) {
    std::cout << "Failed to retrieve the TTree from posits1000.root." << std::endl;
    file1->Close();
    file2->Close();
    return 1;
  }

  // Create histograms for particle counting
  TH1D* hist1 = new TH1D("hist1", "Electrons", 500, 0, 10000);
  TH1D* hist2 = new TH1D("hist2", "Positrons", 500, 0, 10000);

  // Fill the histograms with the Z values from the first TTree
  tree1->Draw("Z>>hist1", "", "goff");

  // Fill the histograms with the Z values from the second TTree
  tree2->Draw("Z>>hist2", "", "goff");

  // Create a new ROOT file for writing
  TFile* outputFile = TFile::Open("output.root", "RECREATE");
  if (!outputFile || outputFile->IsZombie()) {
    std::cout << "Failed to create the output.root file." << std::endl;
    file1->Close();
    file2->Close();
    return 1;
  }

  // Create a new TTree to store the results
  TTree* outputTree = new TTree("result_tree", "Difference in Particle Counts");
  Double_t zValue;
  Double_t difference;

  // Create branches in the output TTree
  outputTree->Branch("z", &zValue, "z/D");
  outputTree->Branch("difference", &difference, "difference/I");

  // Loop over each bin of the histograms
  for (int bin = 1; bin <= hist1->GetNbinsX(); ++bin) {
    // Get the counts for each particle type
    int count1 = hist1->GetBinContent(bin);
    int count2 = hist2->GetBinContent(bin);

    // Calculate the difference in counts for the current z value
    difference = static_cast<Double_t>(count1 - count2)/ static_cast<Double_t>(count1);
    zValue = hist1->GetXaxis()->GetBinCenter(bin);

    // Fill the output TTree with the current z value and the difference
    outputTree->Fill();
  }

  // Write the output TTree to the output ROOT file
  outputTree->Write();

  // Close the ROOT files
  file1->Close();
  file2->Close();

  // Close the output ROOT file
  outputFile->Close();

  std::cout << "Output written to output.root." << std::endl;

  return 0;
}

