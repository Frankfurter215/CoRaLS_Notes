#include <TFile.h>
#include <TTree.h>
#include <iostream>

const int kMaxStringLength = 100;

int main() {
  // Open the ROOT file for reading
  TFile* file = TFile::Open("data.root", "READ");

  if (!file || file->IsZombie()) {
    std::cout << "Failed to open the ROOT file." << std::endl;
    return 1;
  }

  // Access the TTree from the ROOT file
  TTree* tree = dynamic_cast<TTree*>(file->Get("Hits"));

  if (!tree) {
    std::cout << "Failed to retrieve the TTree from the ROOT file." << std::endl;
    file->Close();
    return 1;
  }

  // Variables to store data from the TTree
  char str[kMaxStringLength];
  Double_t num;

  // Set up branches for reading
  tree->SetBranchAddress("partNames", str);
  tree->SetBranchAddress("Z", &num);

  // Create a new ROOT file for writing
  TFile* outputFile = TFile::Open("positrons.root", "RECREATE");

  // Create a new TTree to store the parsed data
  TTree* outputTree = new TTree("parsed_tree", "Parsed Data Tree");

  // Create the branches in the output TTree
  char parsedStr[kMaxStringLength];
  double_t parsednum;
  outputTree->Branch("string", str, "string/C");
  outputTree->Branch("number", &parsednum, "number/I");

  // Parse the ROOT file and fill the output TTree with the "here" and "there" strings and associated integers
  int numEntries = tree->GetEntries();
  for (int i = 0; i < numEntries; ++i) {
    tree->GetEntry(i);
    if (strcmp(str, "e+") == 0) {
      strncpy(parsedStr, str, kMaxStringLength);
      parsednum = num;
      outputTree->Fill();
    }
  }

  // Write the output TTree to the output ROOT file
  outputTree->Write();

  // Close the output ROOT file
  outputFile->Close();

  // Close the input ROOT file
  file->Close();

  std::cout << "Parsing of ROOT file complete. Output written to output.root." << std::endl;

  return 0;
}

