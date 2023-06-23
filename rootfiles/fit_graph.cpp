#include <TF1.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TTree.h>
#include <TH2D.h>

int main() {
  // Open the output ROOT file
  TFile* outputFile = TFile::Open("difference10kgev", "READ");
  if (!outputFile || outputFile->IsZombie()) {
    std::cout << "Failed to open the output.root file." << std::endl;
    return 1;
  }

  // Access the result TTree from the output ROOT file
  TTree* resultTree = dynamic_cast<TTree*>(outputFile->Get("result_tree"));
  if (!resultTree) {
    std::cout << "Failed to retrieve the result_tree from the output.root file." << std::endl;
    outputFile->Close();
    return 1;
  }

  // Variables to store data from the TTree
  Double_t zValue;
  Int_t difference;

  // Set up branches for reading from the result TTree
  resultTree->SetBranchAddress("z", &zValue);
  resultTree->SetBranchAddress("difference", &difference);

  // Create a 2D histogram to visualize the scatterplot
  TH2D* scatterplot = new TH2D("scatterplot", "Difference in Particle Counts", 100, 0, 10000, 350000, 0, 350000);

  // Fill the scatterplot histogram with data from the TTree
  Long64_t numEntries = resultTree->GetEntries();
  for (Long64_t i = 0; i < numEntries; ++i) {
    resultTree->GetEntry(i);
    scatterplot->Fill(zValue, difference);
  }

  // Create a canvas for drawing the scatterplot and the fit
  TCanvas* canvas = new TCanvas("canvas", "Scatterplot and Fit", 800, 600);
  scatterplot->Draw("*");

  // Fit a Gaussian function to the scatterplot with initial parameter estimates
  TF1* gaussianFit = new TF1("gaussianFit", "gaus");
  gaussianFit->SetParameters(350000, 4000, 10000); // Provide initial parameter estimates
  scatterplot->Fit(gaussianFit, "Q");

  // Draw the fitted function on top of the scatterplot
  gaussianFit->SetLineColor(kRed);
  gaussianFit->Draw("same");

  // Save the canvas as a PNG file
  canvas->SaveAs("scatterplot_with_gaussian_fit.png");

  // Close the output ROOT file
  outputFile->Close();

  std::cout << "Scatterplot with Gaussian fit saved as scatterplot_with_gaussian_fit.png." << std::endl;

  return 0;
}

